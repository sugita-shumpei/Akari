#ifndef AKARI_ENGINE_AKARI_WINDOW_H
#define AKARI_ENGINE_AKARI_WINDOW_H
#include <array>
#include <cstdint>
#include <string>
namespace Akari
{
    class AkariEngine;
    class AkariWindowDesc
    {
    public:
        AkariWindowDesc() noexcept; 
        ~AkariWindowDesc() noexcept;

        auto SetSize(const std::array<uint32_t, 2> &size) noexcept -> AkariWindowDesc &;
        auto GetSize() const noexcept -> const std::array<uint32_t, 2> &;

        auto SetPosition(const std::array<uint32_t, 2> &size) noexcept -> AkariWindowDesc &;
        auto GetPosition() const noexcept -> const std::array<uint32_t, 2> &;

        auto SetTitle(const std::string &title) noexcept -> AkariWindowDesc &;
        auto GetTitle() const noexcept -> const std::string &;

        auto SetResizable(bool resizable) noexcept -> AkariWindowDesc &;
        auto GetResizable() const noexcept -> bool;

        auto SetVisible(bool visible) noexcept -> AkariWindowDesc &;
        auto GetVisible() const noexcept -> bool;

        auto SetGraphicsFlags(unsigned int flags) noexcept -> AkariWindowDesc &;
        auto GetGraphicsFlags() const noexcept -> unsigned int;

        auto SetUserPointer(void *pUserPointer) noexcept -> AkariWindowDesc &;
        auto GetUserPointer() const noexcept -> void *;

    private:
        bool m_IsResizable = false;
        bool m_IsVisible = false;
        void *m_UserPointer = nullptr;
        unsigned int m_GraphicsFlags = 0;
        std::string m_Title = "";
        std::array<uint32_t, 2> m_Size = {};
        std::array<uint32_t, 2> m_Position = {};
    };
    class AkariWindow
    {
        friend class AkariEngine;
        AkariWindow(AkariEngine& engine, const AkariWindowDesc& desc, void* handle) noexcept;
    public:
        static auto Handle2Window(void* handle)->AkariWindow*;

        static auto New(AkariEngine& engine, const AkariWindowDesc& desc)->AkariWindow*;
        virtual ~AkariWindow() noexcept;

        void Show() noexcept;
        void Hide() noexcept;

        auto GetSize() const noexcept -> const std::array<uint32_t, 2> &;
        auto GetPosition() const noexcept -> const std::array<uint32_t, 2> &;
        auto GetFramebufferSize() const noexcept -> const std::array<uint32_t, 2> &;
        auto GetGraphicsFlags()const noexcept -> unsigned int;
        auto GetNativeHandle()const noexcept -> void*;
        auto GetTitle() const noexcept -> const std::string&;
        bool IsResizable()const noexcept { return m_IsResizable; }
        bool IsVisible()const noexcept { return m_IsVisible; }
        bool IsMinimized()const noexcept { return m_IsMinimized; }
        bool IsFocused()const noexcept { return m_IsFocused; }
        void RequestClose()noexcept {
            m_ShouldClose = true;
        }
        bool ShouldClose()const noexcept {
            return m_ShouldClose;
        }
    private:
        void Internal_SetSize(const std::array<uint32_t, 2>& size)noexcept {
            m_Size = size;
        }
        void Internal_SetFramebufferSize(const std::array<uint32_t, 2>& size)noexcept {
            m_FramebufferSize = size;
        }
        void Internal_SetPosition(const std::array<uint32_t, 2>& position)noexcept {
            m_Position = position;
        }
        void Internal_SetMinimized(bool isMinimized)noexcept {
            m_IsMinimized = isMinimized;
        }
        void Internal_SetFocused(bool isFocused) noexcept {
            m_IsFocused = isFocused;
        }
        void Internal_SetWindowID(unsigned int windowID)noexcept {
            m_WindowID = windowID;
        }
        void Internal_Destroy()noexcept;
    private:
        AkariEngine* m_Engine;
        void *m_Handle;
        void *m_UserPointer;
        bool m_IsResizable;
        bool m_IsVisible;
        bool m_IsMinimized;
        bool m_IsFocused;
        bool m_ShouldClose;
        unsigned int m_GraphicsFlags;
        unsigned int m_WindowID;
        std::string m_Title;
        std::array<uint32_t, 2> m_Size;
        std::array<uint32_t, 2> m_Position;
        std::array<uint32_t, 2> m_FramebufferSize;
    };

}
#endif
