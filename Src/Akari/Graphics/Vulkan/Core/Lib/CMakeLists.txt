add_library(Akari-Graphics-Vulkan-Core-Lib STATIC

${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCore.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreBuffer.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreCommandBuffer.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreCommandPool.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreDescriptorPool.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreDescriptorSet.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreDescriptorSetLayout.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreDevice.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreDeviceUtils.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCorePhysicalDevice.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreDeviceMemory.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreFramebuffer.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreImage.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreInstance.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreQueue.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreSemaphore.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreExtension.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Core/AKariVKCoreExtensionUtils.h

${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCore.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreBuffer.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreCommandBuffer.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreCommandPool.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreDescriptorPool.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreDescriptorSet.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreDescriptorSetLayout.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreDevice.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreDeviceUtils.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCorePhysicalDevice.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreDeviceMemory.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreFramebuffer.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreImage.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreInstance.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreQueue.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreSemaphore.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKCoreSwapchain.cpp
)
target_include_directories(Akari-Graphics-Vulkan-Core-Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_link_libraries(Akari-Graphics-Vulkan-Core-Lib  PUBLIC Vulkan::Vulkan Akari-Core-Lib)