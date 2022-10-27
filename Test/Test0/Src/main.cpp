#include <iostream>
#include <vulkan/vulkan_raii.hpp>
#include <TestLib/TestWindowManager.h>
#include <TestLib/TestWindow.h>
#include <cassert>
static void ResizeCallback(TestLib::TestWindow* window, int wid, int hei)
{
	if (!window) { 
		std::cerr << "error" << std::endl;
		return;
	}
	std::cerr << "Resize: [" << wid << "," << hei << "]\n";
}
static void CursorCallback(TestLib::TestWindow* window, double x, double y)
{
	if (!window) {
		std::cerr << "error" << std::endl;
		return;
	}
	std::cerr << "Cursor: [" << x << "," << y << "]\n";
}
static void ScrollCallback(TestLib::TestWindow* window, double x, double y)
{
    if (!window) {
        std::cerr << "error" << std::endl;
        return;
    }
    std::cerr << "Scroll: [" << x << "," << y << "]\n";
}
VKAPI_CALL VkBool32 VKAPI_ATTR DebugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT*      pCallbackData,
    void*                                            pUserData)
{
    std::cerr <<"[" << vk::to_string(static_cast<vk::DebugUtilsMessageSeverityFlagBitsEXT>(messageSeverity)) << "]";
    std::cerr <<"[" << vk::to_string(static_cast<vk::DebugUtilsMessageTypeFlagsEXT>(messageTypes)) << "] ";
    std::cerr << pCallbackData->pMessage << std::endl;
    return VK_FALSE;
}
int main(int argc, const char* argv[])
{
	TestLib::TestWindow::Manager().Init();
	auto window  = TestLib::TestWindow(800, 600, "title");
	window.SetPosition({ 400,400 });
    window.SetGraphicsFlags(TestLib::WindowGraphicsFlags_Vulkan);
	window.Init();
	window.SetSizeCallback(ResizeCallback);
	window.SetCursorPosCallback(CursorCallback);
	window.SetResizable(true);
	window.Show();
    auto vk_context = vk::raii::Context();
    auto vk_api_version = vk_context.enumerateInstanceVersion();
    auto vk_application_info = vk::ApplicationInfo()
        .setApiVersion(VK_API_VERSION_1_1);
    auto vk_instance_create_info = vk::InstanceCreateInfo().setPApplicationInfo(&vk_application_info);
    auto vk_instance_extensions = std::vector<const char*>();
    auto vk_instance_layers = std::vector<const char*>();
    auto vk_instance_extensions_supported = vk_context.enumerateInstanceExtensionProperties();
    auto vk_instance_layers_supported = vk_context.enumerateInstanceLayerProperties();
    vk_instance_extensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
#ifdef WIN32
    vk_instance_extensions.push_back("VK_KHR_win32_surface");
#endif
#ifdef __APPLE__
    vk_instance_create_info.flags |= vk::InstanceCreateFlagBits::eEnumeratePortabilityKHR;
    vk_instance_extensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
    vk_instance_extensions.push_back("VK_EXT_metal_surface");
#endif
#ifndef NDEBUG
    vk_instance_extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    vk_instance_layers.push_back("VK_LAYER_KHRONOS_validation");
    vk_instance_layers.push_back("VK_LAYER_LUNARG_api_dump");
#endif
    vk_instance_create_info.setPEnabledExtensionNames(vk_instance_layers);
    vk_instance_create_info.setPEnabledExtensionNames(vk_instance_extensions);
    auto vk_debug_utils_create_info = vk::DebugUtilsMessengerCreateInfoEXT().setMessageType(vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral|vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation|vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance)
        .setMessageSeverity(
        vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose|
        vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning|
        vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo)
        .setPfnUserCallback(DebugCallback);
    vk_instance_create_info.setPNext(&vk_debug_utils_create_info);
    {
        auto vk_instance = vk::raii::Instance(vk_context,vk_instance_create_info);
        {
            auto vk_debug = vk::raii::DebugUtilsMessengerEXT(vk_instance,vk_debug_utils_create_info);
            {
                auto vk_physical_devices =vk_instance.enumeratePhysicalDevices();
                auto vk_properties = vk_physical_devices.front().getProperties();
                
                std::cerr << vk_api_version << std::endl;
//                bool should_close = false;
//                while (!should_close) {
//                    TestLib::TestWindow::Manager().Update();
//                    if (window.ShouldClose()) {
//                        should_close = true;
//                    }
//                }
            }
            vk_debug.clear();
        }
        
    }
	window.Hide();
	window.Free();
	TestLib::TestWindow::Manager().Free();
}
