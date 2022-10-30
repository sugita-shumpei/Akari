#ifndef TESTLIB_TEST_APP_H
#define TESTLIB_TEST_APP_H
#include <TestLib/TestWindow.h>
#include <TestLib/TestWindowManager.h>
namespace TestLib
{
    class TestApp
    {
    public:
        TestApp(int width, int height, const std::string &title) noexcept
            : m_Window{new TestLib::TestWindow(width, height, title)} {}
        virtual ~TestApp() noexcept
        {
            m_Window.reset();
        }

        bool Init()
        {
            if (m_IsInitialized)
            {
                return true;
            }
            bool res = false;
            OnInitWindowMangaer();
            res = m_Window->Manager().Init();
            if (!res)
            {
                return false;
            }
            OnInitWindow();
            res = m_Window->Init();
            if (!res)
            {
                m_Window->Manager().Free();
                return false;
            }
            res = InitGraphics();
            if (!res)
            {
                m_Window->Free();
                m_Window->Manager().Free();
                return false;
            }
            m_IsInitialized = false;
            return true;
        }
        void Free()
        {
            if (!m_IsInitialized)
            {
                return;
            }
            FreeGraphics();
            m_Window->Free();
            m_Window->Manager().Free();
            m_IsInitialized = false;
        }
        void Loop()
        {
            OnBegLoop();
            while (!m_Window->ShouldClose())
            {
                this->RenderFrame();
                m_Window->Manager().Update();
            }
            OnEndLoop();
        }

        bool IsInitialized() const noexcept { return m_IsInitialized; }

        auto GetWindow() const noexcept -> TestLib::TestWindow * { return m_Window.get(); }

    protected:
        virtual void RenderFrame() {}
        virtual void OnInitWindowMangaer() {}
        virtual void OnInitWindow() {}
        virtual bool InitGraphics() { return true; }
        virtual void FreeGraphics() {}
        virtual void OnBegLoop() {}
        virtual void OnEndLoop() {}

    private:
        bool m_IsInitialized = false;
        std::unique_ptr<TestLib::TestWindow> m_Window = nullptr;
    };
}
#endif
