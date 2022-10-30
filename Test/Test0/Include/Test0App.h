#include <TestLib/TestApp.h>
#include <TestLib/TestGraphicsVulkan.h>
#include <iostream>
namespace Test0
{
	class Test0App : public TestLib::TestApp
	{
	public:
		Test0App(int width, int height, const std::string &title) noexcept : TestLib::TestApp(width, height, title) {}
		virtual ~Test0App() noexcept {}

	protected:
		virtual void RenderFrame() {}
		virtual void OnInitWindowMangaer() override
		{
		}
		virtual void OnInitWindow() override
		{
			GetWindow()->SetPosition({400, 400});
			GetWindow()->SetGraphicsFlags(TestLib::WindowGraphicsFlags_Vulkan);
			GetWindow()->SetSizeCallback(ResizeCallback);
			GetWindow()->SetCursorPosCallback(CursorCallback);
			GetWindow()->Init();
		}
		virtual bool InitGraphics() override
		{
			bool res = InitGraphicsVulkanInstance();
			if (!res)
			{
				return false;
			}
			res = InitGraphicsVulkanDevice();
			if (!res)
			{
				TestLib::TestGraphicsVulkan::Instance().Free();
				return false;
			}
			return true;
		}
		virtual void FreeGraphics() override
		{
			m_Device.reset();
			auto &instance = TestLib::TestGraphicsVulkan::Instance();
			instance.Free();
		}
		virtual void OnBegLoop() override
		{
			GetWindow()->SetResizable(true);
			GetWindow()->Show();
		}
		virtual void OnEndLoop() override
		{
			GetWindow()->Hide();
		}

	private:
		bool InitGraphicsVulkanInstance()
		{
			bool res = false;
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
			res = instance.Init();
			return res;
		}
		bool InitGraphicsVulkanDevice()
		{
			bool res = false;
			auto device = std::unique_ptr<TestLib::TestGraphicsVulkanDevice>(TestLib::TestGraphicsVulkan::Instance().CreateDevice(0));
			device->EnableAsyncComputeQueue();
			device->EnableAsyncTransferQueue();
			device->EnableSwapchain();
			device->EnableDedicatedAllocation();
			device->EnableGeometryShader();
			device->EnableTesselationShader();
			device->EnableFeatures(vk::PhysicalDeviceVulkan12Features().setDescriptorBindingVariableDescriptorCount(VK_TRUE));
			device->EnableRayTracing();
			device->EnableDynamicRendering();
			res = device->Init();
			if (!res)
			{
				return false;
			}
			m_Device = std::move(device);
			return true;
		}

	private:
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
		static VkBool32 VKAPI_CALL VKAPI_ATTR DebugCallback(
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
		std::unique_ptr<TestLib::TestGraphicsVulkanDevice> m_Device = nullptr;
	};
}