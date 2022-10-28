#include <iostream>
#include <vulkan/vulkan_raii.hpp>
#include <TestLib/TestWindowManager.h>
#include <TestLib/TestWindow.h>
#include <TestLib/TestGraphicsVulkan.h>
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
VkBool32 VKAPI_CALL VKAPI_ATTR DebugCallback(
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

    TestLib::TestGraphicsVulkan::Manager().SetInstanceApiVersion(VK_API_VERSION_1_3);
    TestLib::TestGraphicsVulkan::Manager().SetApplicationConfig("APP", 0);
    TestLib::TestGraphicsVulkan::Manager().SetEngineConfig("ENG", 0);
    TestLib::TestGraphicsVulkan::Manager().EnableDebug(vk::DebugUtilsMessengerCreateInfoEXT()
        .setMessageType(
            vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral |
            vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation |
            vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance)
        .setMessageSeverity(
            vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose |
            vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning |
            vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo |
            vk::DebugUtilsMessageSeverityFlagBitsEXT::eError)
        .setPfnUserCallback(DebugCallback));
    TestLib::TestGraphicsVulkan::Manager().EnableSurface();
#ifdef __APPLE__
    TestLib::TestGraphicsVulkan::Manager().EnableEmulation();
#endif
    TestLib::TestGraphicsVulkan::Manager().Init();

    TestLib::TestWindow::Manager().Init();
    auto window = TestLib::TestWindow(800, 600, "title");
    window.SetPosition({ 400,400 });
    window.SetGraphicsFlags(TestLib::WindowGraphicsFlags_Vulkan);
    window.SetSizeCallback(ResizeCallback);
    window.SetCursorPosCallback(CursorCallback);
    window.Init();

    window.SetResizable(true);
    window.Show();
    {
        bool should_close = false;
        while (!should_close) {
            TestLib::TestWindow::Manager().Update();
            if (window.ShouldClose()) {
                should_close = true;
            }
        }
        
    }
    window.Hide();
    window.Free();
    TestLib::TestWindow::Manager().Free();
    TestLib::TestGraphicsVulkan::Manager().Free();
}
