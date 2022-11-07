#ifndef AKARI_ENGINE_AKARI_ENGINE_H
#define AKARI_ENGINE_AKARI_ENGINE_H
#include <unordered_map>
namespace Akari {
	class AkariWindow;
	class AkariEngine {
		friend class AkariWindow;
	public:
		AkariEngine() noexcept;
		virtual ~AkariEngine() noexcept;

		virtual bool Init() noexcept;
		virtual void Free() noexcept;
		virtual void Loop() noexcept;

		bool IsInitialized()const noexcept;
	private:
		bool IsAllWindowClosed()const noexcept;
		void ProcessEvents()noexcept;
	private:
		void Internal_SetWindow(AkariWindow* window)noexcept;
		void Internal_RemoveWindow(unsigned int windowID)noexcept;
	private:
		bool m_IsInitialized;
		AkariWindow* m_FocusWindow;
		std::unordered_map<unsigned int, AkariWindow*> m_Windows;
		unsigned int m_NextWindowID;
	};
}
#endif
