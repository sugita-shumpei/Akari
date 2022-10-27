#ifndef TESTLIB_TEST_GRAPHICS_VULKAN_H
#define TESTLIB_TEST_GRAPHICS_VULKAN_H
#include <vulkan/vulkan_raii.hpp>
#include <memory>
namespace TestLib {
    class TestGraphicsVulkan
    {
        std::unique_ptr<vk::raii::Context>        m_VkContext = nullptr;
        std::unique_ptr<vk::raii::Instance>       m_VkInstance = nullptr;
        std::unique_ptr<vk::raii::PhysicalDevice> m_VkPhysicalDevice = nullptr;
        std::unique_ptr<vk::raii::Device>         m_VkDevice = nullptr;
        std::unique_ptr<vk::raii::Queue>          m_VkGeneralQueue  = nullptr;
        std::unique_ptr<vk::raii::Queue>          m_VkComputeQueue  = nullptr;
        std::unique_ptr<vk::raii::Queue>          m_VkTransferQueue = nullptr;
    };
}
#endif
