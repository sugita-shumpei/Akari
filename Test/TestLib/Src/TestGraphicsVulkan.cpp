#include <TestLib/TestGraphicsVulkan.h>
#include <range/v3/algorithm.hpp>
#include <range/v3/iterator/insert_iterators.hpp>
bool TestLib::TestGraphicsVulkanManager::IsInitialized() const noexcept { return m_IsInitialized; }

bool TestLib::TestGraphicsVulkanManager::IsEnabledExtension(const std::string& extension_name) const noexcept
{
	return ranges::v3::find(m_InstanceEnabledExtensionNames, extension_name)!=std::end(m_InstanceEnabledExtensionNames);
}

bool TestLib::TestGraphicsVulkanManager::IsEnabledLayer(const std::string& layer_name) const noexcept
{
	return ranges::v3::find(m_InstanceEnabledLayerNames, layer_name) != std::end(m_InstanceEnabledLayerNames);
}

bool TestLib::TestGraphicsVulkanManager::IsEnabledDebug() const noexcept
{
	return m_IsEnabledDebug;
}

bool TestLib::TestGraphicsVulkanManager::IsEnabledSurface() const noexcept
{
	return m_IsEnabledSurface;
}

bool TestLib::TestGraphicsVulkanManager::IsEnabledEmulation() const noexcept
{
	return m_IsEnabledEmulation;
}
/*TODO*/
bool TestLib::TestGraphicsVulkanManager::EnableExtensions(const std::vector<std::string>& extension_names) noexcept
{
	if (m_IsInitialized) { 
		return false; 
	}
	if (!m_PreInitializedState->SupportExtensions(extension_names)) {
		return false;
	}
	auto newExtensions = std::vector<std::string>();
	newExtensions.reserve(extension_names.size());
	ranges::v3::copy_if(extension_names, ranges::v3::back_inserter(newExtensions), [this](const std::string& extension_name) { return !IsEnabledExtension(extension_name); });
	m_InstanceEnabledExtensionNames.reserve(m_InstanceEnabledExtensionNames.size() + newExtensions.size());
	ranges::v3::copy(newExtensions, ranges::v3::back_inserter(m_InstanceEnabledExtensionNames));
	m_PreInitializedState->instancePEnabledExtensionNames.reserve(m_PreInitializedState->instancePEnabledExtensionNames.size() + newExtensions.size());
	auto 
	ranges::v3::transform(newExtensions, ranges::v3::back_inserter(m_PreInitializedState->instancePEnabledExtensionNames), [](const std::string& str) { return str.c_str(); });
	return true;
}
/*TODO*/
bool TestLib::TestGraphicsVulkanManager::EnableExtension(const std::string& extension_name) noexcept
{
	if (m_IsInitialized) {
		return false;
	}
	if (!m_PreInitializedState->SupportExtension(extension_name)) {
		return false;
	}
	if (!IsEnabledExtension(extension_name)) {
		m_InstanceEnabledExtensionNames.push_back(extension_name);
		m_PreInitializedState->instancePEnabledExtensionNames.push_back(m_InstanceEnabledExtensionNames.back().c_str());
	}
	return true;
}
/*TODO*/
bool TestLib::TestGraphicsVulkanManager::EnableLayers(const std::vector<std::string>& layer_names) noexcept
{
	if (m_IsInitialized) {
		return false;
	}
	if (!m_PreInitializedState->SupportLayers(layer_names)) {
		return false;
	}
	auto newLayers = std::vector<std::string>();
	newLayers.reserve(layer_names.size());
	ranges::v3::copy_if(layer_names, ranges::v3::back_inserter(newLayers), [this](const std::string& layer_name) { return !IsEnabledLayer(layer_name); });
	m_InstanceEnabledLayerNames.reserve(m_InstanceEnabledLayerNames.size() + newLayers.size());
	ranges::v3::copy(newLayers, ranges::v3::back_inserter(m_InstanceEnabledLayerNames));
	return true;
}
/*TODO*/
bool TestLib::TestGraphicsVulkanManager::EnableLayer(const std::string& layer_name) noexcept
{
	if (m_IsInitialized) {
		return false;
	}
	if (!m_PreInitializedState->SupportLayer(layer_name)) {
		return false;
	}
	if (!IsEnabledLayer(layer_name)) {
		m_InstanceEnabledLayerNames.push_back(layer_name);
	}
	return true;
}

bool TestLib::TestGraphicsVulkanManager::EnableDebug(const vk::DebugUtilsMessengerCreateInfoEXT& debug_utils) noexcept
{
	if (m_IsInitialized) { return false; }
	if (!this->EnableExtension(VK_EXT_DEBUG_UTILS_EXTENSION_NAME)) { 
		return false; 
	}
	m_IsEnabledDebug = true;
	m_DebugUtilsMessengerCreateInfo = debug_utils;
	return true;
}

bool TestLib::TestGraphicsVulkanManager::EnableSurface() noexcept
{
	auto extensionNamesForSurfaces = std::vector<std::string>{
		VK_KHR_SURFACE_EXTENSION_NAME,
#ifdef WIN32
		"VK_KHR_win32_surface",
#endif
#ifdef __APPLE__
		"VK_EXT_metal_surface",
#endif
#ifdef __linux__
		"VK_KHR_xlib_surface",
		"VK_KHR_xcb_surface",
#endif
	};
	if (!this->EnableExtensions(extensionNamesForSurfaces)) {
		return false;
	}
	m_IsEnabledSurface = true;
	return true;
}

bool TestLib::TestGraphicsVulkanManager::EnableEmulation() noexcept
{
	if (!this->EnableExtension(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME)) {
		return false;
	}
	m_IsEnabledEmulation = true;
	return true;
}

TestLib::TestGraphicsVulkanManager::TestGraphicsVulkanManager() noexcept
{
	m_VkRaiiContext = std::make_unique <vk::raii::Context>();
	m_PreInitializedState = std::make_unique<PreInitializedState>(*m_VkRaiiContext.get());
}

auto TestLib::TestGraphicsVulkanManager::GetHandle() noexcept -> TestGraphicsVulkanManager&
{
	// TODO: return ステートメントをここに挿入します
	static TestGraphicsVulkanManager manager;
	return manager;
}

TestLib::TestGraphicsVulkanManager::~TestGraphicsVulkanManager() noexcept
{
	m_VkRaiiContext = nullptr;
	m_PreInitializedState = nullptr;
}

bool TestLib::TestGraphicsVulkanManager::Init()
{
	if (m_IsInitialized) { return false; }
	auto applicationInfo = vk::ApplicationInfo();
	applicationInfo.apiVersion = m_InstanceApiVersion;
	applicationInfo.pApplicationName = m_ApplicationName.c_str();
	applicationInfo.applicationVersion = m_ApplicationVersion;
	applicationInfo.pEngineName = m_EngineName.c_str();
	applicationInfo.engineVersion = m_EngineVersion;

	auto instanceCreateInfo = vk::InstanceCreateInfo();
	instanceCreateInfo.pApplicationInfo = &applicationInfo;
	instanceCreateInfo.setPEnabledExtensionNames(m_PreInitializedState->instancePEnabledExtensionNames);
	instanceCreateInfo.setPEnabledLayerNames(m_PreInitializedState->instancePEnabledLayerNames);

	auto debugUtilsMessengerCreateInfo = m_DebugUtilsMessengerCreateInfo;
	if (m_IsEnabledEmulation) {
		instanceCreateInfo.flags |= vk::InstanceCreateFlagBits::eEnumeratePortabilityKHR;
	}
	if (m_IsEnabledDebug) {
		instanceCreateInfo.pNext = &debugUtilsMessengerCreateInfo;
	}

	m_VkRaiiInstance = std::make_unique<vk::raii::Instance>(
		*m_VkRaiiContext.get(), instanceCreateInfo
	);
	if (!m_VkRaiiInstance) { return false; }
	if (m_IsEnabledDebug) {
		m_VkRaiiDebugUtilsMessenger =  std::make_unique<vk::raii::DebugUtilsMessengerEXT>(
			*m_VkRaiiInstance.get(), debugUtilsMessengerCreateInfo
		);
		if (!m_VkRaiiDebugUtilsMessenger) { return false; }
	}
	m_IsInitialized = true;
	m_PreInitializedState.reset();
	return true;
}

void TestLib::TestGraphicsVulkanManager::Free()
{
	if (!m_IsInitialized) { return; }
	m_VkRaiiDebugUtilsMessenger.get();
	m_VkRaiiInstance.reset();
	m_IsInitialized = false;
	m_PreInitializedState = std::make_unique<PreInitializedState>(*m_VkRaiiContext.get(),m_InstanceEnabledExtensionNames,m_InstanceEnabledLayerNames);
}

void TestLib::TestGraphicsVulkanManager::SetInstanceApiVersion(uint32_t version) noexcept {
	if (IsInitialized()) { return; }
	m_InstanceApiVersion = version;
}

void TestLib::TestGraphicsVulkanManager::SetApplicationConfig(const std::string& name, uint32_t version) noexcept {
	if (IsInitialized()) { return; }
	m_ApplicationName = name;
	m_ApplicationVersion = version;
}

void TestLib::TestGraphicsVulkanManager::SetEngineConfig(const std::string& name, uint32_t version) noexcept {
	if (IsInitialized()) { return; }
	m_EngineName = name;
	m_EngineVersion = version;
}

TestLib::TestGraphicsVulkanManager::PreInitializedState::PreInitializedState(const vk::raii::Context& context) noexcept
{
	instanceApiVersion = context.enumerateInstanceVersion();
	instanceExtensionProperties = context.enumerateInstanceExtensionProperties();
	instanceLayerProperties = context.enumerateInstanceLayerProperties();
}

TestLib::TestGraphicsVulkanManager::PreInitializedState::PreInitializedState(const vk::raii::Context& context,const std::vector<std::string>& extensionNames, const std::vector<std::string>& layerNames) noexcept
	:PreInitializedState(context)
{
	instancePEnabledExtensionNames.reserve(extensionNames.size());
	ranges::v3::transform(extensionNames, ranges::v3::back_inserter(instancePEnabledExtensionNames), [](const std::string& str) { return str.c_str(); });
	instancePEnabledLayerNames.reserve(layerNames.size());
	ranges::v3::transform(layerNames, ranges::v3::back_inserter(instancePEnabledLayerNames), [](const std::string& str) { return str.c_str(); });
}

bool TestLib::TestGraphicsVulkanManager::PreInitializedState::SupportExtensions(const std::vector<std::string>& extensions) const noexcept
{
	return ranges::v3::all_of(extensions, [this](const std::string& extension) {
		return this->SupportExtension(extension);
	});
}

bool TestLib::TestGraphicsVulkanManager::PreInitializedState::SupportExtension(const std::string& extension) const noexcept
{
	return ranges::v3::find_if(instanceExtensionProperties, [&extension](const vk::ExtensionProperties& ext) {
		return std::string(ext.extensionName.data()) == extension;
	})!=std::end(instanceExtensionProperties);
}

bool TestLib::TestGraphicsVulkanManager::PreInitializedState::SupportLayers(const std::vector<std::string>& layers) const noexcept
{
	return ranges::v3::all_of(layers, [this](const std::string& layer) {
		return this->SupportLayer(layer);
	});
}

bool TestLib::TestGraphicsVulkanManager::PreInitializedState::SupportLayer(const std::string& layer) const noexcept
{	
	return ranges::v3::find_if(instanceLayerProperties, [&layer](const vk::LayerProperties& lyr) {
		return std::string(lyr.layerName.data()) == layer;
	})!=std::end(instanceLayerProperties);
}

auto TestLib::TestGraphicsVulkan::Manager() noexcept -> TestGraphicsVulkanManager&
{
	// TODO: return ステートメントをここに挿入します
	return TestLib::TestGraphicsVulkanManager::GetHandle();
}
