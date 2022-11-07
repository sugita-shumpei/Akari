#include <Akari/Engine/AkariWindow.h>
#include <Akari/Engine/AkariEngine.h>
#include <Akari/Engine/AkariUtility.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <vector>

Akari::AkariWindowDesc::AkariWindowDesc() noexcept {}
Akari::AkariWindowDesc::~AkariWindowDesc() noexcept {}

auto Akari::AkariWindowDesc::SetSize(const std::array<uint32_t, 2>& size) noexcept -> AkariWindowDesc&
{
    m_Size = size;
    return *this;
}

auto Akari::AkariWindowDesc::GetSize() const noexcept -> const std::array<uint32_t, 2> &
{
    return m_Size;
}

auto Akari::AkariWindowDesc::SetPosition(const std::array<uint32_t, 2> &position) noexcept -> AkariWindowDesc &
{
    m_Position = position;
    return *this;
}

auto Akari::AkariWindowDesc::GetPosition() const noexcept -> const std::array<uint32_t, 2> &
{
    return m_Position;
}

auto Akari::AkariWindowDesc::SetTitle(const std::string &title) noexcept -> AkariWindowDesc &
{
    m_Title = title;
    return *this;
}

auto Akari::AkariWindowDesc::GetTitle() const noexcept -> const std::string &
{
    return m_Title;
}

auto Akari::AkariWindowDesc::SetResizable(bool resizable) noexcept -> AkariWindowDesc &
{
    m_IsResizable = resizable;
    return *this;
}

auto Akari::AkariWindowDesc::GetResizable() const noexcept -> bool
{
    return m_IsResizable;
}

auto Akari::AkariWindowDesc::SetVisible(bool visible) noexcept -> AkariWindowDesc &
{
    m_IsVisible = visible;
    return *this;
}

auto Akari::AkariWindowDesc::GetVisible() const noexcept -> bool
{
    return m_IsVisible;
}

auto Akari::AkariWindowDesc::SetGraphicsFlags(unsigned int flags) noexcept -> AkariWindowDesc &
{
    m_GraphicsFlags = flags;
    return *this;
}

auto Akari::AkariWindowDesc::GetGraphicsFlags() const noexcept -> unsigned int
{
    return m_GraphicsFlags;
}

auto Akari::AkariWindowDesc::SetUserPointer(void *pUserPointer) noexcept -> AkariWindowDesc &
{
    m_UserPointer = pUserPointer;
    return *this;
}

auto Akari::AkariWindowDesc::GetUserPointer() const noexcept -> void *
{
    return m_UserPointer;
}
Akari::AkariWindow::AkariWindow(AkariEngine& engine, const AkariWindowDesc& desc, void* handle) noexcept
    : m_Engine(&engine),
      m_Handle(handle),
      m_UserPointer(desc.GetUserPointer()),
      m_IsResizable(desc.GetResizable()),
      m_IsVisible(desc.GetVisible()),
      m_IsMinimized{false},
      m_IsFocused{false},
      m_ShouldClose{false},
      m_GraphicsFlags(desc.GetGraphicsFlags()),
      m_Title(desc.GetTitle()),
      m_Size(desc.GetSize()),
      m_Position(desc.GetPosition()),
      m_FramebufferSize({0,0}),
      m_WindowID(0)
{
    
}

auto Akari::AkariWindow::New(AkariEngine& engine, const AkariWindowDesc& desc) -> AkariWindow*
{
    if (!engine.IsInitialized()) { return nullptr; }
    int width  = static_cast<int>(desc.GetSize()[0]);
    int height = static_cast<int>(desc.GetSize()[1]);
    int x_pos  = (desc.GetPosition()[0] == UINT32_MAX) ? SDL_WINDOWPOS_CENTERED : static_cast<int>(desc.GetPosition()[0]);
    int y_pos  = (desc.GetPosition()[1] == UINT32_MAX) ? SDL_WINDOWPOS_CENTERED : static_cast<int>(desc.GetPosition()[1]);
    bool is_opengl_supported = false;
    unsigned int flags = 0;
    if (desc.GetResizable()) {
        flags |= SDL_WINDOW_RESIZABLE;
    }
    if (!desc.GetVisible()) {
        flags |= SDL_WINDOW_HIDDEN;
    }
    if (desc.GetGraphicsFlags() & Akari::AkariGraphicsFlagsOpenGL) {
        flags |= SDL_WINDOW_OPENGL;
    }
    if (desc.GetGraphicsFlags() & Akari::AkariGraphicsFlagsVulkan) {
        flags |= SDL_WINDOW_VULKAN;
    }
    if (desc.GetGraphicsFlags() & Akari::AkariGraphicsFlagsMetal ) {
        flags |= SDL_WINDOW_METAL;
    }
    std::string title  = desc.GetTitle();
    SDL_Window* handle = nullptr;
    if (is_opengl_supported) {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS       , SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        auto gl_versions = std::vector<std::pair<int, int>>{
            {4,6},{4,5},{4,4},{4,3},{4,2},{4,1},{4,0},
            {3,3},{3,2},{3,1},{3,0},
            {2,1},{2,0},
            {1,5},{1,4},{1,3},{1,2},{1,1},{1,0}
        };
        for (auto& [ gl_major, gl_minor ]:gl_versions) {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, gl_major);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, gl_minor);
            handle = SDL_CreateWindow(title.c_str(), x_pos, y_pos, width, height, flags);
            if (handle) { break; }
        }
        SDL_GL_ResetAttributes();
        if (!handle) { return nullptr; }
    }
    else {
        handle = SDL_CreateWindow(title.c_str(), x_pos, y_pos, width, height, flags);
    }
    SDL_GetWindowPosition(handle, &x_pos, &y_pos);
    auto window = new AkariWindow(engine, desc, handle);
    window->m_Position[0] = static_cast<uint32_t>(x_pos);
    window->m_Position[1] = static_cast<uint32_t>(y_pos);
    int fbW = width;
    int fbH = height;
    if (flags & SDL_WINDOW_OPENGL) {
        SDL_GL_GetDrawableSize(handle, &fbW, &fbH);
    }else if (flags & SDL_WINDOW_VULKAN) 
    {
        SDL_Vulkan_GetDrawableSize(handle, &fbW, &fbH);

    }else if (flags & SDL_WINDOW_METAL) {
        SDL_Metal_GetDrawableSize(handle, &fbW, &fbH);
    }
    window->m_FramebufferSize[0] = static_cast<uint32_t>(fbW);
    window->m_FramebufferSize[1] = static_cast<uint32_t>(fbH);
    SDL_SetWindowData(handle, "main", window);
    engine.Internal_SetWindow(window);
    return window;
}
Akari::AkariWindow::~AkariWindow() noexcept {
    if (!m_Engine) {
        return;
    }
    m_Engine->Internal_RemoveWindow(m_WindowID);
    Internal_Destroy();
}
void Akari::AkariWindow::Internal_Destroy()noexcept
{
    if (m_Handle) {
        SDL_DestroyWindow(static_cast<SDL_Window*>(m_Handle));
        m_Handle = nullptr;
    }
    m_Engine = nullptr;
}
auto Akari::AkariWindow::GetSize() const noexcept -> const std::array<uint32_t, 2>& { return m_Size; }
auto Akari::AkariWindow::GetPosition() const noexcept -> const std::array<uint32_t, 2>& { return m_Position; }
auto Akari::AkariWindow::GetFramebufferSize() const noexcept -> const std::array<uint32_t, 2>& { return m_FramebufferSize; }
auto Akari::AkariWindow::GetTitle() const noexcept -> const std::string& { return m_Title; }
auto Akari::AkariWindow::GetGraphicsFlags()const noexcept -> unsigned int { return m_GraphicsFlags; }
auto Akari::AkariWindow::GetNativeHandle()const noexcept -> void* { return m_Handle; }

void Akari::AkariWindow::Show() noexcept {
    assert(m_Engine);
    if (m_IsVisible) {
        return;
    }
    SDL_ShowWindow(static_cast<SDL_Window*>(m_Handle));
    m_IsVisible = false;
}

void Akari::AkariWindow::Hide() noexcept {
    assert(m_Engine);
    if (!m_IsVisible) {
        return;
    }
    SDL_HideWindow(static_cast<SDL_Window*>(m_Handle));
    m_IsVisible = false;
}


auto Akari::AkariWindow::Handle2Window(void* handle)->AkariWindow*
{
    if (!handle) { return nullptr; }
    return static_cast<AkariWindow*>(SDL_GetWindowData(static_cast<SDL_Window*>(handle), "main"));
}