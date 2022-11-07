#ifndef AKARI_GRAPHCIS_VULKAN_AKARI_VULKAN_DEVICE_H
#define AKARI_GRAPHCIS_VULKAN_AKARI_VULKAN_DEVICE_H
#include <Akari/Engine/AkariEngine.h>
#include <Akari/Engine/AkariUtility.h>
#include <vulkan/vulkan_raii.hpp>
#include <unordered_set>
#include <any>
#include <utility>
#include <memory>
#include <vector>
#include <string>
namespace Akari {
	namespace Graphics {
		class AkariVulkanDeviceStructureData {
			using pfn_clone = auto(*)(const void*)->AkariVulkanDeviceStructureData;
			template<typename Features>
			struct func_impl {
				static auto clone_callback(const void* ptr)->AkariVulkanDeviceStructureData
				{
					if (!ptr) {
						return AkariVulkanDeviceStructureData(AkariMoveOnlyDynamicStorage(nullptr), nullptr, func_impl<void>::clone_callback);
					}
					else {
						auto realP = static_cast<const Features*>(ptr);
						auto copyP = new Features(*realP);
						return AkariVulkanDeviceStructureData(AkariMoveOnlyDynamicStorage(copyP),&copyP->pNext, func_impl<Features>::clone_callback);
					}
				}
			};
			template<>
			struct func_impl<void> {
				static auto clone_callback(const void* ptr)->AkariVulkanDeviceStructureData
				{
					return AkariVulkanDeviceStructureData(AkariMoveOnlyDynamicStorage(nullptr), nullptr, func_impl<void>::clone_callback);
				}
			};
			AkariVulkanDeviceStructureData(AkariMoveOnlyDynamicStorage&& data, void** pPNext, pfn_clone cloneCallback)noexcept:m_Data{ std::move(data) }, m_PPNext{ pPNext }, m_CloneCallback{ cloneCallback } {}
		public:
			 AkariVulkanDeviceStructureData(nullptr_t = nullptr)noexcept :AkariVulkanDeviceStructureData(AkariMoveOnlyDynamicStorage(nullptr), nullptr, func_impl<void>::clone_callback) {}
			~AkariVulkanDeviceStructureData()noexcept {}

			AkariVulkanDeviceStructureData& operator=(nullptr_t)noexcept
			{
				m_Data = nullptr;
				m_PPNext = nullptr;
				m_CloneCallback = func_impl<void>::clone_callback;
				return *this;
			}

			AkariVulkanDeviceStructureData(AkariVulkanDeviceStructureData&& data)noexcept:
				AkariVulkanDeviceStructureData(std::move(data.m_Data), data.m_PPNext, data.m_CloneCallback) {
				data.m_Data = nullptr;
				data.m_PPNext = nullptr;
				data.m_CloneCallback = func_impl<void>::clone_callback;
			}
			AkariVulkanDeviceStructureData& operator=(AkariVulkanDeviceStructureData && data)noexcept{
				if (&data != this) {
					m_Data = std::move(data.m_Data);
					m_PPNext= data.m_PPNext;
					m_CloneCallback = data.m_CloneCallback;
					data.m_Data = nullptr;
					data.m_PPNext = nullptr;
					data.m_CloneCallback = func_impl<void>::clone_callback;
				}
				return *this;
			}

			AkariVulkanDeviceStructureData(const AkariVulkanDeviceStructureData& data)noexcept
				:AkariVulkanDeviceStructureData(std::move(data.m_CloneCallback(static_cast<const void*>(data.m_Data)))) {}
			AkariVulkanDeviceStructureData& operator=(const AkariVulkanDeviceStructureData& data)noexcept{
				if (&data != this) {
					*this = std::move(data.m_CloneCallback(static_cast<void*>(m_Data)));
				}
				return *this;
			}

			template<typename T>
			AkariVulkanDeviceStructureData(T* pFeatures)noexcept:
			AkariVulkanDeviceStructureData(std::move(func_impl<T>::clone_callback(pFeatures))) {}
			template<typename T>
			AkariVulkanDeviceStructureData& operator=(T* pFeatures)noexcept {
				*this = std::move(func_impl<T>::clone_callback(pFeatures));
				return *this;
			}

			template<typename Features = void> auto GetPData()const noexcept->const Features* { return static_cast<const Features*>(m_Data); }
			template<typename Features = void> auto GetPData()  noexcept->  Features* { return static_cast<  Features*>(m_Data); }

			auto GetPPNext()noexcept -> void** { return m_PPNext; }
		private:
			AkariMoveOnlyDynamicStorage m_Data;
			void** m_PPNext;
			pfn_clone m_CloneCallback;
		};

		class AkariVulkanDeviceFeaturesList{
		public:
			AkariVulkanDeviceFeaturesList() noexcept {}
			~AkariVulkanDeviceFeaturesList() noexcept {}

			AkariVulkanDeviceFeaturesList(const AkariVulkanDeviceFeaturesList& features)noexcept
			{
				m_Data = features.m_Data;
			}
			AkariVulkanDeviceFeaturesList& operator=(const AkariVulkanDeviceFeaturesList& features)noexcept
			{
				if (this != &features) {
					m_Data = features.m_Data;
				}
				return *this;
			}

			AkariVulkanDeviceFeaturesList(AkariVulkanDeviceFeaturesList&& features)noexcept
			{
				m_Data = std::move(features.m_Data);
			}
			AkariVulkanDeviceFeaturesList& operator=(AkariVulkanDeviceFeaturesList&& features)noexcept
			{
				if (this != &features) {
					m_Data = std::move(features.m_Data);
				}
				return *this;
			}

			template<typename VulkanDeviceFeatures> auto AtFeaturesPointer() const noexcept -> const VulkanDeviceFeatures* { 
				if (m_Data.count(VulkanDeviceFeatures::structureType) > 0) {
					return static_cast<const VulkanDeviceFeatures*>(m_Data.at(VulkanDeviceFeatures::structureType).pData.get());
				}
				else {
					return nullptr;
				}
			}
			template<typename VulkanDeviceFeatures> auto AtFeaturesPointer()       noexcept ->       VulkanDeviceFeatures* {
				if (m_Data.count(VulkanDeviceFeatures::structureType) > 0) {
					return static_cast<VulkanDeviceFeatures*>(m_Data.at(VulkanDeviceFeatures::structureType).GetPData());
				}
				else {
					return nullptr;
				}
			}

			bool HasFeatures(vk::StructureType sType)const noexcept {
				return m_Data.count(sType) > 0;
			}
			template<typename VulkanDeviceFeatures> bool HasFeatures()const noexcept {
				return HasFeatures(VulkanDeviceFeatures::structureType);
			}
			template<typename VulkanDeviceFeatures> bool GetFeatures(VulkanDeviceFeatures& features)const noexcept {
				if (m_Data.count(VulkanDeviceFeatures) == 0) { return false; }
				auto pFeatures = AtFeaturesPointer<VulkanDeviceFeatures>();
				std::memcpy(&features, pFeatures, sizeof(VulkanDeviceFeatures));
				features.sType = VulkanDeviceFeatures::structureType;
				features.pNext = nullptr;
				return true;
			}
			template<typename VulkanDeviceFeatures> void SetFeatures(const VulkanDeviceFeatures& features)noexcept {
				auto features_ptr = AddFeaturesPointer< VulkanDeviceFeatures>();
				std::memcpy(features_ptr, &features, sizeof(VulkanDeviceFeatures));
				features_ptr->sType = VulkanDeviceFeatures::structureType;
				features_ptr->pNext = nullptr;
			}

			auto Size() const noexcept -> size_t { return m_Data.size(); }
			auto Empty()const noexcept -> bool { return m_Data.empty(); }

			void Link() noexcept {
				void** prvPpNext = nullptr;
				for (auto& [sType, data] : m_Data) {
					if (prvPpNext) {
						*prvPpNext = data.GetPData();
					}
					prvPpNext = data.GetPPNext();
				}
			}
			void UnLink() {
				for (auto& [sType, data] : m_Data) {
					*data.GetPPNext() = nullptr;
				}
			}

			void Query(const vk::raii::PhysicalDevice& physicalDevice)noexcept {
				if (Empty()) {
					return;
				}
#ifdef VK_KHR_get_physical_device_properties2
				if (HasFeatures<vk::PhysicalDeviceFeatures2KHR>()){
					auto tmpFeatures2Pair = std::move(m_Data.at(vk::PhysicalDeviceFeatures2KHR::structureType));
					m_Data.erase(vk::PhysicalDeviceFeatures2KHR::structureType);
					Link();
					*tmpFeatures2Pair.GetPPNext() = std::begin(m_Data)->second.GetPData();
					PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR = physicalDevice.getDispatcher()->vkGetPhysicalDeviceFeatures2KHR;
					if (!vkGetPhysicalDeviceFeatures2KHR) {
						vkGetPhysicalDeviceFeatures2KHR = physicalDevice.getDispatcher()->vkGetPhysicalDeviceFeatures2;
						assert(vkGetPhysicalDeviceFeatures2KHR);
					}
					vkGetPhysicalDeviceFeatures2KHR(*physicalDevice, reinterpret_cast<VkPhysicalDeviceFeatures2KHR*>(tmpFeatures2Pair.GetPData()));
					m_Data[vk::PhysicalDeviceFeatures2KHR::structureType] = std::move(tmpFeatures2Pair);
					UnLink();
				}
				else {
					Link();
					vk::PhysicalDeviceFeatures2KHR features2;
					features2.pNext = std::begin(m_Data)->second.GetPData();
					PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR = physicalDevice.getDispatcher()->vkGetPhysicalDeviceFeatures2KHR;
					if (!vkGetPhysicalDeviceFeatures2KHR) {
						vkGetPhysicalDeviceFeatures2KHR = physicalDevice.getDispatcher()->vkGetPhysicalDeviceFeatures2;
						assert(vkGetPhysicalDeviceFeatures2KHR);
					}
					vkGetPhysicalDeviceFeatures2KHR(*physicalDevice, reinterpret_cast<VkPhysicalDeviceFeatures2KHR*>(&features2));
					UnLink();
				}
#else
				
#endif
			}
		private:
			template<typename VulkanDeviceFeatures> auto AddFeaturesPointer()       noexcept ->       VulkanDeviceFeatures* {
				if (m_Data.count(VulkanDeviceFeatures::structureType) > 0) {
					return static_cast<VulkanDeviceFeatures*>(m_Data.at(VulkanDeviceFeatures::structureType).GetPData());
				}
				else {
					auto ptr = new VulkanDeviceFeatures();
					m_Data[VulkanDeviceFeatures::structureType] = AkariVulkanDeviceStructureData(ptr);
					return ptr;
				}
			}
		private:
			std::unordered_map<vk::StructureType, AkariVulkanDeviceStructureData> m_Data;
		};

		class AkariVulkanDeviceQueueDesc {
			uint32_t m_QueueFamilyIndex;
			std::vector<float> m_QueuePriorities;
		};
		class AkariVulkanDeviceDesc {
		public:
			 AkariVulkanDeviceDesc() noexcept: m_FeaturesList{} {}
			~AkariVulkanDeviceDesc() noexcept {}
		private:
			AkariVulkanDeviceFeaturesList m_FeaturesList = {};
			std::unordered_set<std::string> m_EnabledExtensionNames = {};
			std::vector<AkariVulkanDeviceQueueDesc> m_DeviceQueueDesc = {};
		};
		class AkariVulkanDevice {
		public:
			template<typename VulkanDeviceFeatures> auto GetFeatures()const noexcept -> VulkanDeviceFeatures
			{
				auto features = VulkanDeviceFeatures();
				(void)m_FeaturesList.GetFeatures(features);
				return features;
			}

		private:
			AkariVulkanDeviceFeaturesList m_FeaturesList;
		};
	}
}
#endif
