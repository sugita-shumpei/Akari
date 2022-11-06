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

int main(int argc, const char** argv)
{
	using namespace Akari::Graphics::Vulkan::Core;
	
	auto vkRaiiContext = std::make_unique<vk::raii::Context>();

	using list_traits = AkariVKExtensionListTraits<
		AkariVKExtensionFlags::eVK_EXT_debug_utils,  AkariVKExtensionFlags::eVK_KHR_surface,
#ifdef WIN32
		AkariVKExtensionFlags::eVK_KHR_win32_surface,
#endif
#ifdef __APPLE__
		AkariVKExtensionFlags::eVK_EXT_metal_surface, AkariVKExtensionFlags::eVK_KHR_portability_enumeration,
#endif
#ifdef __linux__
		AkariVKExtensionFlags::eVK_KHR_xcb_surface, AkariVKExtensionFlags::eVK_KHR_xlib_surface,
#endif
		AkariVKExtensionFlags::eVK_KHR_swapchain,  AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
		AkariVKExtensionFlags::eVK_KHR_ray_query, AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1,
		AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state, AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2,
		AkariVKExtensionFlags::eVK_EXT_opacity_micromap, AkariVKExtensionFlags::eVK_KHR_dynamic_rendering,
		AkariVKExtensionFlags::eVK_EXT_mesh_shader
	>;

	auto instanceApiVersion = vkRaiiContext->enumerateInstanceVersion();
	auto applicationInfo = vk::ApplicationInfo()
		.setApiVersion(instanceApiVersion)
		.setApplicationVersion(VK_MAKE_API_VERSION(0, 1, 0, 0))
		.setEngineVersion(VK_MAKE_API_VERSION(0, 1, 0, 0))
		.setPApplicationName("Application0")
		.setPEngineName("Engine0");
	
	auto instanceExtensionNames = std::vector<const char*>();
	if (instanceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3) {
		instanceExtensionNames = list_traits::EnumerateRequiredVulkan13InstanceExtensionNames();
	}
	else if (instanceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2) {
		instanceExtensionNames = list_traits::EnumerateRequiredVulkan12InstanceExtensionNames();
	}else if(instanceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1) {
		instanceExtensionNames = list_traits::EnumerateRequiredVulkan11InstanceExtensionNames();
	}
	else  {
		instanceExtensionNames = list_traits::EnumerateRequiredVulkan10InstanceExtensionNames();
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
			vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral|
			vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation 
		)
		.setPfnUserCallback(DebugMessageCallback);

#ifndef NDEBUG
	instance_create_info.pNext = &debug_utils_messenger_create_info;
#endif
	auto vkRaiiInstance = std::make_unique<vk::raii::Instance>(*vkRaiiContext, instance_create_info);
	auto vkRaiiDebugMessenger = std::unique_ptr<vk::raii::DebugUtilsMessengerEXT>(nullptr);
#ifndef NDEBUG
	vkRaiiDebugMessenger = std::make_unique<vk::raii::DebugUtilsMessengerEXT>(
		*vkRaiiInstance, debug_utils_messenger_create_info
	);
#endif
	auto vkRaiiPhysicalDevices = std::make_unique<vk::raii::PhysicalDevices>(
		*vkRaiiInstance
	);
	auto deviceProperties = (*vkRaiiPhysicalDevices)[0].getProperties();
	auto deviceApiVersion = std::min(instanceApiVersion, deviceProperties.apiVersion);

	auto deviceExtensionNames  = std::vector<const char*>();
	if (deviceApiVersion      >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3) {
		deviceExtensionNames = list_traits::EnumerateRequiredVulkan13DeviceExtensionNames();
	}
	else if (deviceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2) {
		deviceExtensionNames = list_traits::EnumerateRequiredVulkan12DeviceExtensionNames();
	}
	else if (deviceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1) {
		deviceExtensionNames = list_traits::EnumerateRequiredVulkan11DeviceExtensionNames();
	}
	else {
		deviceExtensionNames = list_traits::EnumerateRequiredVulkan10DeviceExtensionNames();
	}

	{
		bool isFound = true;
		auto deviceExtensionProps = (*vkRaiiPhysicalDevices)[0].enumerateDeviceExtensionProperties();
		for (auto& deviceExtensionName : deviceExtensionNames) {
			if (ranges::v3::find_if(deviceExtensionProps, [deviceExtensionName](const vk::ExtensionProperties& extenProp) {
				return std::string_view(extenProp.extensionName.data()) == std::string_view(deviceExtensionName);
				}) == std::end(deviceExtensionProps)) {
				isFound = false;
			}
		}
		assert(isFound);
	}
	const float priority = 1.0f;
	auto deviceQueueCreateInfos = std::vector<vk::DeviceQueueCreateInfo>();
	{
		auto queueFamilyProperties = (*vkRaiiPhysicalDevices)[0].getQueueFamilyProperties();
		auto geneQueIndices = find_queue_family_indices((*vkRaiiPhysicalDevices)[0], queueFamilyProperties);
		auto compQueIndices = find_queue_family_indices((*vkRaiiPhysicalDevices)[0], queueFamilyProperties, vk::QueueFlagBits::eCompute|  vk::QueueFlagBits::eTransfer, vk::QueueFlagBits::eGraphics);
		auto tranQueIndices = find_queue_family_indices((*vkRaiiPhysicalDevices)[0], queueFamilyProperties, vk::QueueFlagBits::eTransfer, vk::QueueFlagBits::eCompute | vk::QueueFlagBits::eGraphics);
		assert(geneQueIndices.size() >= 1);
		deviceQueueCreateInfos.push_back(vk::DeviceQueueCreateInfo().setQueueFamilyIndex(geneQueIndices.front()).setQueueCount(1).setPQueuePriorities(&priority));
		if (!compQueIndices.empty()) {

			deviceQueueCreateInfos.push_back(vk::DeviceQueueCreateInfo().setQueueFamilyIndex(compQueIndices.front()).setQueueCount(1).setPQueuePriorities(&priority));
		}
		if (!tranQueIndices.empty()) {

			deviceQueueCreateInfos.push_back(vk::DeviceQueueCreateInfo().setQueueFamilyIndex(tranQueIndices.front()).setQueueCount(1).setPQueuePriorities(&priority));
		}
	}
	auto vkRaiiDevice = std::unique_ptr<vk::raii::Device>(nullptr);
	if (deviceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3)
	{
		auto unique_features_tuple = list_traits::MakeUniqueRequiredVulkan13DeviceExtensionFeaturesTuple();
		{
			VkPhysicalDevice vkPhysicalDevice = vkRaiiPhysicalDevices->operator[](0).operator*();
			PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2 = vkRaiiPhysicalDevices->operator[](0).getDispatcher()->vkGetPhysicalDeviceFeatures2;
			if (!vkGetPhysicalDeviceFeatures2) {
				vkGetPhysicalDeviceFeatures2 = vkRaiiPhysicalDevices->operator[](0).getDispatcher()->vkGetPhysicalDeviceFeatures2KHR;
				assert(vkGetPhysicalDeviceFeatures2);
			}
			vkGetPhysicalDeviceFeatures2(vkPhysicalDevice, reinterpret_cast<VkPhysicalDeviceFeatures2KHR*>(
				Akari::Core::get_if<vk::PhysicalDeviceFeatures2KHR>(unique_features_tuple.get())
				));
			{
				Akari::Core::get_if<vk::PhysicalDeviceFeatures2KHR>(unique_features_tuple.get())->features.robustBufferAccess          = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceVulkan12Features>(unique_features_tuple.get())->bufferDeviceAddressCaptureReplay = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceVulkan12Features>(unique_features_tuple.get())->bufferDeviceAddressMultiDevice   = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceVulkan13Features>(unique_features_tuple.get())->robustImageAccess                = VK_FALSE;
#ifndef NDEBUG
				Akari::Core::get_if<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>(unique_features_tuple.get())->rayTracingPipelineShaderGroupHandleCaptureReplay = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>(unique_features_tuple.get())->rayTracingPipelineShaderGroupHandleCaptureReplayMixed = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>(unique_features_tuple.get())->accelerationStructureCaptureReplay = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceOpacityMicromapFeaturesEXT>(unique_features_tuple.get())->micromapCaptureReplay = VK_FALSE;
#endif
			}
		}
		vkRaiiDevice = std::make_unique<vk::raii::Device>(
			(*vkRaiiPhysicalDevices)[0], vk::DeviceCreateInfo()
			.setQueueCreateInfos(deviceQueueCreateInfos)
			.setPEnabledExtensionNames(deviceExtensionNames)
			.setPNext(Akari::Core::get_if<vk::PhysicalDeviceFeatures2KHR>(unique_features_tuple.get()))
		);
	}else if (deviceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2) {
		auto unique_features_tuple = list_traits::MakeUniqueRequiredVulkan12DeviceExtensionFeaturesTuple();
		{
			VkPhysicalDevice vkPhysicalDevice = vkRaiiPhysicalDevices->operator[](0).operator*();
			PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2 = vkRaiiPhysicalDevices->operator[](0).getDispatcher()->vkGetPhysicalDeviceFeatures2;
			if (!vkGetPhysicalDeviceFeatures2) {
				vkGetPhysicalDeviceFeatures2 = vkRaiiPhysicalDevices->operator[](0).getDispatcher()->vkGetPhysicalDeviceFeatures2KHR;
				assert(vkGetPhysicalDeviceFeatures2);
			}
			vkGetPhysicalDeviceFeatures2(vkPhysicalDevice, reinterpret_cast<VkPhysicalDeviceFeatures2KHR*>(
				Akari::Core::get_if<vk::PhysicalDeviceFeatures2KHR>(unique_features_tuple.get())
				));
			{
				Akari::Core::get_if<vk::PhysicalDeviceFeatures2KHR>(unique_features_tuple.get())->features.robustBufferAccess = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceVulkan12Features>(unique_features_tuple.get())->bufferDeviceAddressCaptureReplay = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceVulkan12Features>(unique_features_tuple.get())->bufferDeviceAddressMultiDevice = VK_FALSE;
#ifndef NDEBUG
				Akari::Core::get_if<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>(unique_features_tuple.get())->rayTracingPipelineShaderGroupHandleCaptureReplay = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>(unique_features_tuple.get())->rayTracingPipelineShaderGroupHandleCaptureReplayMixed = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>(unique_features_tuple.get())->accelerationStructureCaptureReplay = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceOpacityMicromapFeaturesEXT>(unique_features_tuple.get())->micromapCaptureReplay = VK_FALSE;
#endif
			}
		}
		vkRaiiDevice = std::make_unique<vk::raii::Device>(
			(*vkRaiiPhysicalDevices)[0], vk::DeviceCreateInfo()
			.setQueueCreateInfos(deviceQueueCreateInfos)
			.setPEnabledExtensionNames(deviceExtensionNames)
			.setPNext(Akari::Core::get_if<vk::PhysicalDeviceFeatures2KHR>(unique_features_tuple.get()))
			);
	} else if (deviceApiVersion >= AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1)
	{
		auto unique_features_tuple = list_traits::MakeUniqueRequiredVulkan11DeviceExtensionFeaturesTuple();
		{
			VkPhysicalDevice vkPhysicalDevice = vkRaiiPhysicalDevices->operator[](0).operator*();
			PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2 = vkRaiiPhysicalDevices->operator[](0).getDispatcher()->vkGetPhysicalDeviceFeatures2;
			if (!vkGetPhysicalDeviceFeatures2) {
				vkGetPhysicalDeviceFeatures2 = vkRaiiPhysicalDevices->operator[](0).getDispatcher()->vkGetPhysicalDeviceFeatures2KHR;
				assert(vkGetPhysicalDeviceFeatures2);
			}
			vkGetPhysicalDeviceFeatures2(vkPhysicalDevice, reinterpret_cast<VkPhysicalDeviceFeatures2KHR*>(
				Akari::Core::get_if<vk::PhysicalDeviceFeatures2KHR>(unique_features_tuple.get())
				));
			{
				Akari::Core::get_if<vk::PhysicalDeviceFeatures2KHR>(unique_features_tuple.get())->features.robustBufferAccess = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR>(unique_features_tuple.get())->bufferDeviceAddressCaptureReplay = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR>(unique_features_tuple.get())->bufferDeviceAddressMultiDevice = VK_FALSE;
#ifndef NDEBUG
				Akari::Core::get_if<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>(unique_features_tuple.get())->rayTracingPipelineShaderGroupHandleCaptureReplay = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceRayTracingPipelineFeaturesKHR>(unique_features_tuple.get())->rayTracingPipelineShaderGroupHandleCaptureReplayMixed = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceAccelerationStructureFeaturesKHR>(unique_features_tuple.get())->accelerationStructureCaptureReplay = VK_FALSE;
				Akari::Core::get_if<vk::PhysicalDeviceOpacityMicromapFeaturesEXT>(unique_features_tuple.get())->micromapCaptureReplay = VK_FALSE;
#endif
			}
		}
		vkRaiiDevice = std::make_unique<vk::raii::Device>(
			(*vkRaiiPhysicalDevices)[0], vk::DeviceCreateInfo()
			.setQueueCreateInfos(deviceQueueCreateInfos)
			.setPEnabledExtensionNames(deviceExtensionNames)
			.setPNext(Akari::Core::get_if<vk::PhysicalDeviceFeatures2KHR>(unique_features_tuple.get()))
			);
	}
	else {
		std::terminate();
	}


	vkRaiiDevice.reset();
	vkRaiiPhysicalDevices.reset();
	vkRaiiDebugMessenger.reset();
	vkRaiiInstance.reset();
	vkRaiiContext.reset();
	return 0;
}