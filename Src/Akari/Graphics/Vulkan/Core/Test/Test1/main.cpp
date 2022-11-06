#include <Akari/Graphics/Vulkan/Core/AkariVKCoreDeviceUtils.h>
#include <Akari/Graphics/Vulkan/Core/AkariVKCoreExtensionUtils.h>
#include <range/v3/algorithm.hpp>
#include <iostream>
#include <memory>
#include <tuple>
#include <array>
#include <any>
static VKAPI_ATTR  VkBool32 VKAPI_CALL DebugMessageCallback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeveirty,
	VkDebugUtilsMessageTypeFlagsEXT messageTypes,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	void* pUserData){
	auto messageCppSeveirty = static_cast<vk::DebugUtilsMessageSeverityFlagBitsEXT>(messageSeveirty);
	auto messageCppTypes = static_cast<vk::DebugUtilsMessageTypeFlagsEXT>(messageTypes);
	std::cout << "[" << vk::to_string(messageCppSeveirty) << "]";
	std::cout << "[" << vk::to_string(messageCppTypes) << "]: ";
	std::cout << pCallbackData->pMessage << std::endl;
	return VK_FALSE;
}

template<typename ExtensionListTraits>
struct Instance {
	std::unique_ptr<vk::raii::Context>                vkRaiiContext  = {};
	std::unique_ptr<vk::raii::Instance>               vkRaiiInstance = {};
	std::unique_ptr<vk::raii::DebugUtilsMessengerEXT> vkRaiiDebugUtilsMessenger     = {};
	std::vector<const char*>                          instanceExtensionNames        = {};
	std::vector<const char*>                          instanceLayerNames            = {};
	uint32_t                                          instanceApiVersion            = {};
	vk::DebugUtilsMessengerCreateInfoEXT              debugUtilsMessengerCreateInfo = {};
public:
	 Instance() noexcept :vkRaiiContext{ new vk::raii::Context() } {
		instanceApiVersion = vkRaiiContext->enumerateInstanceVersion();
	}
	~Instance() {
		Free();
		vkRaiiContext.reset();
	}
	bool Init() {
		auto applicationInfo = vk::ApplicationInfo()
			.setApiVersion(instanceApiVersion)
			.setApplicationVersion(VK_MAKE_API_VERSION(0, 1, 0, 0))
			.setEngineVersion(VK_MAKE_API_VERSION(0, 1, 0, 0))
			.setPApplicationName("Application0")
			.setPEngineName("Engine0");
		if (instanceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3) {
			instanceExtensionNames = ExtensionListTraits::EnumerateRequiredVulkan13InstanceExtensionNames();
		}
		else if (instanceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2) {
			instanceExtensionNames = ExtensionListTraits::EnumerateRequiredVulkan12InstanceExtensionNames();
		}
		else if (instanceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1) {
			instanceExtensionNames = ExtensionListTraits::EnumerateRequiredVulkan11InstanceExtensionNames();
		}
		else {
			instanceExtensionNames = ExtensionListTraits::EnumerateRequiredVulkan10InstanceExtensionNames();
		}

		{
			bool isFound = true;
			auto instanceExtensionProps = vkRaiiContext->enumerateInstanceExtensionProperties();
			for (auto& instanceExtensionName : instanceExtensionNames) {
				if (ranges::v3::find_if(instanceExtensionProps, [instanceExtensionName](const vk::ExtensionProperties& extensionProps) {
					return std::string_view(extensionProps.extensionName.data()) == std::string_view(instanceExtensionName);
					}) == std::end(instanceExtensionProps)) {
					isFound = false;
				}
			}
			assert(isFound);
		}

		auto instanceLayerNames = std::vector<const char*>{
	"VK_LAYER_KHRONOS_validation",
	//"VK_LAYER_LUNARG_api_dump"
		};
		{
			bool isFound = true;
			auto instanceLayerProps = vkRaiiContext->enumerateInstanceLayerProperties();
			for (auto& instanceLayerName : instanceLayerNames) {
				if (ranges::v3::find_if(instanceLayerProps, [instanceLayerName](const vk::LayerProperties& layerProp) {
					return std::string_view(layerProp.layerName.data()) == std::string_view(instanceLayerName);
					}) == std::end(instanceLayerProps)) {
					isFound = false;
				}
			}
			assert(isFound);
		}

		auto instance_create_info = vk::InstanceCreateInfo()
			.setPApplicationInfo(&applicationInfo)
			.setPEnabledExtensionNames(instanceExtensionNames)
			.setPEnabledLayerNames(instanceLayerNames)
#ifdef __APPLE__
			.setFlags(vk::InstanceCreateFlagBits::eEnumeratePortabilityKHR)
#endif
			;
		auto debug_utils_messenger_create_info = vk::DebugUtilsMessengerCreateInfoEXT()
			.setMessageSeverity(
				vk::DebugUtilsMessageSeverityFlagBitsEXT::eError |
				vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose |
				vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning
			)
			.setMessageType(
				vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral |
				vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation
			)
			.setPfnUserCallback(DebugMessageCallback);

#ifndef NDEBUG
		instance_create_info.pNext = &debug_utils_messenger_create_info;
#endif
		vkRaiiInstance = std::make_unique<vk::raii::Instance>(*vkRaiiContext, instance_create_info);
		vkRaiiDebugUtilsMessenger = std::unique_ptr<vk::raii::DebugUtilsMessengerEXT>(nullptr);
#ifndef NDEBUG
		vkRaiiDebugUtilsMessenger = std::make_unique<vk::raii::DebugUtilsMessengerEXT>(
			*vkRaiiInstance, debug_utils_messenger_create_info
			);
#endif
		return true;
	}
	void Free() {
		vkRaiiDebugUtilsMessenger.reset();
		vkRaiiInstance.reset();
	}
};
template<typename ExtensionListTraits>
struct Device {
	using Instance = Instance<ExtensionListTraits>;
	using IAkariVKFeaturesTupleWrapper = Akari::Graphics::Vulkan::Core::IAkariVKFeaturesTupleWrapper;
	template<typename FeaturesTuple>
	using TAkariVKFeaturesTupleWrapper = Akari::Graphics::Vulkan::Core::TAkariVKFeaturesTupleWrapper<FeaturesTuple>;
	const Instance* pInstance = nullptr;
	std::unique_ptr<vk::raii::PhysicalDevice>         vkRaiiPhysicalDevice = {};
	std::unique_ptr<vk::raii::Device>                 vkRaiiDevice = {};
	std::unique_ptr<vk::raii::Queue>                  vkRaiiQueueForGraphics = {};
	std::unique_ptr<vk::raii::Queue>                  vkRaiiQueueForCompute = {};
	std::unique_ptr<vk::raii::Queue>                  vkRaiiQueueForTransfer = {};
	std::vector<const char*>                          deviceExtensionNames = {};
	vk::PhysicalDeviceProperties                      deviceProperties = {};
	std::unique_ptr<IAkariVKFeaturesTupleWrapper>     deviceFeaturesTupleWrapper = nullptr;
	std::vector<vk::QueueFamilyProperties>            queueFamilyProperties = {};
	uint32_t                                          queueFamilyIndexForGraphics = VK_QUEUE_FAMILY_IGNORED;
	uint32_t                                          queueFamilyIndexForCompute = VK_QUEUE_FAMILY_IGNORED;
	uint32_t                                          queueFamilyIndexForTransfer = VK_QUEUE_FAMILY_IGNORED;
public:
	Device(const Instance* pInstance_, uint32_t deviceIdx = 0) noexcept {
		pInstance = pInstance_;
		auto vkRaiiPhysicalDevices = std::make_unique<vk::raii::PhysicalDevices>(
			*pInstance_->vkRaiiInstance
			);
		vkRaiiPhysicalDevice = std::make_unique<vk::raii::PhysicalDevice>(std::move(vkRaiiPhysicalDevices->operator[](0)));
		deviceProperties = vkRaiiPhysicalDevice->getProperties();
		queueFamilyProperties = vkRaiiPhysicalDevice->getQueueFamilyProperties();
	}
	~Device() {
		Free();
	}
	bool Init() {
		auto apiVersion = std::min(pInstance->instanceApiVersion, deviceProperties.apiVersion);
		if (apiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3) {
			return InitAsVulkan13();
		}
		if (apiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2) {
			return InitAsVulkan12();
		}
		if (apiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1) {
			return InitAsVulkan11();
		}
		return InitAsVulkan10();
	}
	void Free() {
		if (vkRaiiQueueForGraphics) {
			vkRaiiQueueForGraphics->waitIdle();
		}
		if (vkRaiiQueueForCompute) {
			vkRaiiQueueForCompute->waitIdle();
		}
		if (vkRaiiQueueForTransfer) {
			vkRaiiQueueForTransfer->waitIdle();
		}
		vkRaiiQueueForGraphics.reset();
		vkRaiiQueueForCompute.reset();
		vkRaiiQueueForTransfer.reset();
		vkRaiiPhysicalDevice.reset();
		if (vkRaiiDevice) {
			vkRaiiDevice->waitIdle();
		}
		vkRaiiDevice.reset();
	}
private:
	bool InitAsVulkan10() {
		deviceExtensionNames = ExtensionListTraits::EnumerateRequiredVulkan10DeviceExtensionNames();
		Impl_CheckExtensions();
		auto featuresWrapper = new TAkariVKFeaturesTupleWrapper<typename ExtensionListTraits::RequiredVulkan10DeviceExtensionFeaturesTuple>();
		Impl_InitFeatures(&featuresWrapper->GetFeatures<vk::PhysicalDeviceFeatures2>());
		deviceFeaturesTupleWrapper.reset(featuresWrapper);
		Impl_ValidateFeatures();
		Impl_InitDevice();
		return true;
	}
	bool InitAsVulkan11() {
		deviceExtensionNames = ExtensionListTraits::EnumerateRequiredVulkan11DeviceExtensionNames();
		auto featuresWrapper = new TAkariVKFeaturesTupleWrapper<typename ExtensionListTraits::RequiredVulkan11DeviceExtensionFeaturesTuple>();
		Impl_InitFeatures(&featuresWrapper->GetFeatures<vk::PhysicalDeviceFeatures2>());
		deviceFeaturesTupleWrapper.reset(featuresWrapper);
		Impl_ValidateFeatures();
		Impl_InitDevice();
		return true;
	}
	bool InitAsVulkan12() {

		deviceExtensionNames = ExtensionListTraits::EnumerateRequiredVulkan12DeviceExtensionNames();
		Impl_CheckExtensions();
		auto featuresWrapper = new TAkariVKFeaturesTupleWrapper<typename ExtensionListTraits::RequiredVulkan12DeviceExtensionFeaturesTuple>();
		Impl_InitFeatures(&featuresWrapper->GetFeatures<vk::PhysicalDeviceFeatures2>());
		deviceFeaturesTupleWrapper.reset(featuresWrapper);
		Impl_ValidateFeatures();
		Impl_InitDevice();
		return true;
	}
	bool InitAsVulkan13() {
		deviceExtensionNames = ExtensionListTraits::EnumerateRequiredVulkan13DeviceExtensionNames();
		Impl_CheckExtensions();
		auto featuresWrapper = new TAkariVKFeaturesTupleWrapper<typename ExtensionListTraits::RequiredVulkan13DeviceExtensionFeaturesTuple>();
		Impl_InitFeatures(&featuresWrapper->GetFeatures<vk::PhysicalDeviceFeatures2>());
		deviceFeaturesTupleWrapper.reset(featuresWrapper);
		Impl_ValidateFeatures();
		Impl_InitDevice();
		return true;
	}
private:
	void Impl_CheckExtensions() {
		bool isFound = true;
		auto deviceExtensionProps = vkRaiiPhysicalDevice->enumerateDeviceExtensionProperties();
		for (auto& deviceExtensionName : deviceExtensionNames) {
			if (ranges::v3::find_if(deviceExtensionProps, [deviceExtensionName](const vk::ExtensionProperties& extensionProps) {
				return std::string_view(extensionProps.extensionName.data()) == std::string_view(deviceExtensionName);
				}) == std::end(deviceExtensionProps)) {
				isFound = false;
			}
		}
		assert(isFound);
	}
	void Impl_InitFeatures(vk::PhysicalDeviceFeatures2* physicalDeviceFeatures2) {
		PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR = vkRaiiPhysicalDevice->getDispatcher()->vkGetPhysicalDeviceFeatures2;
		if (!vkGetPhysicalDeviceFeatures2KHR) {
			vkGetPhysicalDeviceFeatures2KHR = vkRaiiPhysicalDevice->getDispatcher()->vkGetPhysicalDeviceFeatures2KHR;
			assert(vkGetPhysicalDeviceFeatures2KHR);
		}
		vkGetPhysicalDeviceFeatures2KHR(vkRaiiPhysicalDevice->operator*(), reinterpret_cast<VkPhysicalDeviceFeatures2KHR*>(physicalDeviceFeatures2));
	}
	void Impl_ValidateFeatures() {
		auto pFeatures2 = deviceFeaturesTupleWrapper->GetFeaturesIf<vk::PhysicalDeviceFeatures2KHR>();
		if (pFeatures2) {
			pFeatures2->features.robustBufferAccess = VK_FALSE;
		}
		auto pVulkan12Features = deviceFeaturesTupleWrapper->GetFeaturesIf<vk::PhysicalDeviceVulkan12Features>();
		if (pVulkan12Features) {
			pVulkan12Features->bufferDeviceAddressCaptureReplay = VK_FALSE;
			pVulkan12Features->bufferDeviceAddressMultiDevice   = VK_FALSE;
		}
		auto pVulkan13Features = deviceFeaturesTupleWrapper->GetFeaturesIf<vk::PhysicalDeviceVulkan13Features>();
		if (pVulkan13Features) {
			pVulkan13Features->robustImageAccess = VK_FALSE;
		}
		auto pBufferDeviceAddressFeatures = deviceFeaturesTupleWrapper->GetFeaturesIf<vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR>();
		if (pBufferDeviceAddressFeatures){
			pBufferDeviceAddressFeatures->bufferDeviceAddressCaptureReplay = VK_FALSE;
			pBufferDeviceAddressFeatures->bufferDeviceAddressMultiDevice = VK_FALSE;
		}
		auto pImageRobustnessFeatures = deviceFeaturesTupleWrapper->GetFeaturesIf<vk::PhysicalDeviceImageRobustnessFeaturesEXT>();
		if (pImageRobustnessFeatures) {
			pImageRobustnessFeatures->robustImageAccess = VK_FALSE;
		}
		auto pRayTracingPipelineFeatures = deviceFeaturesTupleWrapper->GetFeaturesIf<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>();
		if (pRayTracingPipelineFeatures) {
			pRayTracingPipelineFeatures->rayTracingPipelineShaderGroupHandleCaptureReplay      = VK_FALSE;
			pRayTracingPipelineFeatures->rayTracingPipelineShaderGroupHandleCaptureReplayMixed = VK_FALSE;
		}
		auto pAccelerationStructureFeatures = deviceFeaturesTupleWrapper->GetFeaturesIf<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>();
		if (pAccelerationStructureFeatures) {
			pAccelerationStructureFeatures->accelerationStructureCaptureReplay = VK_FALSE;
		}
		auto pOpacityMicromapFeatures = deviceFeaturesTupleWrapper->GetFeaturesIf<vk::PhysicalDeviceOpacityMicromapFeaturesEXT>();
		if (pOpacityMicromapFeatures) {
			pOpacityMicromapFeatures->micromapCaptureReplay = VK_FALSE;
		}
	}
	void Impl_InitDevice() {
		auto geneQueIndices = Akari::Graphics::Vulkan::Core::find_queue_family_indices(
			*vkRaiiPhysicalDevice, queueFamilyProperties,
			vk::QueueFlagBits::eGraphics | vk::QueueFlagBits::eTransfer | vk::QueueFlagBits::eCompute
		);
		auto compQueIndices = Akari::Graphics::Vulkan::Core::find_queue_family_indices(
			*vkRaiiPhysicalDevice, queueFamilyProperties,
			vk::QueueFlagBits::eTransfer | vk::QueueFlagBits::eCompute  , vk::QueueFlagBits::eGraphics
		);
		auto tranQueIndices = Akari::Graphics::Vulkan::Core::find_queue_family_indices(
			*vkRaiiPhysicalDevice, queueFamilyProperties,
			vk::QueueFlagBits::eTransfer , vk::QueueFlagBits::eCompute| vk::QueueFlagBits::eGraphics
		);
		std::vector<vk::DeviceQueueCreateInfo> deviceQueueCreateInfos = {};
		float queuePriority = 1.0f;
		assert(!geneQueIndices.empty());
		queueFamilyIndexForGraphics = geneQueIndices.front();
		deviceQueueCreateInfos.push_back(vk::DeviceQueueCreateInfo().setQueueFamilyIndex(queueFamilyIndexForGraphics).setQueueCount(1).setPQueuePriorities(&queuePriority));
		if (!compQueIndices.empty()) {
			queueFamilyIndexForCompute = compQueIndices.front();
			deviceQueueCreateInfos.push_back(vk::DeviceQueueCreateInfo().setQueueFamilyIndex(queueFamilyIndexForCompute).setQueueCount(1).setPQueuePriorities(&queuePriority));
		}
		if (!tranQueIndices.empty()) {
			queueFamilyIndexForTransfer = tranQueIndices.front();
			deviceQueueCreateInfos.push_back(vk::DeviceQueueCreateInfo().setQueueFamilyIndex(queueFamilyIndexForTransfer).setQueueCount(1).setPQueuePriorities(&queuePriority));
		}
		vkRaiiDevice = std::make_unique<vk::raii::Device>(
			*vkRaiiPhysicalDevice,
			vk::DeviceCreateInfo().setPEnabledExtensionNames(deviceExtensionNames)
			.setQueueCreateInfos(deviceQueueCreateInfos)
			.setPNext(deviceFeaturesTupleWrapper->GetFeaturesIf<vk::PhysicalDeviceFeatures2KHR>())
		);
		vkRaiiQueueForGraphics = std::make_unique<vk::raii::Queue>(*vkRaiiDevice, queueFamilyIndexForGraphics, 0);
		if (!compQueIndices.empty()) {
			vkRaiiQueueForCompute = std::make_unique<vk::raii::Queue>(*vkRaiiDevice, queueFamilyIndexForCompute, 0);
		}
		if (!tranQueIndices.empty()) {
			vkRaiiQueueForTransfer = std::make_unique<vk::raii::Queue>(*vkRaiiDevice, queueFamilyIndexForTransfer, 0);
		}
	}
};

int main(int argc, const char** argv)
{
	using namespace Akari::Graphics::Vulkan::Core;
	using list_traits = AkariVKExtensionListTraits<
		AkariVKExtensionFlags::eVK_EXT_debug_utils, 
		AkariVKExtensionFlags::eVK_KHR_surface,
#ifdef WIN32
		AkariVKExtensionFlags::eVK_KHR_win32_surface,
#endif
#ifdef __APPLE__
		AkariVKExtensionFlags::eVK_EXT_metal_surface, AkariVKExtensionFlags::eVK_KHR_portability_enumeration,
#endif
#ifdef __linux__
		AkariVKExtensionFlags::eVK_KHR_xcb_surface, AkariVKExtensionFlags::eVK_KHR_xlib_surface,
#endif
		AkariVKExtensionFlags::eVK_KHR_swapchain, 
		AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
		AkariVKExtensionFlags::eVK_KHR_ray_query, 
		AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1,
		AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state, 
		AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2,
		AkariVKExtensionFlags::eVK_EXT_opacity_micromap, 
		AkariVKExtensionFlags::eVK_KHR_dynamic_rendering,
		AkariVKExtensionFlags::eVK_EXT_mesh_shader
	>;
	auto instance = Instance<list_traits>();
	instance.Init();
	auto device = Device(&instance, 0);
	device.Init();
	auto vkRaiiDevice = device.vkRaiiDevice.get();

	device.Free();
	instance.Free();
	return 0;
}