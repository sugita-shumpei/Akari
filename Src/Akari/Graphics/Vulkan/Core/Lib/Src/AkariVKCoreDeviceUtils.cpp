#include <Akari/Graphics/Vulkan/Core/AkariVKCoreDeviceUtils.h>

auto Akari::Graphics::Vulkan::Core::find_queue_family_indices(const vk::raii::PhysicalDevice& physicalDevice, const std::vector<vk::QueueFamilyProperties>& queueFamilyProperties, vk::QueueFlags requredFlags, vk::QueueFlags avoidFlags, const vk::raii::SurfaceKHR* pSurface) -> std::vector<uint32_t> {
	std::vector<uint32_t> queueFamilyIndices = {};
	for (uint32_t i = 0; i < std::size(queueFamilyProperties); ++i) {
		if (pSurface) {
			if (physicalDevice.getSurfaceSupportKHR(i, pSurface->operator*()) != VK_SUCCESS) {
				continue;
			}
		}
		if (((queueFamilyProperties[i].queueFlags & requredFlags) != requredFlags) ||
			((queueFamilyProperties[i].queueFlags & avoidFlags) != vk::QueueFlags{})) {
			continue;
		}
		queueFamilyIndices.push_back(i);
	}
	return queueFamilyIndices;
}
