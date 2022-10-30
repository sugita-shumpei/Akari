#ifndef TESTLIB_TEST_GRAPHICS_VULKAN_H
#define TESTLIB_TEST_GRAPHICS_VULKAN_H
#include <TestLib/TestUtility.h>
#define VULKAN_HPP_USE_REFLECT
#include <vulkan/vulkan_raii.hpp>
#include <unordered_map>
#include <unordered_set>
#include <type_traits>
#include <string>
#include <memory>
#include <vector>
#include <array>
#include <algorithm>
namespace TestLib
{
	namespace TestGraphicsVulkanUtility
	{
		namespace Impl
		{
			template <typename T, size_t N>
			inline constexpr auto MakeFillArray(T v) noexcept -> std::array<T, N>
			{
				std::array<T, N> arr = {};
				for (auto &val : arr)
				{
					val = v;
				}
				return arr;
			}
			template <typename VulkanStructure>
			struct ConvertStructure2Tuple
			{
				using tuple_type = TestLib::remove_cv_ref_tuple_t<decltype(std::declval<VulkanStructure>().reflect())>;

				static auto Eval(const VulkanStructure &v) -> tuple_type
				{
					return TestLib::make_remove_cv_ref_tuple(v.reflect());
				}
			};
			template <>
			struct ConvertStructure2Tuple<vk::PhysicalDeviceProperties2>
			{
				using tuple_type = TestLib::push_tuple_left_2_t<TestLib::remove_cv_ref_tuple_t<decltype(std::declval<vk::PhysicalDeviceProperties>().reflect())>, vk::StructureType, void *>;
				static auto Eval(const vk::PhysicalDeviceProperties2 &v) -> tuple_type
				{
					auto tuple1 = TestLib::make_remove_cv_ref_tuple(v.properties.reflect());
					return TestLib::make_push_tuple_left(tuple1, vk::PhysicalDeviceProperties2::structureType, v.pNext);
				}
			};
			template <>
			struct ConvertStructure2Tuple<vk::PhysicalDeviceFeatures2>
			{
				using tuple_type = TestLib::push_tuple_left_2_t<TestLib::remove_cv_ref_tuple_t<decltype(std::declval<vk::PhysicalDeviceFeatures>().reflect())>, vk::StructureType, void *>;
				static auto Eval(const vk::PhysicalDeviceFeatures2 &v) -> tuple_type
				{
					auto tuple1 = TestLib::make_remove_cv_ref_tuple(v.features.reflect());
					return TestLib::make_push_tuple_left(tuple1, vk::PhysicalDeviceFeatures2::structureType, v.pNext);
				}
			};

			template <typename VulkanStructure>
			struct ConvertTuple2Structure
			{
				using tuple_type = typename ConvertStructure2Tuple<VulkanStructure>::tuple_type;
				template <size_t... Indices>
				static auto Proc(const tuple_type &v, std::index_sequence<Indices...>) -> VulkanStructure
				{
					return VulkanStructure(std::get<Indices + 2>(v)...);
				}
				static auto Eval(const tuple_type &v) -> VulkanStructure
				{
					return Proc(v, std::make_index_sequence<std::tuple_size_v<tuple_type> - 2>());
				}
			};

			template <>
			struct ConvertTuple2Structure<vk::PhysicalDeviceProperties2>
			{
				using tuple_type = typename ConvertStructure2Tuple<vk::PhysicalDeviceProperties2>::tuple_type;
				template <size_t... Indices>
				static auto Proc(const tuple_type &v, std::index_sequence<Indices...>) -> vk::PhysicalDeviceProperties2
				{
					return vk::PhysicalDeviceProperties2(vk::PhysicalDeviceProperties(std::get<Indices + 2>(v)...));
				}
				static auto Eval(const tuple_type &v) -> vk::PhysicalDeviceProperties2
				{
					return Proc(v, std::make_index_sequence<std::tuple_size_v<tuple_type> - 2>());
				}
			};
			template <>
			struct ConvertTuple2Structure<vk::PhysicalDeviceFeatures2>
			{
				using tuple_type = typename ConvertStructure2Tuple<vk::PhysicalDeviceFeatures2>::tuple_type;
				template <size_t... Indices>
				static auto Proc(const tuple_type &v, std::index_sequence<Indices...>) -> vk::PhysicalDeviceFeatures2
				{
					return vk::PhysicalDeviceFeatures2(vk::PhysicalDeviceFeatures(std::get<Indices + 2>(v)...));
				}
				static auto Eval(const tuple_type &v) -> vk::PhysicalDeviceFeatures2
				{
					return Proc(v, std::make_index_sequence<std::tuple_size_v<tuple_type> - 2>());
				}
			};

			template <typename VulkanFeatures>
			struct ConvertFeatures2Array
			{
				using tuple_type = typename ConvertStructure2Tuple<VulkanFeatures>::tuple_type;
				using array_type = std::array<vk::Bool32, std::tuple_size_v<typename ConvertStructure2Tuple<VulkanFeatures>::tuple_type> - 2>;
				template <size_t... Indices>
				static auto Proc(const tuple_type &v, std::index_sequence<Indices...>) -> array_type
				{
					array_type array = {};
					using swallow = int[];
					swallow{
						((void)(array[Indices] = std::get<Indices + 2>(v)), 0)...};
					return array;
				}
				static auto Eval(const VulkanFeatures &v) -> array_type
				{
					return Proc(ConvertStructure2Tuple<VulkanFeatures>::Eval(v), std::make_index_sequence<std::tuple_size_v<tuple_type> - 2>());
				}
			};
			template <typename VulkanFeatures>
			struct ConvertArray2Features
			{
				using tuple_type = typename ConvertStructure2Tuple<VulkanFeatures>::tuple_type;
				using array_type = std::array<vk::Bool32, std::tuple_size_v<typename ConvertStructure2Tuple<VulkanFeatures>::tuple_type> - 2>;
				template <size_t... Indices>
				static auto Proc(const array_type &v, std::index_sequence<Indices...>) -> tuple_type
				{
					return tuple_type(VulkanFeatures::structureType, nullptr, v[Indices]...);
				}
				static auto Eval(const array_type &v) -> VulkanFeatures
				{
					return ConvertTuple2Structure<VulkanFeatures>::Eval(Proc(v, std::make_index_sequence<std::tuple_size_v<tuple_type> - 2>()));
				}
			};

			template <typename VulkanFeatures>
			struct ConvertFeatures2UInt64
			{
				using tuple_type = typename ConvertFeatures2Array<VulkanFeatures>::tuple_type;
				using array_type = typename ConvertFeatures2Array<VulkanFeatures>::array_type;
				static auto Proc(const array_type &v) -> uint64_t
				{
					static_assert(std::tuple_size_v<tuple_type> < 66);
					auto val = uint64_t(0);
					for (uint64_t i = 0; i < v.size(); ++i)
					{
						val |= (static_cast<uint64_t>(v[i]) << i);
					}
					return val;
				}
				static auto Eval(const VulkanFeatures &v) -> uint64_t
				{
					return Proc(ConvertFeatures2Array<VulkanFeatures>::Eval(v));
				}
			};
			template <typename VulkanFeatures>
			struct ConvertUInt642Features
			{
				using tuple_type = typename ConvertFeatures2Array<VulkanFeatures>::tuple_type;
				using array_type = typename ConvertArray2Features<VulkanFeatures>::array_type;
				static auto Proc(uint64_t v) -> array_type
				{
					static_assert(std::tuple_size_v<tuple_type> < 66);
					array_type val = {};
					for (uint64_t i = 0; i < val.size(); ++i)
					{
						val[i] = ((v & (static_cast<uint64_t>(1) << static_cast<uint64_t>(i))) != 0);
					}
					return val;
				}
				static auto Eval(uint64_t v) -> VulkanFeatures
				{
					return ConvertArray2Features<VulkanFeatures>::Eval(Proc(v));
				}
			};

			template <typename VulkanFeatures>
			inline auto GetAllFeatures() -> VulkanFeatures
			{
				return ConvertArray2Features<VulkanFeatures>::Eval(MakeFillArray<vk::Bool32, std::tuple_size_v<typename ConvertArray2Features<VulkanFeatures>::tuple_type> - 2>(VK_TRUE));
			}
			template <typename VulkanFeatures>
			inline auto GetNoneFeatures() -> VulkanFeatures
			{
				return ConvertArray2Features<VulkanFeatures>::Eval(MakeFillArray<vk::Bool32, std::tuple_size_v<typename ConvertArray2Features<VulkanFeatures>::tuple_type> - 2>(VK_FALSE));
			}
		}

		template <typename VulkanStructure>
		inline auto ConvertStructure2Tuple(const VulkanStructure &v) -> typename Impl::ConvertStructure2Tuple<VulkanStructure>::tuple_type
		{
			return Impl::ConvertStructure2Tuple<VulkanStructure>::Eval(v);
		}
		template <typename VulkanStructure>
		inline auto ConvertTuple2Structure(const typename Impl::ConvertTuple2Structure<VulkanStructure>::tuple_type &v) -> VulkanStructure
		{
			return Impl::ConvertTuple2Structure<VulkanStructure>::Eval(v);
		}

		template <typename VulkanFeatures>
		inline auto ConvertFeatures2Array(const VulkanFeatures &v) -> typename Impl::ConvertFeatures2Array<VulkanFeatures>::array_type
		{
			return Impl::ConvertFeatures2Array<VulkanFeatures>::Eval(v);
		}
		template <typename VulkanFeatures>
		inline auto ConvertArray2Features(const typename Impl::ConvertArray2Features<VulkanFeatures>::array_type &v) -> VulkanFeatures
		{
			return Impl::ConvertArray2Features<VulkanFeatures>::Eval(v);
		}

		template <typename VulkanFeatures>
		inline auto ConvertFeatures2UInt64(const VulkanFeatures &v) -> uint64_t
		{
			return Impl::ConvertFeatures2UInt64<VulkanFeatures>::Eval(v);
		}
		template <typename VulkanFeatures>
		inline auto ConvertUInt642Features(const uint64_t &v) -> VulkanFeatures
		{
			return Impl::ConvertUInt642Features<VulkanFeatures>::Eval(v);
		}

		template <typename VulkanFeatures>
		inline auto All() -> VulkanFeatures { return Impl::GetAllFeatures<VulkanFeatures>(); }
		template <typename VulkanFeatures>
		inline auto None() -> VulkanFeatures { return Impl::GetNoneFeatures<VulkanFeatures>(); }
	}
	struct ITestGraphicsVulkanStructureWrapper
	{
		ITestGraphicsVulkanStructureWrapper() noexcept {}
		virtual ~ITestGraphicsVulkanStructureWrapper() noexcept {}

		virtual auto Clone() const noexcept -> ITestGraphicsVulkanStructureWrapper * = 0;
		virtual void Link(ITestGraphicsVulkanStructureWrapper *pNextStructure) = 0;

		// void QueryProperties(const vk::raii::PhysicalDevice* physicalDevice){
		//	if (!physicalDevice) { return; }
		//	auto properties2 = vk::PhysicalDeviceProperties2();
		//	auto pNext = GetPNext();
		//	if (pNext) {
		//		properties2.pNext = pNext->GetPData();
		//	}else{
		//		properties2.pNext = nullptr;
		//	}
		//	if (GetSType() == vk::StructureType::ePhysicalDeviceProperties2) {
		//		physicalDevice->getDispatcher()->vkGetPhysicalDeviceProperties2(
		//			physicalDevice->operator*(),reinterpret_cast<VkPhysicalDeviceProperties2*>(&properties2)
		//		);
		//		SetPData(&properties2);
		//		return;
		//	}
		//	properties2.pNext = GetPData();
		//	physicalDevice->getDispatcher()->vkGetPhysicalDeviceProperties2(
		//		physicalDevice->operator*(), reinterpret_cast<VkPhysicalDeviceProperties2*>(&properties2)
		//	);
		//	return;
		// }

		virtual auto GetSType() const noexcept -> vk::StructureType = 0;
		virtual auto GetDataSize() const noexcept -> size_t = 0;

		virtual auto GetPData() const noexcept -> const void * = 0;
		virtual auto GetPData() noexcept -> void * = 0;

		virtual bool SetPData(void *pData) = 0;

		virtual auto GetPNext() const noexcept -> ITestGraphicsVulkanStructureWrapper * = 0;
	};
	struct ITestGraphicsVulkanFeaturesWrapper : public ITestGraphicsVulkanStructureWrapper
	{
		ITestGraphicsVulkanFeaturesWrapper() noexcept : ITestGraphicsVulkanStructureWrapper() {}
		virtual ~ITestGraphicsVulkanFeaturesWrapper() noexcept {}

		void QueryFeatures(const vk::raii::PhysicalDevice *physicalDevice)
		{
			if (!physicalDevice)
			{
				return;
			}
			auto features2 = vk::PhysicalDeviceFeatures2();
			auto pNext = GetPNext();
			if (pNext)
			{
				features2.pNext = pNext->GetPData();
			}
			if (GetSType() == vk::StructureType::ePhysicalDeviceFeatures2)
			{
				physicalDevice->getDispatcher()->vkGetPhysicalDeviceFeatures2(
					physicalDevice->operator*(), reinterpret_cast<VkPhysicalDeviceFeatures2 *>(&features2));
				SetPData(&features2);
				return;
			}
			features2.pNext = GetPData();
			physicalDevice->getDispatcher()->vkGetPhysicalDeviceFeatures2(
				physicalDevice->operator*(), reinterpret_cast<VkPhysicalDeviceFeatures2 *>(&features2));
			return;
		}

		virtual auto GetAllFeatures() const noexcept -> ITestGraphicsVulkanFeaturesWrapper * = 0;
		virtual auto GetNoneFeatures() const noexcept -> ITestGraphicsVulkanFeaturesWrapper * = 0;

		virtual auto ConvertFromUInt64(uint64_t val) const noexcept -> ITestGraphicsVulkanFeaturesWrapper * = 0;
		virtual auto ConvertToUInt64() const noexcept -> uint64_t = 0;
	};
	template <typename VulkanStructure>
	struct TTestGraphicsVulkanFeaturesWrapper : public ITestGraphicsVulkanFeaturesWrapper
	{
		using DataType = VulkanStructure;
		static constexpr vk::StructureType structureType = VulkanStructure::structureType;

		TTestGraphicsVulkanFeaturesWrapper(const DataType &data = {}) noexcept : ITestGraphicsVulkanFeaturesWrapper(), m_Data{data}
		{
			m_Data.sType = VulkanStructure::structureType;
			m_Data.pNext = nullptr;
			m_PNext = nullptr;
		}
		virtual ~TTestGraphicsVulkanFeaturesWrapper() noexcept {}

		static auto All() -> TTestGraphicsVulkanFeaturesWrapper *
		{
			return new TTestGraphicsVulkanFeaturesWrapper(TestGraphicsVulkanUtility::All<VulkanStructure>());
		}
		static auto None() -> TTestGraphicsVulkanFeaturesWrapper *
		{
			return new TTestGraphicsVulkanFeaturesWrapper(TestGraphicsVulkanUtility::None<VulkanStructure>());
		}

		virtual auto GetAllFeatures() const noexcept -> ITestGraphicsVulkanFeaturesWrapper * override
		{
			return All();
		}
		virtual auto GetNoneFeatures() const noexcept -> ITestGraphicsVulkanFeaturesWrapper * override
		{
			return None();
		}

		virtual auto ConvertFromUInt64(uint64_t val) const noexcept -> ITestGraphicsVulkanFeaturesWrapper * override
		{
			return new TTestGraphicsVulkanFeaturesWrapper(TestGraphicsVulkanUtility::ConvertUInt642Features<VulkanStructure>(val));
		}
		virtual auto ConvertToUInt64() const noexcept -> uint64_t override
		{
			return TestGraphicsVulkanUtility::ConvertFeatures2UInt64<VulkanStructure>(m_Data);
		}

		virtual auto Clone() const noexcept -> ITestGraphicsVulkanStructureWrapper * override
		{
			return new TTestGraphicsVulkanFeaturesWrapper(m_Data);
		}

		virtual void Link(ITestGraphicsVulkanStructureWrapper *pNextStructure) override
		{
			if (!pNextStructure)
			{
				m_PNext = nullptr;
				m_Data.pNext = nullptr;
			}
			else
			{
				m_PNext = pNextStructure;
				m_Data.pNext = pNextStructure->GetPData();
			}
		}

		virtual auto GetSType() const noexcept -> vk::StructureType override
		{
			return VulkanStructure::structureType;
		}
		virtual auto GetDataSize() const noexcept -> size_t override
		{
			return sizeof(m_Data);
		}

		virtual auto GetPData() const noexcept -> const void * override
		{
			return &m_Data;
		}
		virtual auto GetPData() noexcept -> void * override
		{
			return &m_Data;
		}

		virtual bool SetPData(void *pData) override
		{
			if (!pData)
			{
				return false;
			}
			vk::BaseInStructure inStructure = {};
			std::memcpy(&inStructure, pData, sizeof(inStructure));
			if (inStructure.sType != VulkanStructure::structureType)
			{
				return false;
			}
			std::memcpy(&m_Data, pData, sizeof(m_Data));
			m_Data.sType = VulkanStructure::structureType;
			if (m_PNext)
			{
				m_Data.pNext = m_PNext->GetPData();
			}
			return true;
		}
		virtual auto GetPNext() const noexcept -> ITestGraphicsVulkanStructureWrapper * override { return m_PNext; }

		auto GetData() const noexcept -> const VulkanStructure & { return m_Data; }
		auto GetData() noexcept -> VulkanStructure & { return m_Data; }

	private:
		VulkanStructure m_Data;
		ITestGraphicsVulkanStructureWrapper *m_PNext;
	};

	class TestGraphicsVulkanDevice;
	class TestGraphicsVulkanInstance
	{
		using VkRaiiContext_t = vk::raii::Context;
		using VkRaiiInstance_t = vk::raii::Instance;
		using VkDebugUtilsMessenger_t = vk::raii::DebugUtilsMessengerEXT;
		using VkPhysicalDevices_t = vk::raii::PhysicalDevices;
		using VkPhysicalDevice_t = vk::raii::PhysicalDevice;

	private:
		TestGraphicsVulkanInstance() noexcept;

	public:
		static auto GetHandle() -> TestGraphicsVulkanInstance &;
		~TestGraphicsVulkanInstance() noexcept;

		bool Init();
		void Free();

		bool IsInitialized() const noexcept { return m_IsInitialized; }

		auto CreateDevice(unsigned int physicalDeviceIdx) const noexcept -> TestGraphicsVulkanDevice *;

		bool SetApplicationInfo(const std::string &application_name, uint32_t application_version) noexcept;
		bool SetEngineInfo(const std::string &engine_name, uint32_t engine_version) noexcept;

		bool IsEnabledExtension(const std::string &layer_name) const noexcept;
		bool IsEnabledLayer(const std::string &layer_name) const noexcept;
		bool IsEnabledDebug() const noexcept { return m_IsEnabledDebug; }
		bool IsEnabledSurface() const noexcept { return m_IsEnabledSurface; }
		bool IsEnabledEmulation() const noexcept { return m_IsEnabledEmulation; }

		bool EnableExtension(const std::string &extension_name) noexcept;
		bool EnableExtensions(const std::vector<std::string> &extension_names) noexcept;
		bool EnableLayer(const std::string &layer_name) noexcept;
		bool EnableLayers(const std::vector<std::string> &layernames) noexcept;
		bool EnableDebug(
			vk::DebugUtilsMessageSeverityFlagsEXT messageSeverity,
			vk::DebugUtilsMessageTypeFlagsEXT messageType,
			PFN_vkDebugUtilsMessengerCallbackEXT messageCallback,
			void *pUserData) noexcept;

		bool EnableSurface() noexcept;
		bool EnableEmulation() noexcept;

		auto GetVkRaiiContext() const noexcept -> VkRaiiContext_t *;
		auto GetVkRaiiInstance() const noexcept -> VkRaiiInstance_t *;
		auto GetVkRaiiDebugUtilsMessenger() const noexcept -> VkDebugUtilsMessenger_t *;
		auto GetVkRaiiPhysicalDevices() const noexcept -> VkPhysicalDevices_t *;
		auto GetVkRaiiPhysicalDevice(uint32_t idx) const noexcept -> VkPhysicalDevice_t *;

		auto GetVkInstance() const noexcept -> VkInstance;
		auto GetVkDebugUtilsMessenger() const noexcept -> VkDebugUtilsMessengerEXT;
		auto GetVkPhysicalDevice(uint32_t idx) const noexcept -> VkPhysicalDevice;

	private:
		/*Supported*/
		bool IsSupportedExtensions(const std::vector<std::string> &extension_names) const noexcept;
		bool IsSupportedExtension(const std::string &extension_name) const noexcept;
		bool IsSupportedLayers(const std::vector<std::string> &layer_names) const noexcept;
		bool IsSupportedLayer(const std::string &layer_name) const noexcept;

	private:
		bool m_IsInitialized = false;
		bool m_IsEnabledDebug = false;
		bool m_IsEnabledSurface = false;
		bool m_IsEnabledEmulation = false;

		std::unique_ptr<VkRaiiContext_t> m_VkRaiiContext = nullptr;
		std::unique_ptr<VkRaiiInstance_t> m_VkRaiiInstance = nullptr;
		std::unique_ptr<VkDebugUtilsMessenger_t> m_VkRaiiDebugUtilsMessenger = nullptr;
		std::unique_ptr<VkPhysicalDevices_t> m_VkRaiiPhysicalDevices = nullptr;

		std::unordered_set<std::string> m_InstanceEnabledExtensionNames = {};
		std::unordered_set<std::string> m_InstanceEnabledLayerNames = {};

		vk::DebugUtilsMessageSeverityFlagsEXT m_DebugUtilsMessageSeverity = {};
		vk::DebugUtilsMessageTypeFlagsEXT m_DebugUtilsMessageType = {};
		PFN_vkDebugUtilsMessengerCallbackEXT m_DebugUtilsMessengerCallback = nullptr;
		void *m_DebugUtilsPUserData = nullptr;

		uint32_t m_InstanceApiVersion = 0;
		std::string m_EngineName = "";
		uint32_t m_EngineVersion = 0;
		std::string m_ApplicationName = "";
		uint32_t m_ApplicationVersion = 0;

		std::vector<vk::ExtensionProperties> m_InstanceExtensionProperties = {};
		std::vector<vk::LayerProperties> m_InstanceLayerProperties = {};
	};
	class TestGraphicsVulkanDevice
	{
		using VkRaiiContext_t = vk::raii::Context;
		using VkRaiiInstance_t = vk::raii::Instance;
		using VkRaiiPhysicalDevice_t = vk::raii::PhysicalDevice;
		using VkRaiiDevice_t = vk::raii::Device;
		using VkRaiiQueue_t = vk::raii::Queue;
		using FeaturesWrapper = ITestGraphicsVulkanFeaturesWrapper;

	private:
		TestGraphicsVulkanDevice(unsigned int physicalDeviceIdx) noexcept;

	public:
		static auto New(unsigned int physicalDeviceIdx) noexcept -> TestGraphicsVulkanDevice *;
		~TestGraphicsVulkanDevice() noexcept;

		bool Init();
		void Free();

		bool IsInitialized() const noexcept;

		template <typename VulkanFeatures>
		bool EnableFeatures(const VulkanFeatures &requiredFeatures = {}) noexcept
		{
			if (m_IsInitialized)
			{
				return false;
			}
			auto *supportedFeatures = RequestSupportedFeaturesWrapper<VulkanFeatures>();
			auto supportedFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(supportedFeatures->GetData());
			auto requiredFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(requiredFeatures);
			if ((supportedFeaturesU64 & requiredFeaturesU64) != requiredFeaturesU64)
			{
				return false;
			}
			if (m_DeviceEnabledFeatures.count(VulkanFeatures::structureType) == 0)
			{
				m_DeviceEnabledFeatures[VulkanFeatures::structureType] = std::unique_ptr<FeaturesWrapper>(
					new TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures>(requiredFeatures));
			}
			else
			{
				auto *enabledFeatures = static_cast<TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures> *>(m_DeviceEnabledFeatures.at(VulkanFeatures::structureType).get());
				auto enabledFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(enabledFeatures->GetData());
				auto resultFeaturesU64 = enabledFeaturesU64 | requiredFeaturesU64;
				enabledFeatures->GetData() = TestGraphicsVulkanUtility::ConvertUInt642Features<VulkanFeatures>(resultFeaturesU64);
			}
			return true;
		}
		template <typename VulkanFeatures>
		bool EnableFeatures(const VulkanFeatures &requiredFeatures, const VulkanFeatures &optionalFeatures) noexcept
		{
			if (m_IsInitialized)
			{
				return false;
			}
			auto *supportedFeatures = RequestSupportedFeaturesWrapper<VulkanFeatures>();
			auto supportedFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(supportedFeatures->GetData());
			auto requiredFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(requiredFeatures);
			if ((supportedFeaturesU64 & requiredFeaturesU64) != requiredFeaturesU64)
			{
				return false;
			}
			auto optionalFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(optionalFeatures);
			auto requestFeaturesU64 = (optionalFeaturesU64 & supportedFeaturesU64) | requiredFeaturesU64;

			if (m_DeviceEnabledFeatures.count(VulkanFeatures::structureType) == 0)
			{
				m_DeviceEnabledFeatures[VulkanFeatures::structureType] = std::unique_ptr<FeaturesWrapper>(
					new TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures>(TestGraphicsVulkanUtility::ConvertUInt642Features<VulkanFeatures>(requestFeaturesU64)));
			}
			else
			{
				auto *enabledFeatures = static_cast<TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures> *>(m_DeviceEnabledFeatures.at(VulkanFeatures::structureType).get());
				auto enabledFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(enabledFeatures->GetData());
				auto resultFeaturesU64 = enabledFeaturesU64 | requestFeaturesU64;
				enabledFeatures->GetData() = TestGraphicsVulkanUtility::ConvertUInt642Features<VulkanFeatures>(resultFeaturesU64);
			}
			return true;
		}
		bool EnableExtension(const std::string &extensionName) noexcept
		{
			if (m_IsInitialized)
			{
				return false;
			}
			if (!IsSupportedExtension(extensionName))
			{
				return false;
			}
			m_DeviceEnabledExtensionNames.insert(extensionName);
			return true;
		}
		template <typename VulkanFeatures>
		bool EnableExtension(const std::string &extensionName, const VulkanFeatures &requiredFeatures) noexcept
		{
			if (m_IsInitialized)
			{
				return false;
			}
			if (!IsSupportedExtension(extensionName))
			{
				return false;
			}
			auto *supportedFeatures = RequestSupportedFeaturesWrapper<VulkanFeatures>();
			auto supportedFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(supportedFeatures->GetData());
			auto requiredFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(requiredFeatures);
			if ((supportedFeaturesU64 & requiredFeaturesU64) != requiredFeaturesU64)
			{
				return false;
			}
			if (m_DeviceEnabledFeatures.count(VulkanFeatures::structureType) == 0)
			{
				m_DeviceEnabledFeatures[VulkanFeatures::structureType] = std::unique_ptr<ITestGraphicsVulkanFeaturesWrapper>(
					new TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures>(requiredFeatures));
			}
			else
			{
				auto *enabledFeatures = static_cast<TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures> *>(m_DeviceEnabledFeatures.at(VulkanFeatures::structureType).get());
				auto enabledFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(enabledFeatures->GetData());
				auto resultFeaturesU64 = enabledFeaturesU64 | requiredFeaturesU64;
				enabledFeatures->GetData() = TestGraphicsVulkanUtility::ConvertUInt642Features<VulkanFeatures>(resultFeaturesU64);
			}
			m_DeviceEnabledExtensionNames.insert(extensionName);
			return true;
		}
		template <typename VulkanFeatures>
		bool EnableExtension(const std::string &extensionName, const VulkanFeatures &requiredFeatures, const VulkanFeatures &optionalFeatures) noexcept
		{
			if (m_IsInitialized)
			{
				return false;
			}
			if (!IsSupportedExtension(extensionName))
			{
				return false;
			}
			auto *supportedFeatures = RequestSupportedFeaturesWrapper<VulkanFeatures>();
			auto supportedFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(supportedFeatures->GetData());
			auto requiredFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(requiredFeatures);
			if ((supportedFeaturesU64 & requiredFeaturesU64) != requiredFeaturesU64)
			{
				return false;
			}
			auto optionalFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(optionalFeatures);
			auto requestFeaturesU64 = (optionalFeaturesU64 & supportedFeaturesU64) | requiredFeaturesU64;

			if (m_DeviceEnabledFeatures.count(VulkanFeatures::structureType) == 0)
			{
				m_DeviceEnabledFeatures[VulkanFeatures::structureType] = std::unique_ptr<FeaturesWrapper>(
					new TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures>(TestGraphicsVulkanUtility::ConvertUInt642Features<VulkanFeatures>(requestFeaturesU64)));
			}
			else
			{
				auto *enabledFeatures = static_cast<TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures> *>(m_DeviceEnabledFeatures.at(VulkanFeatures::structureType).get());
				auto enabledFeaturesU64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(enabledFeatures->GetData());
				auto resultFeaturesU64 = enabledFeaturesU64 | requestFeaturesU64;
				enabledFeatures->GetData() = TestGraphicsVulkanUtility::ConvertUInt642Features<VulkanFeatures>(resultFeaturesU64);
			}
			m_DeviceEnabledExtensionNames.insert(extensionName);
			return true;
		}

		bool EnableSwapchain() noexcept;
		bool EnableGeometryShader() noexcept;
		bool EnableTesselationShader() noexcept;
		bool EnableDedicatedAllocation() noexcept;
		bool EnableBufferDeviceAddress(const vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR &optionalBufferDeviceAddress = {}) noexcept;
		bool EnableDescriptorIndexing(const vk::PhysicalDeviceDescriptorIndexingFeaturesEXT &optionalDescriptorIndexing = {}) noexcept;
		bool EnableRayTracing(
			const vk::PhysicalDeviceRayTracingPipelineFeaturesKHR &optionalRayTracingFeatures = {},
			const vk::PhysicalDeviceAccelerationStructureFeaturesKHR &optionalAccelerationStructureFeatures = {}) noexcept;
		bool EnableDynamicRendering() noexcept;
		bool EnableAsyncTransferQueue() noexcept;
		bool EnableAsyncComputeQueue() noexcept;

		bool IsEnabledExtension(const std::string &extensionName) const noexcept { return m_DeviceEnabledExtensionNames.count(extensionName) > 0; }
		template <typename VulkanFeatures>
		bool IsEnabledFeatures(const VulkanFeatures &features) const noexcept
		{
			if (m_DeviceEnabledFeatures.count(VulkanFeatures::structureType) == 0)
			{
				return false;
			}
			auto enabledFeatures64 = m_DeviceEnabledFeatures.at(VulkanFeatures::structureType)->ConvertToUInt64();
			auto requiredFeatures64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(features);
			return (enabledFeatures64 & requiredFeatures64) == requiredFeatures64;
		}
		bool IsEnabledSwapchain() const noexcept;
		bool IsEnabledGeometryShader() const noexcept;
		bool IsEnabledTesselationShader() const noexcept;
		bool IsEnabledDedicatedAllocation() const noexcept;
		bool IsEnabledDescriptorIndexing() const noexcept;
		bool IsEnabledBufferDeviceAddress() const noexcept;
		bool IsEnabledRayTracing() const noexcept;
		bool IsEnabledDynamicRendering() const noexcept;
		bool IsEnabledAsyncComputeQueue() const noexcept;
		bool IsEnabledAsyncTransferQueue() const noexcept;

		static auto GetVkRaiiContext() noexcept -> VkRaiiContext_t *;
		static auto GetVkRaiiInstance() noexcept -> VkRaiiInstance_t *;
		auto GetVkRaiiPhysicalDevice() const noexcept -> VkRaiiPhysicalDevice_t *;
		auto GetVkRaiiDevice() const noexcept -> VkRaiiDevice_t *;
		auto GetVkRaiiGeneralQueue() const noexcept -> VkRaiiQueue_t *;
		auto GetVkRaiiAsyncTransferQueue() const noexcept -> VkRaiiQueue_t *;
		auto GetVkRaiiAsyncComputeQueue() const noexcept -> VkRaiiQueue_t *;

		static auto GetVkInstance() noexcept -> VkInstance;
		auto GetVkPhysicalDevice() const noexcept -> VkPhysicalDevice;
		auto GetVkDevice() const noexcept -> VkDevice;
		auto GetVkGeneralQueue() const noexcept -> VkQueue;
		auto GetVkAsyncTransferQueue() const noexcept -> VkQueue;
		auto GetVkAsyncComputeQueue() const noexcept -> VkQueue;

	private:
		auto RequestSupportedFeaturesWrapper(const FeaturesWrapper *ref) -> FeaturesWrapper *
		{
			if (!ref)
			{
				return nullptr;
			}
			auto sType = ref->GetSType();
			if (m_DeviceSupportedFeatures.count(sType) == 0)
			{
				m_DeviceSupportedFeatures[sType] = std::unique_ptr<FeaturesWrapper>(ref->GetNoneFeatures());
				m_DeviceSupportedFeatures[sType]->QueryFeatures(m_VkRaiiPhysicalDevice);
			}
			return m_DeviceSupportedFeatures[sType].get();
		}
		template <typename VulkanFeatures>
		auto RequestSupportedFeaturesWrapper() -> TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures> *
		{
			if (m_DeviceSupportedFeatures.count(VulkanFeatures::structureType) == 0)
			{
				m_DeviceSupportedFeatures[VulkanFeatures::structureType] = std::unique_ptr<
					FeaturesWrapper>(new TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures>());
				m_DeviceSupportedFeatures[VulkanFeatures::structureType]->QueryFeatures(m_VkRaiiPhysicalDevice);
			}
			return static_cast<TTestGraphicsVulkanFeaturesWrapper<VulkanFeatures> *>(m_DeviceSupportedFeatures.at(VulkanFeatures::structureType).get());
		}

		bool IsSupportedExtension(const std::string &extensionName) const noexcept;

		template <typename VulkanFeatures>
		bool IsSupportedFeatures(const VulkanFeatures &requiredFeatures) const noexcept
		{
			if (m_DeviceSupportedFeatures.count(VulkanFeatures::structureType) == 0)
			{
				return false;
			}
			auto supportedFeatures64 = m_DeviceSupportedFeatures.at(VulkanFeatures::structureType)->ConvertToUInt64();
			auto requiredFeatures64 = TestGraphicsVulkanUtility::ConvertFeatures2UInt64(requiredFeatures);
			return (requiredFeatures64 & supportedFeatures64) == requiredFeatures64;
		}
		bool IsSupportedFeaturesWrapper(const FeaturesWrapper *featuresWrapper) const noexcept;
		bool IsSupportedFeaturesWrapperList(const std::vector<const FeaturesWrapper *> &featuresWrapperList) const noexcept;

		static auto FindQueueFamilyIndices(const std::vector<vk::QueueFamilyProperties> &queueProps, vk::QueueFlags requiredFlags = vk::QueueFlagBits::eGraphics | vk::QueueFlagBits::eCompute | vk::QueueFlagBits::eTransfer, vk::QueueFlags avoidFlags = {}) noexcept -> std::vector<uint32_t>;

	private:
		bool m_IsInitialized = false;

		bool m_IsEnabledSwapchain = false;
		bool m_IsEnabledGeometryShader = false;
		bool m_IsEnabledTesselationShader = false;
		bool m_IsEnabledDedicatedAllocation = false;
		bool m_IsEnabledDescriptorIndexing = false;
		bool m_IsEnabledBufferDeviceAddress = false;
		bool m_IsEnabledRayTracing = false;
		bool m_IsEnabledDynamicRendering = false;

		bool m_IsEnabledAsyncComputeQueue = false;
		bool m_IsEnabledAsyncTransferQueue = false;

		VkRaiiPhysicalDevice_t *m_VkRaiiPhysicalDevice = nullptr;
		std::unique_ptr<VkRaiiDevice_t> m_VkRaiiDevice = nullptr;
		std::unique_ptr<VkRaiiQueue_t> m_VkRaiiGeneralQueue = nullptr;
		std::unique_ptr<VkRaiiQueue_t> m_VkRaiiAsyncComputeQueue = nullptr;
		std::unique_ptr<VkRaiiQueue_t> m_VkRaiiAsyncTransferQueue = nullptr;

		std::unordered_set<std::string> m_DeviceEnabledExtensionNames = {};
		std::unordered_map<vk::StructureType, std::unique_ptr<FeaturesWrapper>> m_DeviceEnabledFeatures = {};

		uint32_t m_PhysicalDeviceIndex = 0;
		uint32_t m_GeneralQueueIndex = VK_QUEUE_FAMILY_IGNORED;
		uint32_t m_AsyncComputeQueueIndex = VK_QUEUE_FAMILY_IGNORED;
		uint32_t m_AsyncTransferQueueIndex = VK_QUEUE_FAMILY_IGNORED;

		std::vector<vk::ExtensionProperties> m_DeviceExtensionProperties = {};
		std::vector<vk::QueueFamilyProperties> m_DeviceQueueFamilyProperties = {};
		vk::PhysicalDeviceProperties m_DeviceProperties = {};
		std::unordered_map<vk::StructureType, std::unique_ptr<FeaturesWrapper>> m_DeviceSupportedFeatures = {};
	};

	namespace TestGraphicsVulkan
	{
		auto Instance() noexcept -> TestGraphicsVulkanInstance &;
	}
}
#endif
