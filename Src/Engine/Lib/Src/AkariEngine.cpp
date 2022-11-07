#include <Akari/Engine/AkariEngine.h>
#include <Akari/Engine/AkariWindow.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <iostream>
#include <cassert>
Akari::AkariEngine::AkariEngine() noexcept
{
    m_IsInitialized = false;
    m_NextWindowID = 0;
    m_Windows = {};
    m_FocusWindow = nullptr;
}

Akari::AkariEngine::~AkariEngine() noexcept
{
    assert(!m_IsInitialized);
}

bool Akari::AkariEngine::Init() noexcept
{
    if (m_IsInitialized) { return true; }
    m_IsInitialized = (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_TIMER)==0);
    return m_IsInitialized;
}

void Akari::AkariEngine::Free() noexcept
{
    if (!m_IsInitialized) { return; }
    m_FocusWindow = nullptr;
    for (auto& [windowID, window] : m_Windows) {
        window->Internal_Destroy();
    }
    SDL_Quit();
    m_IsInitialized = false;
}

void Akari::AkariEngine::Loop()noexcept {
    while (!IsAllWindowClosed()) {
        ProcessEvents();
    }
}

bool Akari::AkariEngine::IsAllWindowClosed()const noexcept {
    bool isAllClosed = true;
    for (auto& [id, window] : m_Windows) {
        if (!window->IsVisible()) {
            continue;
        }
        if (!window->ShouldClose()) {
            isAllClosed = false;
        }
    }
    return isAllClosed;
}
void Akari::AkariEngine::ProcessEvents()noexcept {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            std::cerr << "Quit!\n";
            break;
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_MINIMIZED) {
                std::cerr << "Minimized!\n";
                auto window = AkariWindow::Handle2Window(SDL_GetWindowFromID(event.window.windowID));
                window->Internal_SetMinimized(true);
                break;

            }
            if (event.window.event == SDL_WINDOWEVENT_MAXIMIZED) {
                std::cerr << "Maximized!\n";
                break;
            }
            if (event.window.event == SDL_WINDOWEVENT_RESTORED) {
                std::cerr << "Restored!\n";
                auto window = AkariWindow::Handle2Window(SDL_GetWindowFromID(event.window.windowID));
                window->Internal_SetMinimized(false);
                break;
            }
            if (event.window.event == SDL_WINDOWEVENT_ENTER) {
                std::cerr << "Enter!\n";
                auto window = AkariWindow::Handle2Window(SDL_GetWindowFromID(event.window.windowID));
                window->Internal_SetFocused(true);
                m_FocusWindow = window;
                break;
            }
            if (event.window.event == SDL_WINDOWEVENT_LEAVE) {
                std::cerr << "Leave!\n";
                auto window = AkariWindow::Handle2Window(SDL_GetWindowFromID(event.window.windowID));
                window->Internal_SetFocused(false);
                m_FocusWindow = nullptr;
                break;
            }
            if (event.window.event == SDL_WINDOWEVENT_MOVED) {
                std::cerr << "Moved!\n";
                auto window = AkariWindow::Handle2Window(SDL_GetWindowFromID(event.window.windowID));
                auto pos = window->GetPosition();
                auto x = event.window.data1;
                auto y = event.window.data2;
                if ((pos[0] != x) || (pos[1] != y)) {
                    window->Internal_SetPosition({ static_cast<uint32_t>(x),static_cast<uint32_t>(y) });
                }
                break;
            }
            if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                std::cerr << "Resized!\n";
                auto window = AkariWindow::Handle2Window(SDL_GetWindowFromID(event.window.windowID));
                auto size = window->GetSize();
                auto wid = event.window.data1;
                auto hei = event.window.data2;
                if ((size[0] != wid) || (size[1] != hei)) {
                    window->Internal_SetSize({ static_cast<uint32_t>(wid),static_cast<uint32_t>(hei) });
                    int fbWid = wid;
                    int fbHei = hei;
                    auto flags = window->GetGraphicsFlags();
                    if (flags & SDL_WINDOW_OPENGL) {
                        SDL_GL_GetDrawableSize(static_cast<SDL_Window*>(window->GetNativeHandle()), &fbWid, &fbHei);
                    }
                    else if (flags & SDL_WINDOW_VULKAN)
                    {
                        SDL_Vulkan_GetDrawableSize(static_cast<SDL_Window*>(window->GetNativeHandle()), &fbWid, &fbHei);

                    }
                    else if (flags & SDL_WINDOW_METAL) {
                        SDL_Metal_GetDrawableSize(static_cast<SDL_Window*>(window->GetNativeHandle()), &fbWid, &fbHei);
                    }
                    window->Internal_SetFramebufferSize({ static_cast<uint32_t>(fbWid),static_cast<uint32_t>(fbHei) });
                }
                break;
            }
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                auto window = AkariWindow::Handle2Window(SDL_GetWindowFromID(event.window.windowID));
                std::cerr << "Closed!\n";
                if (window) {
                    window->RequestClose();
                    window->Hide();
                }
                break;
            }
            break;

        default:
            break;
        }

    }
}

void Akari::AkariEngine::Internal_SetWindow(AkariWindow* window)noexcept
{
    m_Windows[m_NextWindowID] = window;
    window->Internal_SetWindowID(m_NextWindowID);
    m_NextWindowID++;
}

void Akari::AkariEngine::Internal_RemoveWindow(unsigned int windowID)noexcept
{
    m_Windows.erase(windowID);
}

bool Akari::AkariEngine::IsInitialized()const noexcept {
    return m_IsInitialized;
}
