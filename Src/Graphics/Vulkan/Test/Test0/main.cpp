#include <Akari/Graphics/Vulkan/AkariVulkanInstance.h>
#include <Akari/Graphics/Vulkan/AkariVulkanDevice.h>
#include <Akari/Engine/AkariUtility.h>
#include <iostream>
int main(int argc, const char** argv)
{
	auto vk_raii_context = std::make_unique<vk::raii::Context>();
	auto vk_raii_instance = std::unique_ptr<vk::raii::Instance>(nullptr);
	{
		auto vk_application_info = vk::ApplicationInfo()
			.setApiVersion(VK_API_VERSION_1_3)
			.setPApplicationName("Akari-Graphics-Vulkan-Test0")
			.setApplicationVersion(VK_MAKE_API_VERSION(0, 1, 0, 0))
			.setPEngineName("Akari-Graphics-Vulkan-Test0")
			.setEngineVersion(VK_MAKE_API_VERSION(0, 1, 0, 0));

		auto instance_extension_names = std::vector<const char*>{
			VK_KHR_SURFACE_EXTENSION_NAME,
			"VK_KHR_win32_surface",
			VK_EXT_DEBUG_UTILS_EXTENSION_NAME
		};

		auto instance_layer_names = std::vector<const char*>{
			"VK_LAYER_KHRONOS_validation"
		};
		
		auto vk_instance_create_info = vk::InstanceCreateInfo()
			.setPApplicationInfo(&vk_application_info)
			.setPEnabledExtensionNames(instance_extension_names)
			.setPEnabledLayerNames(instance_layer_names);

		vk_raii_instance = std::make_unique<vk::raii::Instance>(*vk_raii_context, vk_instance_create_info);

	}

	{
		auto vk_raii_physical_devices   = vk_raii_instance->enumeratePhysicalDevices();
		auto akari_vulkan_features_list   = Akari::Graphics::AkariVulkanDeviceFeaturesList();
		akari_vulkan_features_list.SetFeatures(vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR());
		akari_vulkan_features_list.SetFeatures(vk::PhysicalDeviceDescriptorIndexingFeaturesEXT());
		akari_vulkan_features_list.SetFeatures(vk::PhysicalDeviceRayTracingPipelineFeaturesKHR());
		akari_vulkan_features_list.SetFeatures(vk::PhysicalDeviceRayQueryFeaturesKHR());
		akari_vulkan_features_list.SetFeatures(vk::PhysicalDeviceAccelerationStructureFeaturesKHR());
		akari_vulkan_features_list.SetFeatures(vk::PhysicalDeviceRayTracingMaintenance1FeaturesKHR());
		akari_vulkan_features_list.SetFeatures(vk::PhysicalDeviceOpacityMicromapFeaturesEXT());
		akari_vulkan_features_list.Query(vk_raii_physical_devices[0]);
		auto akari_vulkan_features_list_1 = akari_vulkan_features_list;
		{
			auto* pFeatures = akari_vulkan_features_list_1.AtFeaturesPointer<vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR>();
			std::cout << "bufferDeviceAddress             : " << pFeatures->bufferDeviceAddress              << std::endl;
			std::cout << "bufferDeviceAddressCaptureReplay: " << pFeatures->bufferDeviceAddressCaptureReplay << std::endl;
			std::cout << "bufferDeviceAddressMultiDevice  : " << pFeatures->bufferDeviceAddressMultiDevice   << std::endl;
		}
		{
			auto* pFeatures = akari_vulkan_features_list_1.AtFeaturesPointer<vk::PhysicalDeviceDescriptorIndexingFeaturesEXT>();
			std::cout << "runtimeDescriptorArray                      : " << pFeatures->runtimeDescriptorArray << std::endl;
			std::cout << "descriptorBindingPartiallyBound             : " << pFeatures->descriptorBindingPartiallyBound << std::endl;
			std::cout << "descriptorBindingSampledImageUpdateAfterBind: " << pFeatures->descriptorBindingSampledImageUpdateAfterBind << std::endl;
		}
	}
	vk_raii_instance.reset();
	vk_raii_context.reset();
	return 0;
}