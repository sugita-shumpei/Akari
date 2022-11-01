#ifndef AKARI_GRAPHCIS_VULKAN_UTILITY_UTILS_STRUCTURE_WRAPPER_H
#define AKARI_GRAPHCIS_VULKAN_UTILITY_UTILS_STRUCTURE_WRAPPER_H
#include <vulkan/vulkan.hpp>
namespace Akari::Graphics::Vulkan::Utility
{
	struct IAkariVKUtilsStructureWrapper{};
	template<typename VulkanStructure>
	struct TAkariVKUtilsStructureWrapper:public IAkariVKUtilsStructureWrapper
	{
	};

}
#endif