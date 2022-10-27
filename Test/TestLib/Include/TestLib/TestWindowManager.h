#ifndef TESTLIB_TEST_WINDOW_MANAGER_H
#define TESTLIB_TEST_WINDOW_MANAGER_H
#include <array>
#include <mutex>
namespace TestLib
{
	class TestWindow;
	class TestWindowManager
	{
	private:
		TestWindowManager()noexcept;
	public:
		static auto GetHandle() noexcept ->TestWindowManager&;
		virtual ~TestWindowManager() noexcept;

		bool Init();
		void Free();
		void Update();

		bool IsInitialized() const noexcept;

		auto GetFocusWindow()const noexcept -> TestWindow*;
	private:
		void SetFocusWindow(TestWindow* window)noexcept;
	private:
		TestWindow* m_FocusWindow = nullptr;
		bool m_IsInitialized  = false;
	};
}
#endif
