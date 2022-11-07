#ifndef AKARI_ENGINE_AKARI_UTILITIY_H
#define AKARI_ENGINE_AKARI_UTILITIY_H
#include <iostream>
#include <typeinfo>
#include <cassert>
#include <memory>
#ifndef NDEBUG
#define AKARI_DEBUG_ASSERT(EXPR) do{ auto akari_engine_debug_assert_tmp_result = EXPR; assert(akari_engine_debug_assert_tmp_result); }while(0)
#else
#define AKARI_DEBUG_ASSERT(EXPR)  do{ (void)EXPR; }while(0)
#endif
namespace Akari {
	enum AkariGraphicsFlags: unsigned int{
		AkariGraphicsFlagsUnknown = 0,
		AkariGraphicsFlagsOpenGL  = 1,
		AkariGraphicsFlagsVulkan  = 2,
		AkariGraphicsFlagsDirectX = 4,
		AkariGraphicsFlagsMetal   = 8,
	};

	class AkariCopyableDynamicStorage {
		using unique_void_ptr = std::unique_ptr<void, void(*)(void*)>;
		using delete_func = void(*)(void*);
		using  clone_func = auto(*)(void*)->unique_void_ptr;
		
		template<typename T>
		struct func_impl {
			static void delete_callback(void* p) { 
				if (!p) { return; }
				//std::cout << "delete: " << typeid(T).name() << std::endl;
				auto realP = static_cast<T*>(p);
				delete realP;
				return; 
			}
			static auto clone_callback(void* p)->unique_void_ptr {
				//std::cout << "delete: void" <<std::endl;
				if (!p) { return unique_void_ptr(nullptr, func_impl<void>::delete_callback); }
				auto realP = static_cast<T*>(p);
				return unique_void_ptr(new T(*realP), delete_callback);
			}
		};
		template<>
		struct func_impl<void> {
			static void delete_callback(void*) { return; }
			static auto clone_callback(void*)->unique_void_ptr { return unique_void_ptr(nullptr, delete_callback); }
		};
	public:
		AkariCopyableDynamicStorage(nullptr_t = nullptr) noexcept :m_Data{ nullptr, func_impl<void>::delete_callback }, m_CloneFunc{ func_impl<void>::clone_callback } {}
		AkariCopyableDynamicStorage& operator=(nullptr_t)noexcept {
			m_Data = std::unique_ptr<void*, void(*)(void*)>(nullptr, func_impl<void>::delete_callback);
			m_CloneFunc = func_impl<void>::clone_callback;
		}

		AkariCopyableDynamicStorage(const AkariCopyableDynamicStorage& storage)noexcept 
			:m_Data{std::move(storage.m_CloneFunc(storage.m_Data.get()))},
			 m_CloneFunc{ storage.m_CloneFunc }{}
		AkariCopyableDynamicStorage& operator=(const AkariCopyableDynamicStorage& storage)noexcept
		{
			if (this != &storage) {
				m_Data = std::move(storage.m_CloneFunc(storage.m_Data.get()));
				m_CloneFunc = storage.m_CloneFunc;
			}
			return *this;
		}

		AkariCopyableDynamicStorage(AkariCopyableDynamicStorage&& storage)noexcept
			:m_Data{ std::move(storage.m_Data) },
			 m_CloneFunc{ storage.m_CloneFunc } {}
		AkariCopyableDynamicStorage& operator=(AkariCopyableDynamicStorage&& storage)noexcept
		{
			if (this != &storage) {
				m_Data = std::move(storage.m_Data);
				m_CloneFunc = storage.m_CloneFunc;
			}
			return *this;
		}

		template<typename T>
		AkariCopyableDynamicStorage(T* ptr)noexcept :m_Data(func_impl<T>::clone_callback(ptr)), m_CloneFunc(ptr?func_impl<T>::clone_callback:func_impl<void>::clone_callback) {}

		template<typename T>
		AkariCopyableDynamicStorage& operator=(T* ptr)noexcept {
			m_Data = func_impl<T>::clone_callback(ptr);
			m_CloneFunc = ptr ? func_impl<T>::clone_callback : func_impl<void>::clone_callback;
			return *this;
		}

		bool operator!()const noexcept {
			return m_Data == nullptr;
		}

		template<typename T, bool is_not_void = !std::is_same_v<T,void>>
		operator T* () noexcept {
			if (m_CloneFunc == func_impl<T>::clone_callback) {
				return static_cast<T*>(m_Data.get());
			}
			else {
				return nullptr;
			}
		}

		template<typename T, bool is_not_void = !std::is_same_v<T, void>>
		operator const T* () const noexcept {
			if (m_CloneFunc == func_impl<T>::clone_callback) {
				return static_cast<T*>(m_Data.get());
			}
			else {
				return nullptr;
			}
		}

		operator void* ()noexcept {
			return m_Data.get();
		}

		operator const void* ()const noexcept {
			return m_Data.get();
		}
	private:
		unique_void_ptr m_Data;
		clone_func m_CloneFunc;
	};

	class AkariMoveOnlyDynamicStorage {
		using unique_void_ptr = std::unique_ptr<void, void(*)(void*)>;
		using delete_func = void(*)(void*);

		template<typename T>
		struct func_impl {
			static void delete_callback(void* p) {
				if (!p) { return; }
				//std::cout << "delete: " << typeid(T).name() << std::endl;
				auto realP = static_cast<T*>(p);
				delete realP;
				return;
			}
		};
		template<>
		struct func_impl<void> {
			static void delete_callback(void*) {
				//std::cout << "delete: void" << std::endl;
				return; }
		};
	public:
		AkariMoveOnlyDynamicStorage(nullptr_t = nullptr) noexcept :m_Data{ nullptr, func_impl<void>::delete_callback } {}
		AkariMoveOnlyDynamicStorage& operator=(nullptr_t)noexcept {
			m_Data = std::unique_ptr<void*, delete_func>(nullptr, func_impl<void>::delete_callback);
			return *this;
		}

		AkariMoveOnlyDynamicStorage(AkariMoveOnlyDynamicStorage&& storage)noexcept
			:m_Data{ std::move(storage.m_Data) } {}
		AkariMoveOnlyDynamicStorage& operator=(AkariMoveOnlyDynamicStorage&& storage)noexcept
		{
			if (this != &storage) {
				m_Data = std::move(storage.m_Data);
			}
			return *this;
		}

		template<typename T>
		AkariMoveOnlyDynamicStorage(T* ptr)noexcept :m_Data(ptr, ptr?func_impl<T>::delete_callback:func_impl<void>::delete_callback){}

		template<typename T>
		AkariMoveOnlyDynamicStorage& operator=(T* ptr)noexcept {
			m_Data = unique_void_ptr(ptr, ptr ? func_impl<T>::delete_callback : func_impl<void>::delete_callback);
			return *this;
		}

		bool operator!()const noexcept {
			return m_Data == nullptr;
		}

		template<typename T, bool is_not_void = !std::is_same_v<T, void>>
		operator T* () noexcept {
			if (m_Data.get_deleter() == func_impl<T>::delete_callback) {
				return static_cast<T*>(m_Data.get());
			}
			else {
				return nullptr;
			}
		}

		template<typename T, bool is_not_void = !std::is_same_v<T, void>>
		operator const T* () const noexcept {
			if (m_Data.get_deleter() == func_impl<T>::delete_callback) {
				return static_cast<T*>(m_Data.get());
			}
			else {
				return nullptr;
			}
		}

		operator void* ()noexcept {
			return m_Data.get();
		}

		operator const void* ()const noexcept {
			return m_Data.get();
		}
	private:
		unique_void_ptr m_Data;
	};

}
#endif
