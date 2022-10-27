#include <TestLib/TestWindowManager.h>
#include <TestLib/TestWindow.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#undef main
auto TestLib::TestWindowManager::GetHandle() noexcept -> TestWindowManager&
{
	// TODO: return
	static TestWindowManager manager;
	return manager;
}
TestLib::TestWindowManager::TestWindowManager() noexcept :m_IsInitialized{ false } {}
TestLib::TestWindowManager::~TestWindowManager() noexcept {}
bool TestLib::TestWindowManager::Init() {
	if (m_IsInitialized) { return true; }
	if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER) == 0)
	{
		m_IsInitialized = true;
	}
	return m_IsInitialized;
}

void TestLib::TestWindowManager::Free() {
	if (!m_IsInitialized) {
		return;
	}
	SDL_assert(m_FocusWindow == nullptr);
	SDL_Quit();
	m_IsInitialized = false;
}

void TestLib::TestWindowManager::Update()
{
	SDL_Event event = {};
	while (SDL_PollEvent(&event))
	{
		if ( event.type == SDL_WINDOWEVENT) {
			auto window_handle = SDL_GetWindowFromID(event.window.windowID);
			if (!window_handle) { break; }
			auto window = TestWindow::Handle2Window(window_handle);
			if (!window) { break; }
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				window->RequestClose();
                if (m_FocusWindow==window)
                {
                    m_FocusWindow = nullptr;
                }
				break;
			}
			if (event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				int newWid = event.window.data1;
				int newHei = event.window.data2;
				int fbWid  = newWid;
				int fbHei  = newHei;
				auto graphicsFlags = window->GetGraphicsFlags();
				if (graphicsFlags & TestLib::WindowGraphicsFlags::WindowGraphicsFlags_OpenGL)
				{
					SDL_GL_GetDrawableSize(window_handle, &fbWid, &fbHei);
				}
				else if (graphicsFlags & TestLib::WindowGraphicsFlags::WindowGraphicsFlags_Vulkan)
				{
					SDL_Vulkan_GetDrawableSize(window_handle, &fbWid, &fbHei);
				}
				window->Impl_SetFramebufferSize({ fbWid,fbHei });
				window->GetSizeCallback()(window, newWid, newHei);
				window->Impl_SetSize({ newWid, newHei });
				break;
			}
			if (event.window.event == SDL_WINDOWEVENT_ENTER)
			{
				m_FocusWindow = window;
				break;
			}
			if (event.window.event == SDL_WINDOWEVENT_LEAVE)
			{
				m_FocusWindow = nullptr;
				break;
			}
			if (event.window.event == SDL_WINDOWEVENT_MOVED)
			{
				int newPosX = event.window.data1;
				int newPosY = event.window.data2;
				window->Impl_SetPosition({ newPosX,newPosY });
				break;
			}
			break;
		}
		if ( event.type == SDL_MOUSEMOTION) {
			auto window_handle = SDL_GetWindowFromID(event.motion.windowID);;
			if (!window_handle) { break; }
			auto window = TestWindow::Handle2Window(window_handle);
			if (!window) { break; }
			if (window != m_FocusWindow) { break; }
			auto abs_cursor_pos = window->Impl_GetAbsCursorPosition();
			if ((abs_cursor_pos[0] != event.motion.x) ||
				(abs_cursor_pos[1] != event.motion.y)) {
				auto window_size = window->GetSize();
				double rel_cursor_pos_x = static_cast<double>(event.motion.x) / static_cast<double>(window_size[0]);
				double rel_cursor_pos_y = static_cast<double>(event.motion.y) / static_cast<double>(window_size[1]);
				window->GetCursorPosCallback()(window, rel_cursor_pos_x, rel_cursor_pos_y);
				window->Impl_SetAbsCursorPosition({ event.motion.x , event.motion.y });
				window->Impl_SetRelCursorPosition({ rel_cursor_pos_x,rel_cursor_pos_y });
				break;
			}
		}
        if (event.type==SDL_MOUSEWHEEL){
            auto window_handle = SDL_GetWindowFromID(event.wheel.windowID);;
            if (!window_handle) { break; }
            auto window = TestWindow::Handle2Window(window_handle);
            if (!window) { break; }
            if (window!=m_FocusWindow){
                break;
            }
            window->GetScrollCallback()(window,event.wheel.preciseX,event.wheel.preciseY);
            window->Impl_SetScrollOffset({event.wheel.preciseX,event.wheel.preciseY});
            break;
        }
		if ((event.type == SDL_KEYDOWN) || (event.type == SDL_KEYUP)) {
			break;
		}
	}
}

bool TestLib::TestWindowManager::IsInitialized() const noexcept {
	return m_IsInitialized;
}

auto TestLib::TestWindowManager::GetFocusWindow() const noexcept -> TestWindow* { return m_FocusWindow; }

void TestLib::TestWindowManager::SetFocusWindow(TestWindow* window) noexcept {
	m_FocusWindow = window;
}
