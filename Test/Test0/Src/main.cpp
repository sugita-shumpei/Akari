#include <iostream>
#include <TestLib/TestWindowManager.h>
#include <TestLib/TestWindow.h>
#include <TestLib/TestGraphicsVulkan.h>
#include <cassert>
static void ResizeCallback(TestLib::TestWindow *window, int wid, int hei)
{
    if (!window)
    {
        std::cerr << "error" << std::endl;
        return;
    }
    std::cerr << "Resize: [" << wid << "," << hei << "]\n";
}
static void CursorCallback(TestLib::TestWindow *window, double x, double y)
{
    if (!window)
    {
        std::cerr << "error" << std::endl;
        return;
    }
    std::cerr << "Cursor: [" << x << "," << y << "]\n";
}
static void ScrollCallback(TestLib::TestWindow *window, double x, double y)
{
    if (!window)
    {
        std::cerr << "error" << std::endl;
        return;
    }
    std::cerr << "Scroll: [" << x << "," << y << "]\n";
}
VkBool32 VKAPI_CALL VKAPI_ATTR DebugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
    void *pUserData)
{
    std::cerr << "[" << vk::to_string(static_cast<vk::DebugUtilsMessageSeverityFlagBitsEXT>(messageSeverity)) << "]";
    std::cerr << "[" << vk::to_string(static_cast<vk::DebugUtilsMessageTypeFlagsEXT>(messageTypes)) << "] ";
    std::cerr << pCallbackData->pMessage << std::endl;
    return VK_FALSE;
}
int main(int argc, const char *argv[])
{
    auto &instance = TestLib::TestGraphicsVulkan::Instance();
    instance.SetApplicationInfo("APP", 0);
    instance.SetEngineInfo("ENG", 0);
    instance.EnableLayers({
        "VK_LAYER_KHRONOS_validation",
        //"VK_LAYER_LUNARG_api_dump"
    });
    instance.EnableDebug(vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose | vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning | vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo | vk::DebugUtilsMessageSeverityFlagBitsEXT::eError,
                         vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral | vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation | vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance,
                         DebugCallback, nullptr);
    instance.EnableSurface();
#ifdef __APPLE__
    instance.EnableEmulation();
#endif
    instance.Init();

    auto device = std::unique_ptr<TestLib::TestGraphicsVulkanDevice>(instance.CreateDevice(0));
    device->EnableAsyncComputeQueue();
    device->EnableAsyncTransferQueue();
    device->EnableSwapchain();
    device->EnableDedicatedAllocation();
    device->EnableGeometryShader();
    device->EnableTesselationShader();
    device->EnableFeatures(vk::PhysicalDeviceVulkan12Features().setDescriptorBindingVariableDescriptorCount(VK_TRUE));
    device->EnableRaytracing();
    device->EnableDynamicRendering();
    device->Init();

    auto &window_manager = TestLib::TestWindow::Manager();
    window_manager.Init();
    auto window = TestLib::TestWindow(800, 600, "title");
    window.SetPosition({400, 400});
    window.SetGraphicsFlags(TestLib::WindowGraphicsFlags_Vulkan);
    window.SetSizeCallback(ResizeCallback);
    window.SetCursorPosCallback(CursorCallback);
    window.Init();

    window.SetResizable(true);
    window.Show();
    {
        bool should_close = false;
        while (!should_close)
        {
            window_manager.Update();
            if (window.ShouldClose())
            {
                should_close = true;
            }
        }
    }

    window.Hide();
    window.Free();
    window_manager.Free();
    device->Free();
    instance.Free();
}
