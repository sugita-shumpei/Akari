#ifndef TESTLIB_TEST_GRAPHICS_VULKAN_H
#define TESTLIB_TEST_GRAPHICS_VULKAN_H
#include <vulkan/vulkan_raii.hpp>
#include <memory>
#include <vector>
#include <algorithm>
namespace TestLib {
    class TestGraphicsVulkanManager {
    private:
        TestGraphicsVulkanManager() noexcept;
    public:
        static auto GetHandle()noexcept -> TestGraphicsVulkanManager&;
        ~TestGraphicsVulkanManager() noexcept;

        TestGraphicsVulkanManager(const TestGraphicsVulkanManager&) = delete;
        TestGraphicsVulkanManager(TestGraphicsVulkanManager&&) = delete;
        TestGraphicsVulkanManager& operator=(const TestGraphicsVulkanManager&) = delete;
        TestGraphicsVulkanManager& operator=(     TestGraphicsVulkanManager&&) = delete;

        bool Init();
        void Free();

        void SetInstanceApiVersion(uint32_t version)noexcept;

        void SetApplicationConfig(const std::string& name, uint32_t version)noexcept;

        void SetEngineConfig(const std::string& name, uint32_t version)noexcept;

        bool EnableExtensions(const std::vector<std::string>& extension_names)noexcept;
        bool EnableExtension(const std::string& extension_name)noexcept;

        bool EnableLayers(const std::vector<std::string>& layer_names)noexcept;
        bool EnableLayer(const std::string& layer_name)noexcept;

        bool EnableDebug(const vk::DebugUtilsMessengerCreateInfoEXT& debug_utils)noexcept;
        bool EnableSurface() noexcept;
        bool EnableEmulation()noexcept;

        bool IsInitialized() const noexcept;
        bool IsEnabledExtension(const std::string& extension_name)const noexcept;
        bool IsEnabledLayer(const std::string& layer_name)const noexcept;
        bool IsEnabledDebug() const noexcept;
        bool IsEnabledSurface() const noexcept;
        bool IsEnabledEmulation() const noexcept;
    public:
        std::unique_ptr<vk::raii::Context>  m_VkRaiiContext = nullptr;
        std::unique_ptr<vk::raii::Instance> m_VkRaiiInstance = nullptr;
        std::unique_ptr<vk::raii::DebugUtilsMessengerEXT> m_VkRaiiDebugUtilsMessenger = nullptr;

        vk::DebugUtilsMessengerCreateInfoEXT m_DebugUtilsMessengerCreateInfo;

        bool m_IsInitialized   = false;
        bool m_IsEnabledDebug = false;
        bool m_IsEnabledSurface = false;
        bool m_IsEnabledEmulation = false;

        std::uint32_t m_InstanceApiVersion = 0;
        std::string   m_ApplicationName = {};
        std::uint32_t m_ApplicationVersion = 0;
        std::string   m_EngineName    = {};
        std::uint32_t m_EngineVersion = 0;

        std::vector<std::string> m_InstanceEnabledExtensionNames = {};
        std::vector<std::string> m_InstanceEnabledLayerNames = {};

        struct PreInitializedState {
            PreInitializedState(const vk::raii::Context& context) noexcept;
            PreInitializedState(const vk::raii::Context& context,
                const std::vector<std::string>& extensionNames,
                const std::vector<std::string>&     layerNames
            )noexcept;

            bool SupportExtensions(const std::vector<std::string>& extensions)const noexcept;
            bool SupportExtension(const std::string& extensions)const noexcept;

            bool SupportLayers(const std::vector<std::string>& extensions)const noexcept;;
            bool SupportLayer(const std::string& extensions)const noexcept;

            uint32_t instanceApiVersion = 0;
            std::vector<vk::ExtensionProperties> instanceExtensionProperties = {};
            std::vector<vk::LayerProperties> instanceLayerProperties = {};
            vk::ApplicationInfo applicationInfo = {};
            vk::InstanceCreateInfo instanceCreateInfo = {};
            vk::DebugUtilsMessengerCreateInfoEXT debugUtilsMessengerCreateInfo = {};
            std::vector<const char*> instancePEnabledExtensionNames = {};
            std::vector<const char*> instancePEnabledLayerNames = {};
        };
        std::unique_ptr<PreInitializedState> m_PreInitializedState = nullptr;
    };
    
    class TestGraphicsVulkan
    {
    public:
        static auto Manager()noexcept -> TestGraphicsVulkanManager&;
    };
}
#endif
