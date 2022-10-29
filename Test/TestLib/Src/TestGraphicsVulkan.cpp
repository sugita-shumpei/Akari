#include <TestLib/TestGraphicsVulkan.h>
#include <range/v3/algorithm.hpp>
#include <range/v3/iterator/insert_iterators.hpp>
TestLib::TestGraphicsVulkanInstance::TestGraphicsVulkanInstance() noexcept : m_VkRaiiContext{new vk::raii::Context()}
{
	/*TODO */
	m_InstanceExtensionProperties = m_VkRaiiContext->enumerateInstanceExtensionProperties();
	m_InstanceLayerProperties = m_VkRaiiContext->enumerateInstanceLayerProperties();
	m_InstanceApiVersion = m_VkRaiiContext->enumerateInstanceVersion();
}

auto TestLib::TestGraphicsVulkanInstance::GetHandle() -> TestGraphicsVulkanInstance &
{
	// TODO: return ステートメントをここに挿入します
	static TestLib::TestGraphicsVulkanInstance instance;
	return instance;
}

TestLib::TestGraphicsVulkanInstance::~TestGraphicsVulkanInstance() noexcept
{
	m_VkRaiiContext.reset();
}

bool TestLib::TestGraphicsVulkanInstance::Init()
{
	if (m_IsInitialized)
	{
		return true;
	}
	auto applicationInfo = vk::ApplicationInfo()
							   .setApiVersion(m_InstanceApiVersion)
							   .setPApplicationName(m_ApplicationName.data())
							   .setApplicationVersion(m_ApplicationVersion)
							   .setPEngineName(m_EngineName.data())
							   .setEngineVersion(m_EngineVersion);

	auto instancePEnabledExtensionNames = std::vector<const char *>();
	{
		instancePEnabledExtensionNames.reserve(m_InstanceEnabledExtensionNames.size());
		ranges::transform(m_InstanceEnabledExtensionNames, ranges::back_inserter(instancePEnabledExtensionNames), [](const auto &extension_name)
						  { return extension_name.data(); });
	}
	auto instancePEnabledLayerNames = std::vector<const char *>();
	{
		instancePEnabledLayerNames.reserve(m_InstanceEnabledExtensionNames.size());
		ranges::transform(m_InstanceEnabledLayerNames, ranges::back_inserter(instancePEnabledLayerNames), [](const auto &layer_name)
						  { return layer_name.data(); });
	}
	auto instanceCreateInfo = vk::InstanceCreateInfo()
								  .setPApplicationInfo(&applicationInfo)
								  .setPEnabledExtensionNames(instancePEnabledExtensionNames)
								  .setPEnabledLayerNames(instancePEnabledLayerNames);

	if (m_IsEnabledEmulation)
	{
		instanceCreateInfo.flags |= vk::InstanceCreateFlagBits::eEnumeratePortabilityKHR;
	}

	auto debugUtilsMessengerCreateInfo = vk::DebugUtilsMessengerCreateInfoEXT()
											 .setMessageSeverity(m_DebugUtilsMessageSeverity)
											 .setMessageType(m_DebugUtilsMessageType)
											 .setPfnUserCallback(m_DebugUtilsMessengerCallback)
											 .setPUserData(m_DebugUtilsPUserData);

	if (m_IsEnabledDebug)
	{
		instanceCreateInfo.setPNext(&debugUtilsMessengerCreateInfo);
	}
	auto vkInstance = VkInstance(nullptr);
	{
		auto res = m_VkRaiiContext->getDispatcher()->vkCreateInstance(
			reinterpret_cast<const VkInstanceCreateInfo *>(&instanceCreateInfo),
			nullptr,
			&vkInstance);
		if (res != VK_SUCCESS)
		{
			return false;
		}
	}

	m_VkRaiiInstance = std::make_unique<vk::raii::Instance>(
		*m_VkRaiiContext.get(), vkInstance, nullptr);

	if (m_IsEnabledDebug)
	{
		auto vkDebugUtilsMessenger = static_cast<VkDebugUtilsMessengerEXT>(nullptr);
		auto res = m_VkRaiiInstance->getDispatcher()->vkCreateDebugUtilsMessengerEXT(
			vkInstance, reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT *>(&debugUtilsMessengerCreateInfo), nullptr, &vkDebugUtilsMessenger);
		if (res != VK_SUCCESS)
		{
			m_VkRaiiInstance.reset();
			return false;
		}
		m_VkRaiiDebugUtilsMessenger = std::make_unique<vk::raii::DebugUtilsMessengerEXT>(
			*m_VkRaiiInstance.get(), vkDebugUtilsMessenger, nullptr);
	}

	{
		auto vkPhysicalDeviceCount = static_cast<uint32_t>(0);
		auto vkPhysicalDevices = std::vector<VkPhysicalDevice>();
		{
			auto res = m_VkRaiiInstance->getDispatcher()->vkEnumeratePhysicalDevices(m_VkRaiiInstance->operator*(), &vkPhysicalDeviceCount, nullptr);
			if (res != VK_SUCCESS)
			{
				m_VkRaiiDebugUtilsMessenger.reset();
				m_VkRaiiInstance.reset();
				return false;
			}
		}
		vkPhysicalDevices.resize(vkPhysicalDeviceCount);
		{
			auto res = m_VkRaiiInstance->getDispatcher()->vkEnumeratePhysicalDevices(m_VkRaiiInstance->operator*(), &vkPhysicalDeviceCount, vkPhysicalDevices.data());
			if (res != VK_SUCCESS)
			{
				m_VkRaiiDebugUtilsMessenger.reset();
				m_VkRaiiInstance.reset();
				return false;
			}
		}
		m_VkRaiiPhysicalDevices = std::make_unique<vk::raii::PhysicalDevices>(*m_VkRaiiInstance.get());
		m_VkRaiiPhysicalDevices->reserve(vkPhysicalDeviceCount);
		for (auto &physicalDevice : vkPhysicalDevices)
		{
			m_VkRaiiPhysicalDevices->push_back(
				vk::raii::PhysicalDevice(*m_VkRaiiInstance.get(), physicalDevice));
		}
	}

	m_IsInitialized = true;
	return true;
}

void TestLib::TestGraphicsVulkanInstance::Free()
{
	if (!m_IsInitialized)
	{
		return;
	}
	m_VkRaiiPhysicalDevices.reset();
	m_VkRaiiDebugUtilsMessenger.reset();
	m_VkRaiiInstance.reset();
	m_IsInitialized = false;
}

auto TestLib::TestGraphicsVulkanInstance::CreateDevice(unsigned int physicalDeviceIdx) const noexcept -> TestGraphicsVulkanDevice *
{
	return TestLib::TestGraphicsVulkanDevice::New(physicalDeviceIdx);
}

bool TestLib::TestGraphicsVulkanInstance::SetApplicationInfo(const std::string &application_name, uint32_t application_version) noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	m_ApplicationName = application_name;
	m_ApplicationVersion = application_version;
	return true;
}

bool TestLib::TestGraphicsVulkanInstance::SetEngineInfo(const std::string &engine_name, uint32_t engine_version) noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	m_EngineName = engine_name;
	m_EngineVersion = engine_version;
	return true;
}

bool TestLib::TestGraphicsVulkanInstance::IsEnabledExtension(const std::string &extension_name) const noexcept
{
	return m_InstanceEnabledExtensionNames.count(extension_name) > 0;
}

bool TestLib::TestGraphicsVulkanInstance::IsEnabledLayer(const std::string &layer_name) const noexcept
{
	return m_InstanceEnabledLayerNames.count(layer_name) > 0;
}

bool TestLib::TestGraphicsVulkanInstance::EnableExtension(const std::string &extension_name) noexcept
{
	if (IsInitialized())
	{
		return false;
	}
	if (!IsSupportedExtension(extension_name))
	{
		return false;
	}
	m_InstanceEnabledExtensionNames.insert(extension_name);
	return true;
}

bool TestLib::TestGraphicsVulkanInstance::EnableExtensions(const std::vector<std::string> &extension_names) noexcept
{
	if (IsInitialized())
	{
		return false;
	}
	if (!IsSupportedExtensions(extension_names))
	{
		return false;
	}
	for (auto &extension_name : extension_names)
	{
		m_InstanceEnabledExtensionNames.insert(extension_name);
	}
	return true;
}

bool TestLib::TestGraphicsVulkanInstance::EnableLayer(const std::string &layer_name) noexcept
{
	if (IsInitialized())
	{
		return false;
	}
	if (!IsSupportedLayer(layer_name))
	{
		return false;
	}
	m_InstanceEnabledLayerNames.insert(layer_name);
	return true;
}

bool TestLib::TestGraphicsVulkanInstance::EnableLayers(const std::vector<std::string> &layernames) noexcept
{
	if (IsInitialized())
	{
		return false;
	}
	if (!IsSupportedLayers(layernames))
	{
		return false;
	}
	for (auto &layer_name : layernames)
	{
		m_InstanceEnabledLayerNames.insert(layer_name);
	}
	return true;
}

bool TestLib::TestGraphicsVulkanInstance::EnableDebug(vk::DebugUtilsMessageSeverityFlagsEXT messageSeverity, vk::DebugUtilsMessageTypeFlagsEXT messageType, PFN_vkDebugUtilsMessengerCallbackEXT messageCallback, void *pUserData) noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledDebug)
	{
		return true;
	}

	if (!EnableExtension(VK_EXT_DEBUG_UTILS_EXTENSION_NAME))
	{
		return false;
	}
	m_IsEnabledDebug = true;
	m_DebugUtilsMessageSeverity = messageSeverity;
	m_DebugUtilsMessageType = messageType;
	m_DebugUtilsMessengerCallback = messageCallback;
	m_DebugUtilsPUserData = pUserData;
	return true;
}

bool TestLib::TestGraphicsVulkanInstance::EnableSurface() noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledSurface)
	{
		return true;
	}
	auto extension_names_for_surfaces = std::vector<std::string>{
		VK_KHR_SURFACE_EXTENSION_NAME,
#ifdef WIN32
		"VK_KHR_win32_surface",
#endif
#ifdef __APPLE__
		"VK_EXT_metal_surface",
#endif
#ifdef __linux__
		"VK_KHR_xlib_surface",
		"VK_KHR_xcb_surface"
#endif
	};
	m_IsEnabledSurface = EnableExtensions(extension_names_for_surfaces);
	return m_IsEnabledSurface;
}

bool TestLib::TestGraphicsVulkanInstance::EnableEmulation() noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledEmulation)
	{
		return true;
	}
	m_IsEnabledEmulation = EnableExtension(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
	return m_IsEnabledEmulation;
}

auto TestLib::TestGraphicsVulkanInstance::GetVkRaiiContext() const noexcept -> VkRaiiContext_t *
{
	return m_VkRaiiContext.get();
}

auto TestLib::TestGraphicsVulkanInstance::GetVkRaiiInstance() const noexcept -> VkRaiiInstance_t *
{
	return m_VkRaiiInstance.get();
}

auto TestLib::TestGraphicsVulkanInstance::GetVkRaiiDebugUtilsMessenger() const noexcept -> VkDebugUtilsMessenger_t *
{
	return m_VkRaiiDebugUtilsMessenger.get();
}

auto TestLib::TestGraphicsVulkanInstance::GetVkRaiiPhysicalDevices() const noexcept -> VkPhysicalDevices_t *
{
	return m_VkRaiiPhysicalDevices.get();
}

auto TestLib::TestGraphicsVulkanInstance::GetVkRaiiPhysicalDevice(uint32_t idx) const noexcept -> VkPhysicalDevice_t *
{
	if (!m_VkRaiiPhysicalDevices)
	{
		return nullptr;
	}
	if (m_VkRaiiPhysicalDevices->size() <= idx)
	{
		return nullptr;
	}
	return &(*m_VkRaiiPhysicalDevices)[idx];
}

auto TestLib::TestGraphicsVulkanInstance::GetVkInstance() const noexcept -> VkInstance
{
	return m_VkRaiiInstance ? static_cast<VkInstance>(m_VkRaiiInstance->operator*()) : VkInstance(nullptr);
}

auto TestLib::TestGraphicsVulkanInstance::GetVkDebugUtilsMessenger() const noexcept -> VkDebugUtilsMessengerEXT
{
	return m_VkRaiiDebugUtilsMessenger ? static_cast<VkDebugUtilsMessengerEXT>(m_VkRaiiDebugUtilsMessenger->operator*()) : VkDebugUtilsMessengerEXT(nullptr);
}

auto TestLib::TestGraphicsVulkanInstance::GetVkPhysicalDevice(uint32_t idx) const noexcept -> VkPhysicalDevice
{
	auto vkRaiiPhysicalDevice = GetVkRaiiPhysicalDevice(idx);
	if (!vkRaiiPhysicalDevice)
	{
		return nullptr;
	}
	return vkRaiiPhysicalDevice->operator*();
}

bool TestLib::TestGraphicsVulkanInstance::IsSupportedExtensions(const std::vector<std::string> &extension_names) const noexcept
{
	return ranges::all_of(extension_names, [this](const auto &extension_name)
						  { return IsSupportedExtension(extension_name); });
}

bool TestLib::TestGraphicsVulkanInstance::IsSupportedExtension(const std::string &extension_name) const noexcept
{
	return ranges::find_if(m_InstanceExtensionProperties, [&extension_name](const auto &extension_prop)
						   { return extension_name == std::string(extension_prop.extensionName.data()); }) != std::end(m_InstanceExtensionProperties);
}

bool TestLib::TestGraphicsVulkanInstance::IsSupportedLayers(const std::vector<std::string> &layer_names) const noexcept
{
	return ranges::all_of(layer_names, [this](const auto &layer_name)
						  { return IsSupportedLayer(layer_name); });
}

bool TestLib::TestGraphicsVulkanInstance::IsSupportedLayer(const std::string &layer_name) const noexcept
{
	return ranges::find_if(m_InstanceLayerProperties, [&layer_name](const auto &layer_prop)
						   { return layer_name == std::string(layer_prop.layerName.data()); }) != std::end(m_InstanceLayerProperties);
}

auto TestLib::TestGraphicsVulkan::Instance() noexcept -> TestGraphicsVulkanInstance &
{
	// TODO: return ステートメントをここに挿入します
	return TestLib::TestGraphicsVulkanInstance::GetHandle();
}

TestLib::TestGraphicsVulkanDevice::TestGraphicsVulkanDevice(unsigned int physicalDeviceIdx) noexcept
	: m_PhysicalDeviceIndex{physicalDeviceIdx}
{
	m_VkRaiiPhysicalDevice = TestGraphicsVulkanInstance::GetHandle().GetVkRaiiPhysicalDevice(physicalDeviceIdx);
	m_DeviceExtensionProperties = m_VkRaiiPhysicalDevice->enumerateDeviceExtensionProperties();
	m_DeviceProperties = m_VkRaiiPhysicalDevice->getProperties();
	m_DeviceQueueFamilyProperties = m_VkRaiiPhysicalDevice->getQueueFamilyProperties();
	auto indices = FindQueueFamilyIndices(m_DeviceQueueFamilyProperties, vk::QueueFlagBits::eGraphics | vk::QueueFlagBits::eCompute | vk::QueueFlagBits::eTransfer);
	m_GeneralQueueIndex = indices.front();
	m_DeviceEnabledFeatures[vk::PhysicalDeviceFeatures2::structureType] = std::unique_ptr<FeaturesWrapper>(
		new TTestGraphicsVulkanFeaturesWrapper<vk::PhysicalDeviceFeatures2>());
	m_DeviceSupportedFeatures[vk::PhysicalDeviceFeatures2::structureType] = std::unique_ptr<FeaturesWrapper>(
		new TTestGraphicsVulkanFeaturesWrapper<vk::PhysicalDeviceFeatures2>());
}

auto TestLib::TestGraphicsVulkanDevice::New(unsigned int physicalDeviceIdx) noexcept -> TestGraphicsVulkanDevice *
{
	if (!TestGraphicsVulkanInstance::GetHandle().IsInitialized())
	{
		return nullptr;
	}
	if (TestGraphicsVulkanInstance::GetHandle().GetVkRaiiPhysicalDevices()->size() <= physicalDeviceIdx)
	{
		return nullptr;
	}
	return new TestGraphicsVulkanDevice(physicalDeviceIdx);
}

TestLib::TestGraphicsVulkanDevice::~TestGraphicsVulkanDevice() noexcept
{
}

bool TestLib::TestGraphicsVulkanDevice::Init()
{
	if (m_IsInitialized)
	{
		return true;
	}
	auto devicePEnabledExtensionNames = std::vector<const char *>();
	for (auto &extensionName : m_DeviceEnabledExtensionNames)
	{
		devicePEnabledExtensionNames.push_back(extensionName.data());
	}

	auto deviceQueueCreateInfos = std::vector<vk::DeviceQueueCreateInfo>();
	deviceQueueCreateInfos.push_back(
		vk::DeviceQueueCreateInfo().setQueueCount(1).setQueueFamilyIndex(m_GeneralQueueIndex));
	if (m_IsEnabledAsyncComputeQueue)
	{
		deviceQueueCreateInfos.push_back(
			vk::DeviceQueueCreateInfo().setQueueCount(1).setQueueFamilyIndex(m_AsyncComputeQueueIndex));
	}
	if (m_IsEnabledAsyncTransferQueue)
	{
		deviceQueueCreateInfos.push_back(
			vk::DeviceQueueCreateInfo().setQueueCount(1).setQueueFamilyIndex(m_AsyncTransferQueueIndex));
	}
	auto deviceQueuePriorities = std::vector<float>(deviceQueueCreateInfos.size(), 1.0f);
	for (auto i = 0; i < deviceQueueCreateInfos.size(); ++i)
	{
		deviceQueueCreateInfos[i].setPQueuePriorities(&deviceQueuePriorities[i]);
	}

	auto features2Wrapper = std::unique_ptr<FeaturesWrapper>((FeaturesWrapper *)m_DeviceEnabledFeatures.at(vk::PhysicalDeviceFeatures2::structureType)->Clone());
	auto featuresWrappers = std::vector<std::unique_ptr<FeaturesWrapper>>();

	for (auto &[structureType, featuresWrapper] : m_DeviceEnabledFeatures)
	{
		if (structureType == vk::PhysicalDeviceFeatures2::structureType)
		{
			continue;
		}
		featuresWrappers.push_back(std::unique_ptr<FeaturesWrapper>((FeaturesWrapper *)featuresWrapper->Clone()));
	}
	if (!featuresWrappers.empty())
	{
		FeaturesWrapper *pHead = featuresWrappers.front().get();
		features2Wrapper->Link(pHead);
		pHead = nullptr;
		for (auto &featuresWrapper : featuresWrappers)
		{
			if (pHead)
			{
				pHead->Link(featuresWrapper.get());
			}
			pHead = featuresWrapper.get();
		}
	}

	auto deviceCreateInfo = vk::DeviceCreateInfo()
								.setPEnabledExtensionNames(devicePEnabledExtensionNames)
								.setQueueCreateInfos(deviceQueueCreateInfos)
								.setPNext(features2Wrapper->GetPData());

	if (m_VkRaiiPhysicalDevice->getDispatcher()->vkCreateDevice)
	{
		auto device = VkDevice(nullptr);
		auto res = m_VkRaiiPhysicalDevice->getDispatcher()->vkCreateDevice(
			GetVkPhysicalDevice(),
			reinterpret_cast<const VkDeviceCreateInfo *>(&deviceCreateInfo),
			nullptr,
			&device);
		if (res != VK_SUCCESS)
		{
			return false;
		}
		m_VkRaiiDevice = std::make_unique<VkRaiiDevice_t>(*m_VkRaiiPhysicalDevice, device, nullptr);
	}
	{
		m_VkRaiiGeneralQueue = std::make_unique<VkRaiiQueue_t>(*m_VkRaiiDevice, m_GeneralQueueIndex, 0);
	}
	if (m_IsEnabledAsyncComputeQueue)
	{
		m_VkRaiiAsyncComputeQueue = std::make_unique<VkRaiiQueue_t>(*m_VkRaiiDevice, m_AsyncComputeQueueIndex, 0);
	}
	if (m_IsEnabledAsyncTransferQueue)
	{
		m_VkRaiiAsyncTransferQueue = std::make_unique<VkRaiiQueue_t>(*m_VkRaiiDevice, m_IsEnabledAsyncTransferQueue, 0);
	}

	m_IsInitialized = true;
	return m_IsInitialized;
}
void TestLib::TestGraphicsVulkanDevice::Free()
{
	if (!m_IsInitialized)
	{
		return;
	}
	m_VkRaiiGeneralQueue.reset();
	m_VkRaiiAsyncComputeQueue.reset();
	m_VkRaiiAsyncTransferQueue.reset();
	m_VkRaiiDevice.reset();
	m_IsInitialized = false;
}
bool TestLib::TestGraphicsVulkanDevice::IsInitialized() const noexcept
{
	return m_IsInitialized;
}

auto TestLib::TestGraphicsVulkanDevice::GetVkRaiiContext() noexcept -> VkRaiiContext_t *
{
	return TestLib::TestGraphicsVulkanInstance::GetHandle().GetVkRaiiContext();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkRaiiInstance() noexcept -> VkRaiiInstance_t *
{
	return TestLib::TestGraphicsVulkanInstance::GetHandle().GetVkRaiiInstance();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkRaiiPhysicalDevice() const noexcept -> VkRaiiPhysicalDevice_t *
{
	return m_VkRaiiPhysicalDevice;
}
auto TestLib::TestGraphicsVulkanDevice::GetVkRaiiDevice() const noexcept -> VkRaiiDevice_t *
{
	return m_VkRaiiDevice.get();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkRaiiGeneralQueue() const noexcept -> VkRaiiQueue_t *
{
	return m_VkRaiiGeneralQueue.get();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkRaiiAsyncTransferQueue() const noexcept -> VkRaiiQueue_t *
{
	return m_VkRaiiAsyncTransferQueue.get();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkRaiiAsyncComputeQueue() const noexcept -> VkRaiiQueue_t *
{
	return m_VkRaiiAsyncComputeQueue.get();
}

auto TestLib::TestGraphicsVulkanDevice::GetVkInstance() noexcept -> VkInstance
{
	return TestLib::TestGraphicsVulkanInstance::GetHandle().GetVkInstance();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkPhysicalDevice() const noexcept -> VkPhysicalDevice
{
	if (!m_VkRaiiPhysicalDevice)
	{
		return nullptr;
	}
	return m_VkRaiiPhysicalDevice->operator*();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkDevice() const noexcept -> VkDevice
{
	if (!m_VkRaiiDevice)
	{
		return nullptr;
	}
	return m_VkRaiiDevice->operator*();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkGeneralQueue() const noexcept -> VkQueue
{
	if (!m_VkRaiiGeneralQueue)
	{
		return nullptr;
	}
	return m_VkRaiiGeneralQueue->operator*();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkAsyncTransferQueue() const noexcept -> VkQueue
{
	if (!m_VkRaiiAsyncTransferQueue)
	{
		return nullptr;
	}
	return m_VkRaiiAsyncTransferQueue->operator*();
}
auto TestLib::TestGraphicsVulkanDevice::GetVkAsyncComputeQueue() const noexcept -> VkQueue
{
	if (!m_VkRaiiAsyncComputeQueue)
	{
		return nullptr;
	}
	return m_VkRaiiAsyncComputeQueue->operator*();
}

bool TestLib::TestGraphicsVulkanDevice::IsSupportedExtension(const std::string &extension_name) const noexcept
{
	return ranges::find_if(m_DeviceExtensionProperties, [&extension_name](const auto &extension_prop)
						   { return extension_name == std::string(extension_prop.extensionName.data()); }) != std::end(m_DeviceExtensionProperties);
}
bool TestLib::TestGraphicsVulkanDevice::IsSupportedFeaturesWrapper(const FeaturesWrapper *featuresWrapper) const noexcept
{
	if (!featuresWrapper)
	{
		return false;
	}
	if (m_DeviceSupportedFeatures.count(featuresWrapper->GetSType()) == 0)
	{
		return false;
	}
	auto supportedFeatures64 = m_DeviceSupportedFeatures.at(featuresWrapper->GetSType())->ConvertToUInt64();
	auto requestedFeatures64 = featuresWrapper->ConvertToUInt64();
	return (supportedFeatures64 & requestedFeatures64) == requestedFeatures64;
}
bool TestLib::TestGraphicsVulkanDevice::IsSupportedFeaturesWrapperList(const std::vector<const FeaturesWrapper *> &featuresWrapperList) const noexcept
{
	for (auto &featuresWrapper : featuresWrapperList)
	{
		if (!IsSupportedFeaturesWrapper(featuresWrapper))
		{
			return false;
		}
	}
	return true;
}

bool TestLib::TestGraphicsVulkanDevice::EnableGeometryShader() noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledGeometryShader)
	{
		return true;
	}
	m_IsEnabledGeometryShader = EnableFeatures(vk::PhysicalDeviceFeatures2().setFeatures(vk::PhysicalDeviceFeatures().setGeometryShader(VK_TRUE)));
	return m_IsEnabledGeometryShader;
}
bool TestLib::TestGraphicsVulkanDevice::EnableTesselationShader() noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledTesselationShader)
	{
		return true;
	}
	m_IsEnabledTesselationShader = EnableFeatures(vk::PhysicalDeviceFeatures2().setFeatures(vk::PhysicalDeviceFeatures().setTessellationShader(VK_TRUE)));
	return m_IsEnabledTesselationShader;
}
bool TestLib::TestGraphicsVulkanDevice::EnableBufferDeviceAddress(const vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR &optionalBufferDeviceAddress) noexcept
{
	if (m_DeviceProperties.apiVersion >= VK_MAKE_API_VERSION(0, 1, 2, 0))
	{
		m_IsEnabledBufferDeviceAddress = EnableFeatures(vk::PhysicalDeviceVulkan12Features()
															.setBufferDeviceAddress(VK_TRUE),
														vk::PhysicalDeviceVulkan12Features()
															.setBufferDeviceAddressCaptureReplay(optionalBufferDeviceAddress.bufferDeviceAddressCaptureReplay)
															.setBufferDeviceAddressMultiDevice(optionalBufferDeviceAddress.bufferDeviceAddressMultiDevice));
	}
	else
	{
		m_IsEnabledBufferDeviceAddress = EnableExtension(
			VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME,
			vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR().setBufferDeviceAddress(VK_TRUE),
			optionalBufferDeviceAddress);
	}
	return m_IsEnabledBufferDeviceAddress;
}
bool TestLib::TestGraphicsVulkanDevice::EnableDescriptorIndexing(const vk::PhysicalDeviceDescriptorIndexingFeaturesEXT &optinalDescriptorIndexing) noexcept
{
	if (m_DeviceProperties.apiVersion >= VK_MAKE_API_VERSION(0, 1, 2, 0))
	{
		m_IsEnabledDescriptorIndexing = EnableFeatures(vk::PhysicalDeviceVulkan12Features()
														   .setDescriptorIndexing(VK_TRUE),
													   vk::PhysicalDeviceVulkan12Features()
														   .setDescriptorBindingPartiallyBound(optinalDescriptorIndexing.descriptorBindingPartiallyBound)
														   .setDescriptorBindingSampledImageUpdateAfterBind(optinalDescriptorIndexing.descriptorBindingSampledImageUpdateAfterBind)
														   .setDescriptorBindingStorageBufferUpdateAfterBind(optinalDescriptorIndexing.descriptorBindingStorageBufferUpdateAfterBind)
														   .setDescriptorBindingStorageImageUpdateAfterBind(optinalDescriptorIndexing.descriptorBindingStorageImageUpdateAfterBind)
														   .setDescriptorBindingStorageTexelBufferUpdateAfterBind(optinalDescriptorIndexing.descriptorBindingStorageTexelBufferUpdateAfterBind)
														   .setDescriptorBindingUniformBufferUpdateAfterBind(optinalDescriptorIndexing.descriptorBindingUniformBufferUpdateAfterBind)
														   .setDescriptorBindingUniformTexelBufferUpdateAfterBind(optinalDescriptorIndexing.descriptorBindingUniformTexelBufferUpdateAfterBind)
														   .setDescriptorBindingUpdateUnusedWhilePending(optinalDescriptorIndexing.descriptorBindingUpdateUnusedWhilePending)
														   .setDescriptorBindingVariableDescriptorCount(optinalDescriptorIndexing.descriptorBindingVariableDescriptorCount)
														   .setRuntimeDescriptorArray(optinalDescriptorIndexing.runtimeDescriptorArray));
	}
	else
	{
		m_IsEnabledDescriptorIndexing = EnableExtension(
			VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME,
			vk::PhysicalDeviceDescriptorIndexingFeaturesEXT(),
			optinalDescriptorIndexing);
	}
	return m_IsEnabledDescriptorIndexing;
}
bool TestLib::TestGraphicsVulkanDevice::EnableRaytracing(
	const vk::PhysicalDeviceRayTracingPipelineFeaturesKHR &optionalRayTracingFeatures,
	const vk::PhysicalDeviceAccelerationStructureFeaturesKHR &optionalAccelerationStructureFeatures) noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (!m_IsEnabledRayTracing)
	{
		if (m_DeviceProperties.apiVersion >= VK_MAKE_API_VERSION(0, 1, 2, 0))
		{
			RequestSupportedFeaturesWrapper<vk::PhysicalDeviceVulkan12Features>();
			auto requiredFeaturesVk12 = vk::PhysicalDeviceVulkan12Features()
											.setVulkanMemoryModel(VK_TRUE);

			if (!m_IsEnabledBufferDeviceAddress)
			{
				requiredFeaturesVk12.setBufferDeviceAddress(VK_TRUE);
			}
			if (!m_IsEnabledDescriptorIndexing)
			{
				requiredFeaturesVk12.setDescriptorIndexing(VK_TRUE);
			}
			if (!IsSupportedFeatures(requiredFeaturesVk12))
			{
				return false;
			}
		}
		else
		{
			{
				if (!IsSupportedExtension(VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME))
				{
					return false;
				}
				RequestSupportedFeaturesWrapper<vk::PhysicalDeviceVulkanMemoryModelFeaturesKHR>();
			}
			if (!m_IsEnabledBufferDeviceAddress)
			{
				if (!IsSupportedExtension(VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME))
				{
					return false;
				}
				RequestSupportedFeaturesWrapper<vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR>();
				if (!IsSupportedFeatures(vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR()
											 .setBufferDeviceAddress(VK_TRUE)))
				{
					return false;
				}
			}
			if (!m_IsEnabledDescriptorIndexing)
			{
				if (!IsSupportedExtension(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME))
				{
					return false;
				}
				RequestSupportedFeaturesWrapper<vk::PhysicalDeviceDescriptorIndexingFeaturesEXT>();
			}
		}

		if (!IsSupportedExtension(VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME))
		{
			return false;
		}
		if (!IsSupportedExtension(VK_KHR_RAY_QUERY_EXTENSION_NAME))
		{
			return false;
		}
		if (!IsSupportedExtension(VK_KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME))
		{
			return false;
		}
		if (!IsSupportedExtension(VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME))
		{
			return false;
		}
		if (!IsSupportedExtension(VK_KHR_PIPELINE_LIBRARY_EXTENSION_NAME))
		{
			return false;
		}

		RequestSupportedFeaturesWrapper<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>();
		RequestSupportedFeaturesWrapper<vk::PhysicalDeviceRayQueryFeaturesKHR>();
		RequestSupportedFeaturesWrapper<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>();

		if (!IsSupportedFeatures(vk::PhysicalDeviceRayTracingPipelineFeaturesKHR().setRayTracingPipeline(VK_TRUE)))
		{
			return false;
		}
		if (!IsSupportedFeatures(vk::PhysicalDeviceRayQueryFeaturesKHR().setRayQuery(VK_TRUE)))
		{
			return false;
		}
		if (!IsSupportedFeatures(vk::PhysicalDeviceAccelerationStructureFeaturesKHR().setAccelerationStructure(VK_TRUE)))
		{
			return false;
		}

		if (m_DeviceProperties.apiVersion >= VK_MAKE_API_VERSION(0, 1, 2, 0))
		{
			auto requiredFeaturesVk12 = vk::PhysicalDeviceVulkan12Features()
											.setVulkanMemoryModel(VK_TRUE);

			if (!m_IsEnabledBufferDeviceAddress)
			{
				requiredFeaturesVk12.setBufferDeviceAddress(VK_TRUE);
			}
			if (!m_IsEnabledDescriptorIndexing)
			{
				requiredFeaturesVk12.setDescriptorIndexing(VK_TRUE);
			}

			auto vulkan12Features64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(requiredFeaturesVk12);
			if (m_DeviceEnabledFeatures.count(vk::PhysicalDeviceVulkan12Features::structureType) > 0)
			{
				vulkan12Features64 |= m_DeviceEnabledFeatures.at(vk::PhysicalDeviceVulkan12Features::structureType)->ConvertToUInt64();
			}
			m_DeviceEnabledFeatures[vk::PhysicalDeviceVulkan12Features::structureType] = std::unique_ptr<FeaturesWrapper>(
				new TTestGraphicsVulkanFeaturesWrapper(TestGraphicsVulkanUtility::ConvertUInt642Features<vk::PhysicalDeviceVulkan12Features>(vulkan12Features64)));
		}
		else
		{
			{
				m_DeviceEnabledExtensionNames.insert(VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME);
				auto vulkanMemoryModelFeatures64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(vk::PhysicalDeviceVulkanMemoryModelFeaturesKHR().setVulkanMemoryModel(VK_TRUE));
				if (m_DeviceEnabledFeatures.count(vk::PhysicalDeviceVulkanMemoryModelFeaturesKHR::structureType) > 0)
				{
					vulkanMemoryModelFeatures64 |= m_DeviceEnabledFeatures.at(vk::PhysicalDeviceVulkanMemoryModelFeaturesKHR::structureType)->ConvertToUInt64();
				}
				m_DeviceEnabledFeatures[vk::PhysicalDeviceVulkanMemoryModelFeaturesKHR::structureType] = std::unique_ptr<FeaturesWrapper>(
					new TTestGraphicsVulkanFeaturesWrapper(TestGraphicsVulkanUtility::ConvertUInt642Features<vk::PhysicalDeviceVulkanMemoryModelFeaturesKHR>(vulkanMemoryModelFeatures64)));
			}
			if (!m_IsEnabledBufferDeviceAddress)
			{
				m_DeviceEnabledExtensionNames.insert(VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME);
				auto vulkanBufferDeviceAddress64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR().setBufferDeviceAddress(VK_TRUE));
				if (m_DeviceEnabledFeatures.count(vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR::structureType) > 0)
				{
					vulkanBufferDeviceAddress64 |= m_DeviceEnabledFeatures.at(vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR::structureType)->ConvertToUInt64();
				}
				m_DeviceEnabledFeatures[vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR::structureType] = std::unique_ptr<FeaturesWrapper>(
					new TTestGraphicsVulkanFeaturesWrapper(TestGraphicsVulkanUtility::ConvertUInt642Features<vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR>(vulkanBufferDeviceAddress64)));
			}
			if (!m_IsEnabledDescriptorIndexing)
			{
				m_DeviceEnabledExtensionNames.insert(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME);
			}
		}

		m_DeviceEnabledExtensionNames.insert(VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME);
		m_DeviceEnabledExtensionNames.insert(VK_KHR_RAY_QUERY_EXTENSION_NAME);
		m_DeviceEnabledExtensionNames.insert(VK_KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME);
		m_DeviceEnabledExtensionNames.insert(VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME);
		m_DeviceEnabledExtensionNames.insert(VK_KHR_PIPELINE_LIBRARY_EXTENSION_NAME);
		{
			{
				auto vulkanRayQuery64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(vk::PhysicalDeviceRayQueryFeaturesKHR().setRayQuery(VK_TRUE));
				if (m_DeviceEnabledFeatures.count(vk::PhysicalDeviceRayQueryFeaturesKHR::structureType) > 0)
				{
					vulkanRayQuery64 |= m_DeviceEnabledFeatures.at(vk::PhysicalDeviceRayQueryFeaturesKHR::structureType)->ConvertToUInt64();
				}
				m_DeviceEnabledFeatures[vk::PhysicalDeviceRayQueryFeaturesKHR::structureType] = std::unique_ptr<FeaturesWrapper>(
					new TTestGraphicsVulkanFeaturesWrapper(TestGraphicsVulkanUtility::ConvertUInt642Features<vk::PhysicalDeviceRayQueryFeaturesKHR>(vulkanRayQuery64)));
			}
		}
	}
	{
		{
			auto vulkanRayTracingPipeline64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(vk::PhysicalDeviceRayTracingPipelineFeaturesKHR().setRayTracingPipeline(VK_TRUE));
			vulkanRayTracingPipeline64 |= (TestGraphicsVulkanUtility::ConvertFeatures2UInt64(optionalRayTracingFeatures));
			if (m_DeviceEnabledFeatures.count(vk::PhysicalDeviceRayTracingPipelineFeaturesKHR::structureType) > 0)
			{
				vulkanRayTracingPipeline64 |= m_DeviceEnabledFeatures.at(vk::PhysicalDeviceRayTracingPipelineFeaturesKHR::structureType)->ConvertToUInt64();
			}
			vulkanRayTracingPipeline64 &= m_DeviceSupportedFeatures.at(vk::PhysicalDeviceRayTracingPipelineFeaturesKHR::structureType)->ConvertToUInt64();
			m_DeviceEnabledFeatures[vk::PhysicalDeviceRayTracingPipelineFeaturesKHR::structureType] = std::unique_ptr<FeaturesWrapper>(
				new TTestGraphicsVulkanFeaturesWrapper(TestGraphicsVulkanUtility::ConvertUInt642Features<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>(vulkanRayTracingPipeline64)));
		}
		{
			auto vulkanAccelerationStructure64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(vk::PhysicalDeviceAccelerationStructureFeaturesKHR().setAccelerationStructure(VK_TRUE));
			vulkanAccelerationStructure64 |= (TestGraphicsVulkanUtility::ConvertFeatures2UInt64(optionalAccelerationStructureFeatures));
			if (m_DeviceEnabledFeatures.count(vk::PhysicalDeviceAccelerationStructureFeaturesKHR::structureType) > 0)
			{
				vulkanAccelerationStructure64 |= m_DeviceEnabledFeatures.at(vk::PhysicalDeviceAccelerationStructureFeaturesKHR::structureType)->ConvertToUInt64();
			}
			vulkanAccelerationStructure64 &= m_DeviceSupportedFeatures.at(vk::PhysicalDeviceAccelerationStructureFeaturesKHR::structureType)->ConvertToUInt64();
			m_DeviceEnabledFeatures[vk::PhysicalDeviceAccelerationStructureFeaturesKHR::structureType] = std::unique_ptr<FeaturesWrapper>(
				new TTestGraphicsVulkanFeaturesWrapper(TestGraphicsVulkanUtility::ConvertUInt642Features<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>(vulkanAccelerationStructure64)));
		}
	}
	m_IsEnabledDescriptorIndexing = true;
	m_IsEnabledBufferDeviceAddress = true;
	m_IsEnabledRayTracing = true;
	return true;
}
bool TestLib::TestGraphicsVulkanDevice::EnableDynamicRendering() noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledDynamicRendering)
	{
		return true;
	}
	if (m_DeviceProperties.apiVersion >= VK_MAKE_API_VERSION(0, 1, 3, 0))
	{
		m_IsEnabledDynamicRendering = EnableFeatures(vk::PhysicalDeviceVulkan13Features().setDynamicRendering(VK_TRUE));
	}
	else
	{
		m_IsEnabledDynamicRendering = EnableExtension(VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME, vk::PhysicalDeviceDynamicRenderingFeaturesKHR().setDynamicRendering(VK_TRUE));
	}
	return m_IsEnabledDynamicRendering;
}
bool TestLib::TestGraphicsVulkanDevice::EnableSwapchain() noexcept
{

	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledSwapchain)
	{
		return true;
	}
	m_IsEnabledSwapchain = EnableExtension(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
	return m_IsEnabledSwapchain;
}
bool TestLib::TestGraphicsVulkanDevice::EnableDedicatedAllocation() noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledDedicatedAllocation)
	{
		return true;
	}
	if (m_DeviceProperties.apiVersion >= VK_MAKE_API_VERSION(0, 1, 1, 0))
	{
		m_IsEnabledDedicatedAllocation = true;
	}
	else
	{
		m_IsEnabledDedicatedAllocation = EnableExtension(VK_KHR_DEDICATED_ALLOCATION_EXTENSION_NAME);
	}
	return m_IsEnabledDedicatedAllocation;
}
bool TestLib::TestGraphicsVulkanDevice::EnableAsyncTransferQueue() noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledAsyncTransferQueue)
	{
		return true;
	}
	auto indices = FindQueueFamilyIndices(m_DeviceQueueFamilyProperties, vk::QueueFlagBits::eTransfer, vk::QueueFlagBits::eCompute | vk::QueueFlagBits::eGraphics);
	if (indices.empty())
	{
		return false;
	}
	m_IsEnabledAsyncTransferQueue = true;
	m_AsyncTransferQueueIndex = indices.front();
	return true;
}
bool TestLib::TestGraphicsVulkanDevice::EnableAsyncComputeQueue() noexcept
{
	if (m_IsInitialized)
	{
		return false;
	}
	if (m_IsEnabledAsyncComputeQueue)
	{
		return true;
	}
	auto indices = FindQueueFamilyIndices(m_DeviceQueueFamilyProperties, vk::QueueFlagBits::eCompute | vk::QueueFlagBits::eTransfer, vk::QueueFlagBits::eGraphics);
	if (indices.empty())
	{
		return false;
	}
	m_IsEnabledAsyncComputeQueue = true;
	m_AsyncComputeQueueIndex = indices.front();
	return true;
}

bool TestLib::TestGraphicsVulkanDevice::IsEnabledSwapchain() const noexcept { return m_IsEnabledSwapchain; }
bool TestLib::TestGraphicsVulkanDevice::IsEnabledGeometryShader() const noexcept { return m_IsEnabledGeometryShader; }
bool TestLib::TestGraphicsVulkanDevice::IsEnabledTesselationShader() const noexcept { return m_IsEnabledTesselationShader; }
bool TestLib::TestGraphicsVulkanDevice::IsEnabledDedicatedAllocation() const noexcept { return m_IsEnabledDedicatedAllocation; }
bool TestLib::TestGraphicsVulkanDevice::IsEnabledDescriptorIndexing() const noexcept { return m_IsEnabledDescriptorIndexing; }
bool TestLib::TestGraphicsVulkanDevice::IsEnabledBufferDeviceAddress() const noexcept { return m_IsEnabledBufferDeviceAddress; }
bool TestLib::TestGraphicsVulkanDevice::IsEnabledRayTracing() const noexcept { return m_IsEnabledRayTracing; }
bool TestLib::TestGraphicsVulkanDevice::IsEnabledDynamicRendering() const noexcept { return m_IsEnabledDynamicRendering; }
bool TestLib::TestGraphicsVulkanDevice::IsEnabledAsyncComputeQueue() const noexcept { return m_IsEnabledAsyncComputeQueue; }
bool TestLib::TestGraphicsVulkanDevice::IsEnabledAsyncTransferQueue() const noexcept { return m_IsEnabledAsyncTransferQueue; }

auto TestLib::TestGraphicsVulkanDevice::FindQueueFamilyIndices(const std::vector<vk::QueueFamilyProperties> &queueProps, vk::QueueFlags requiredFlags, vk::QueueFlags avoidFlags) noexcept -> std::vector<uint32_t>
{
	std::vector<uint32_t> res = {};
	uint32_t index = 0;
	for (auto &queueProp : queueProps)
	{
		if ((queueProp.queueFlags & requiredFlags) != requiredFlags)
		{
			++index;
			continue;
		}
		if ((queueProp.queueFlags & avoidFlags) != vk::QueueFlags())
		{
			++index;
			continue;
		}
		{
			res.push_back(index);
			++index;
		}
	}
	return res;
}