#include <TestLib/TestWindow.h>
#include <TestLib/TestWindowManager.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

auto TestLib::TestWindow::Manager() noexcept -> TestLib::TestWindowManager&
{
	// TODO: return ステートメントをここに挿入します
	return TestLib::TestWindowManager::GetHandle();
}

TestLib::TestWindow::TestWindow(int width, int height, const std::string& title) noexcept
	:m_Size{ width,height }, m_Title{title} {}

auto TestLib::TestWindow::Handle2Window(void* handle) noexcept -> TestWindow*
{
	if (!handle) { return nullptr; }
	return static_cast<TestWindow*>(SDL_GetWindowData(static_cast<SDL_Window*>(handle),"window"));
}

TestLib::TestWindow::~TestWindow() noexcept {}

 bool TestLib::TestWindow::Init() {
	 if (m_IsInitialized) { return true; }
	 if (!Manager().IsInitialized()) { return false; }
	 unsigned int flags = SDL_WINDOW_RESIZABLE;
	 if (m_GraphicsFlags& WindowGraphicsFlags_OpenGL)
	 {
		 flags |= SDL_WINDOW_OPENGL;
	 }
	 if (m_GraphicsFlags & WindowGraphicsFlags_Vulkan)
	 {
		 flags |= SDL_WINDOW_VULKAN;
	 }
	 if (m_GraphicsFlags & WindowGraphicsFlags_Metal)
	 {
		 flags |= SDL_WINDOW_METAL;
	 }
	 if (!m_IsVisible)
	 {
		 flags |= SDL_WINDOW_HIDDEN;
	 }
	 SDL_Window* window = nullptr;
	 if (m_GraphicsFlags & WindowGraphicsFlags_OpenGL)
	 {
		 bool shouldSearchValidVersion = m_GraphicsGLMajorVersion == 0;
		 if (m_GraphicsGLProfile == TestLib::WindowGraphicsOpenGLProfileFlags_Core)
		 {
			 SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		 }
		 if (m_GraphicsGLProfile == TestLib::WindowGraphicsOpenGLProfileFlags_Comp)
		 {
			 SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
		 }
		 if (m_GraphicsGLForwardCompat)
		 {
			 SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
		 }
		 if (shouldSearchValidVersion)
		 {
			 auto glVersions = std::vector<std::pair<int, int>>{
				 {4,6},{4,5},{4,4},{4,3},{4,2},{4,1},{4,0},
				 {3,3},{3,2},{3,1},{3,0},
				 {2,1},{2,0},
				 {1,5},{1,4},{1,3},{1,2},{1,1},{1,0}
			 };
			 for (auto& [major, minor] : glVersions)
			 {
				 SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
				 SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
				 window = SDL_CreateWindow(m_Title.c_str(), m_Position[0], m_Position[1], m_Size[0], m_Size[1], flags);
				 if (window){
					 m_GraphicsGLMajorVersion = major;
					 m_GraphicsGLMinorVersion = minor;
					 break;
				 }
			 }
		 }
		 else {
			 SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, m_GraphicsGLMajorVersion);
			 SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, m_GraphicsGLMinorVersion); 
			 window = SDL_CreateWindow(m_Title.c_str(), m_Position[0], m_Position[1], m_Size[0], m_Size[1], flags);
		 }
		 if (window) {
			 m_ContextHandle = SDL_GL_CreateContext(window);
		 }
		 SDL_GL_ResetAttributes();
	 }
	 else {
		 window = SDL_CreateWindow(m_Title.c_str(), m_Position[0], m_Position[1], m_Size[0], m_Size[1], flags);
	 }
	 if (!window) { return false; }
	 SDL_SetWindowResizable(window, static_cast<SDL_bool>(m_IsResizable));
	 SDL_SetWindowData(window, "window", this);
	 {
		 int fbWid, fbHei;
		 fbWid = m_Size[0];
		 fbHei = m_Size[1];
		 if (m_GraphicsFlags & WindowGraphicsFlags_OpenGL)
		 {
			 SDL_GL_GetDrawableSize(window, &fbWid, &fbHei);
		 }
		 if (m_GraphicsFlags & WindowGraphicsFlags_Vulkan)
		 {
			 SDL_Vulkan_GetDrawableSize(window, &fbWid, &fbHei);
		 }
		 m_FramebufferSize = { fbWid,fbHei };
	 }
	 m_Handle = window;
	 m_IsInitialized = true;
	 return true;
}

 void TestLib::TestWindow::Free() {
	 if (!m_IsInitialized) { return; }
	 if (m_ContextHandle) {
		 SDL_GL_DeleteContext(static_cast<SDL_GLContext>(m_ContextHandle));
		 m_ContextHandle = nullptr;
	 }
	 SDL_DestroyWindow(static_cast<SDL_Window*>(m_Handle));
	 m_Handle = nullptr;
	 m_IsInitialized = false;
}

 void TestLib::TestWindow::Show()
 {
	 if (!m_IsInitialized) { return; }
	 if (m_IsVisible) {
		 return;
	 }
	 SDL_ShowWindow(static_cast<SDL_Window*>(m_Handle));
	 m_IsVisible = true;
 }

 void TestLib::TestWindow::Hide()
 {
	 if (!m_IsInitialized) { return; }
	 if (!m_IsVisible) {
		 return;
	 }
	 SDL_HideWindow(static_cast<SDL_Window*>(m_Handle));
	 m_IsVisible = false;
 }

 auto TestLib::TestWindow::GetSize() const noexcept -> const std::array<int, 2>&
 {
	 // TODO: return ステートメントをここに挿入します
	 return m_Size;
 }

 void TestLib::TestWindow::SetSize(const std::array<int, 2>& size)
 {
	 if (m_IsInitialized)
	 {
		 if ((m_Size[0] != size[0]) && (m_Size[1] != size[1])) {
			 auto handle = static_cast<SDL_Window*>(m_Handle);
			 int fbWid = size[0];
			 int fbHei = size[1];
			 if (m_GraphicsFlags & TestLib::WindowGraphicsFlags::WindowGraphicsFlags_OpenGL)
			 {
				 SDL_GL_GetDrawableSize(handle, &fbWid, &fbHei);
			 }
			 else if (m_GraphicsFlags & TestLib::WindowGraphicsFlags::WindowGraphicsFlags_Vulkan)
			 {
				 SDL_Vulkan_GetDrawableSize(handle, &fbWid, &fbHei);
			 }
			 m_FramebufferSize = std::array<int, 2>{fbWid, fbHei};
			 m_SizeCallback(this, size[0], size[1]);
			 SDL_SetWindowSize(handle, size[0], size[1]);
		 }
	 }
	 m_Size = size;
 }

 auto TestLib::TestWindow::GetPosition() const noexcept -> const std::array<int, 2>&
 {
	 // TODO: return ステートメントをここに挿入します
	 return m_Position;
 }

 void TestLib::TestWindow::SetPosition(const std::array<int, 2>& pos)
 {
	 if (m_IsInitialized)
	 {
		 SDL_SetWindowPosition(static_cast<SDL_Window*>(m_Handle), pos[0], pos[1]);
	 }
	 m_Position = pos;
 }

 auto TestLib::TestWindow::GetFramebufferSize() const noexcept -> const std::array<int, 2>&
 {
	 // TODO: return ステートメントをここに挿入します
	 return m_FramebufferSize;
 }

 auto TestLib::TestWindow::GetCursorPosition() const noexcept -> const std::array<double, 2>&
 {
	 // TODO: return ステートメントをここに挿入します
	 return m_RelCursorPosition;
 }

 void TestLib::TestWindow::SetTitle(const std::string& title)
 {
	 if (m_IsInitialized) { 
		 SDL_SetWindowTitle(static_cast<SDL_Window*>(m_Handle), title.c_str());
	 }
	 m_Title = title;
 }

 auto TestLib::TestWindow::GetTitle() const noexcept -> const std::string&
 {
	 // TODO: return ステートメントをここに挿入します
	 return m_Title;
 }

 bool TestLib::TestWindow::IsInitialized() const noexcept { return m_IsInitialized; }

 bool TestLib::TestWindow::IsResizable() const noexcept
 {
	 return m_IsResizable;
 }

 bool TestLib::TestWindow::IsVisible() const noexcept
 {
	 return m_IsVisible;
 }

 void TestLib::TestWindow::SetVisible(bool visible)
 {

	 if (m_IsInitialized) {
		 if (m_IsVisible&&!visible)
		 {
			 SDL_HideWindow(static_cast<SDL_Window*>(m_Handle));
		 }
		 if (!m_IsVisible && visible)
		 {
			 SDL_ShowWindow(static_cast<SDL_Window*>(m_Handle));
		 }
	 }
	 m_IsVisible = visible;
 }

 void TestLib::TestWindow::SetResizable(bool resizable)
 {
	 if (m_IsInitialized) {
		 if ((m_IsResizable && !resizable)||
			(!m_IsResizable &&  resizable))
		 {
			 SDL_SetWindowResizable(static_cast<SDL_Window*>(m_Handle), static_cast<SDL_bool>(resizable));
		 }
	 }
	 m_IsResizable = resizable;
 }

 void TestLib::TestWindow::SetGraphicsFlags(WindowGraphicsFlags graphicsFlags) noexcept
 {
	 if (m_IsInitialized) { return; }
	 m_GraphicsFlags = graphicsFlags;
 }

 auto TestLib::TestWindow::GetGraphicsFlags() const noexcept -> WindowGraphicsFlags
 {
	 return m_GraphicsFlags;
 }

 void TestLib::TestWindow::SetGraphicsGLMajorVersion(unsigned int majorVersion) noexcept
 {
	 if (m_IsInitialized) { return; }
	 m_GraphicsGLMajorVersion = majorVersion;
 }

 auto TestLib::TestWindow::GetGraphicsGLMajorVersion() const noexcept -> unsigned int
 {
	 return m_GraphicsGLMajorVersion;
 }

 void TestLib::TestWindow::SetGraphicsGLMinorVersion(unsigned int minorVersion) noexcept
 {
	 if (m_IsInitialized) { return; }
	 m_GraphicsGLMinorVersion = minorVersion;
 }

 auto TestLib::TestWindow::GetGraphicsGLMinorVersion() const noexcept -> unsigned int
 {
	 return m_GraphicsGLMinorVersion;
 }

 void TestLib::TestWindow::SetGraphicsGLProfile(WindowGraphicsOpenGLProfileFlags profile) noexcept
 {
	 if (m_IsInitialized) { return; }
	 m_GraphicsGLProfile = profile;
 }

 auto TestLib::TestWindow::GetGraphicsGLProfile() const noexcept -> WindowGraphicsOpenGLProfileFlags
 {
	 return m_GraphicsGLProfile;
 }

 void TestLib::TestWindow::SetGraphicsGLForwardCompat(bool enableForwardCompat) noexcept
 {
	 if (m_IsInitialized) { return; }
	 m_GraphicsGLForwardCompat = enableForwardCompat;
 }

 bool TestLib::TestWindow::GetGraphicsGLForwardCompat() const noexcept
 {
	 return m_GraphicsGLForwardCompat;
 }

 void TestLib::TestWindow::SetUserData(const std::string& key, void* value) noexcept
 {
	 m_UserData[key] = value;
 }

 auto TestLib::TestWindow::GetUserData(const std::string& key) const noexcept -> void*
 {
	 if (m_UserData.count(key) > 0) { return m_UserData.at(key); }
	 return nullptr;
 }

 bool TestLib::TestWindow::ShouldClose() const noexcept {
	return m_ShouldClose;
}

 void TestLib::TestWindow::RequestClose() noexcept
{
	m_ShouldClose = true;
}

 void TestLib::TestWindow::SwapBuffers()
 {
	 if (!m_IsInitialized) { return; }
	 auto handle = static_cast<SDL_Window*>(m_Handle);
	 SDL_GL_SwapWindow(handle);
 }

 void TestLib::TestWindow::SetSizeCallback(SizeCallback callback) noexcept
 {
	 m_SizeCallback = callback;
 }

 auto TestLib::TestWindow::GetSizeCallback() const noexcept -> SizeCallback
 {
	 return m_SizeCallback;
 }

 void TestLib::TestWindow::SetCursorPosCallback(CursorPosCallback callback) noexcept
 {
	 m_CursorPosCallback = callback;
 }

 auto TestLib::TestWindow::GetCursorPosCallback() const noexcept -> CursorPosCallback
 {
	 return m_CursorPosCallback;
 }

 void TestLib::TestWindow::SetScrollCallback(ScrollCallback callback) noexcept
 {
	 m_ScrollCallback = callback;
 }

 auto TestLib::TestWindow::GetScrollCallback() const noexcept -> ScrollCallback
 {
	 return m_ScrollCallback;
 }

 void TestLib::TestWindow::Impl_SetSize(const std::array<int, 2>& size) noexcept
 {
	 m_Size = size;
 }

 void TestLib::TestWindow::Impl_SetFramebufferSize(const std::array<int, 2>& size) noexcept
 {
	 m_FramebufferSize = size;
 }

 void TestLib::TestWindow::Impl_SetPosition(const std::array<int, 2>& position) noexcept
 {
	 m_Position = position;
 }

 void TestLib::TestWindow::Impl_SetScrollOffset(const std::array<double, 2>& scroll_offsets) noexcept
 {
	 m_ScrollOffsets = scroll_offsets;
 }

 void TestLib::TestWindow::Impl_SetAbsCursorPosition(const std::array<int, 2>& absCursorPos) noexcept
 {
	 m_AbsCursorPosition = absCursorPos;
 }

 auto TestLib::TestWindow::Impl_GetAbsCursorPosition() const noexcept -> const std::array<int, 2>&
 {
	 // TODO: return ステートメントをここに挿入します
	 return m_AbsCursorPosition;
 }

 void TestLib::TestWindow::Impl_SetRelCursorPosition(const std::array<double, 2>& relCursorPos) noexcept
 {
	 m_RelCursorPosition;
 }
