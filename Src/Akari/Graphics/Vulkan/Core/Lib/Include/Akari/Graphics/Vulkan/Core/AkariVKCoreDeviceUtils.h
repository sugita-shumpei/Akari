#ifndef AKARI_GRAPHCIS_VULKAN_CORE_AKARI_VK_CORE_DEVICE_UTILS_H
#define AKARI_GRAPHCIS_VULKAN_CORE_AKARI_VK_CORE_DEVICE_UTILS_H
#include <Akari/Graphics/Vulkan/Core/AkariVKCore.h>
#include <vector>
#include <string_view>
#include <tuple>
AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_BEGIN

auto find_queue_family_indices(
	const vk::raii::PhysicalDevice& physicalDevice,
	const std::vector<vk::QueueFamilyProperties>& queueFamilyProperties,
	vk::QueueFlags requredFlags = vk::QueueFlagBits::eGraphics | vk::QueueFlagBits::eCompute | vk::QueueFlagBits::eTransfer,
	vk::QueueFlags avoidFlags = {},
	const vk::raii::SurfaceKHR* pSurface = nullptr
)->std::vector<uint32_t>;

AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_END
#endif