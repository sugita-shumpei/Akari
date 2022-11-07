add_library(Akari-Graphics-Vulkan 
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/AkariVulkanInstance.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/AkariVulkanDevice.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/AkariVulkanQueue.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/AkariVulkanSurface.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/AkariVulkanSwapchain.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/AkariVulkanCommandBuffer.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/AkariVulkanCommandPool.h

${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariVulkanInstance.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariVulkanDevice.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariVulkanQueue.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariVulkanSurface.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariVulkanSwapchain.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariVulkanCommandBuffer.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariVulkanCommandPool.cpp
)
target_include_directories(Akari-Graphics-Vulkan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_link_libraries(Akari-Graphics-Vulkan PUBLIC Akari-Engine Vulkan::Vulkan)