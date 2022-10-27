#ifndef TESTLIB_TEST_WINDOW_H
#define TESTLIB_TEST_WINDOW_H
#include <string>
#include <array>
#include <unordered_map>
#include <mutex>
namespace TestLib
{
	enum WindowGraphicsFlags {
		WindowGraphicsFlags_Unknown = 0,
		WindowGraphicsFlags_OpenGL  = 1,
		WindowGraphicsFlags_Vulkan  = 2,
		WindowGraphicsFlags_Metal   = 4,
	};
	enum WindowGraphicsOpenGLProfileFlags {
		WindowGraphicsOpenGLProfileFlags_Core = 0,
		WindowGraphicsOpenGLProfileFlags_Comp = 1,
	};
    struct KeyState
    {
        bool isPressed = false;
        bool isUpdated = false;
    };
    class TestWindowManager;
	class TestWindow
	{
		friend class TestWindowManager;
	public:
		static auto Manager()noexcept -> TestWindowManager&;
		using SizeCallback      = void(*)(TestWindow*,    int,    int);
		using CursorPosCallback = void(*)(TestWindow*, double, double);
		using ScrollCallback    = void(*)(TestWindow*, double, double);
	public:
		static auto Handle2Window(void* handle)noexcept ->TestWindow*;

		TestWindow(int width, int height, const std::string& title) noexcept;
		virtual ~TestWindow() noexcept;

		bool Init();
		void Free();

		void Show();
		void Hide();

		auto GetSize()const noexcept -> const std::array<int, 2>&;
		void SetSize(const std::array<int, 2>& size);

		auto GetPosition()const noexcept -> const std::array<int, 2>&;
		void SetPosition(const std::array<int, 2>& pos);

		auto GetFramebufferSize()const noexcept -> const std::array<int, 2>&;

		auto GetCursorPosition()const noexcept -> const std::array<double, 2>&;

		void SetTitle(const std::string& title);
		auto GetTitle()const noexcept -> const std::string&;

		bool IsInitialized()const noexcept;

		bool IsResizable()const noexcept;
		bool IsVisible()const noexcept;

		void SetVisible(bool visible);
		void SetResizable(bool resizable);
		/*Graphics*/
		void SetGraphicsFlags(WindowGraphicsFlags graphicsFlags)noexcept;
		auto GetGraphicsFlags()const noexcept->WindowGraphicsFlags;

		void SetGraphicsGLMajorVersion(unsigned int majorVersion)noexcept;
		auto GetGraphicsGLMajorVersion()const noexcept-> unsigned int;

		void SetGraphicsGLMinorVersion(unsigned int minorVersion)noexcept;
		auto GetGraphicsGLMinorVersion()const noexcept-> unsigned int;

		void SetGraphicsGLProfile(WindowGraphicsOpenGLProfileFlags profile)noexcept;
		auto GetGraphicsGLProfile()const noexcept->WindowGraphicsOpenGLProfileFlags;

		void SetGraphicsGLForwardCompat(bool enableForwardCompat)noexcept;
		bool GetGraphicsGLForwardCompat()const noexcept;

		/*Thread Unsafe*/
		void SetUserData(const std::string& key, void* value) noexcept;
		auto GetUserData(const std::string& key)const noexcept ->void*;

		bool ShouldClose()const noexcept;
		/*Thread Unsafe*/
		void RequestClose()noexcept;

		void SwapBuffers();
		/*Callback*/
		void SetSizeCallback(SizeCallback callback)noexcept;
		auto GetSizeCallback()const noexcept -> SizeCallback;

		void SetCursorPosCallback(CursorPosCallback callback)noexcept;
		auto GetCursorPosCallback()const noexcept -> CursorPosCallback;

		void SetScrollCallback(ScrollCallback callback)noexcept;
		auto GetScrollCallback()const noexcept -> ScrollCallback;
	private:
		static void Def_SizeCallback(TestWindow*, int, int) {}
		static void Def_CursorPosCallback(TestWindow*, double, double) {}
		static void Def_ScrollCallback(TestWindow*, double, double) {}

		void Impl_SetSize(const std::array<int, 2>& size)noexcept;
		void Impl_SetFramebufferSize(const std::array<int, 2>& size)noexcept;
		void Impl_SetPosition(const std::array<int, 2>& position)noexcept;
		void Impl_SetScrollOffset(const std::array<double, 2>& scroll_offsets) noexcept;
		void Impl_SetAbsCursorPosition(const std::array<int, 2>& absCursorPos)noexcept;
		auto Impl_GetAbsCursorPosition()const noexcept -> const std::array<int, 2>&;
		void Impl_SetRelCursorPosition(const std::array<double , 2 > &relCursorPos)noexcept;
	private:
		void* m_Handle = nullptr;
		void* m_ContextHandle = nullptr;

		bool m_IsInitialized = false;
		bool m_IsVisible   = false;
		bool m_IsResizable = false;
		bool m_ShouldClose = false;

		WindowGraphicsFlags m_GraphicsFlags = TestLib::WindowGraphicsFlags::WindowGraphicsFlags_Unknown;
		unsigned int m_GraphicsGLMajorVersion = 0;
		unsigned int m_GraphicsGLMinorVersion = 0;
		WindowGraphicsOpenGLProfileFlags m_GraphicsGLProfile = TestLib::WindowGraphicsOpenGLProfileFlags_Core;
		bool m_GraphicsGLForwardCompat = false;

		std::string m_Title = "";
		std::array<int, 2> m_Size = {};
		std::array<int, 2> m_FramebufferSize = {};
		std::array<int, 2> m_Position = {};
		std::array<double, 2> m_RelCursorPositions = {};
		std::array<int, 2> m_AbsCursorPositions = {};
		std::array<double, 2> m_ScrollOffsets = {};
		std::unordered_map<std::string, void*> m_UserData = {};
        std::unordered_map<std::string, KeyState> m_KeyStates = {};

		SizeCallback m_SizeCallback = Def_SizeCallback;
		CursorPosCallback m_CursorPosCallback = Def_CursorPosCallback;
		ScrollCallback m_ScrollCallback = Def_ScrollCallback;
	};
}
#endif
