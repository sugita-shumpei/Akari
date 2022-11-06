#ifndef AKARI_VK_CORE_AKARI_CORE_EXTENSION_UTILS_H
#define AKARI_VK_CORE_AKARI_CORE_EXTENSION_UTILS_H
#include <Akari/Graphics/Vulkan/Core/AkariVKCoreExtension.h>
#include <Akari/Core/AkariCoreUtility.h>
#include <utility>
#include <variant>
AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_BEGIN
namespace {
	template<AkariVKExtensionFlags ExtensionFlagList>
	struct has_extension_features :std::bool_constant<!std::is_same<typename AkariVKExtensionFeaturesTraits<ExtensionFlagList>::type, AkariVKExtensionFeaturesNotNecessary>::value> {};
	template<>
	struct has_extension_features<AkariVKExtensionFlags::eCount>:std::false_type{};
	
	template<typename IndexSequence>
	struct index_sequence_remove_not_necessary {
	public:
		using type = typename Akari::Core::remove_integer_sequence<IndexSequence, AkariVKExtensionFlags, has_extension_features>::type;
	};

	template<typename IndexSequence>
	struct index_sequence_to_features_tuple_impl;

	template<unsigned int... Indices>
	struct index_sequence_to_features_tuple_impl<std::integer_sequence<unsigned int,Indices...>> {
		static_assert(has_extension_features<AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2>::value);
		using type = std::tuple<typename AkariVKExtensionFeaturesTraits<static_cast<AkariVKExtensionFlags>(Indices)>::type ...>;

	};
	template<>
	struct index_sequence_to_features_tuple_impl<void> {
		using type = void;
	};

	template<typename IndexSequence>
	struct index_sequence_to_features_tuple : index_sequence_to_features_tuple_impl<typename index_sequence_remove_not_necessary<IndexSequence>::type> {};
	
	template<typename FeaturesTuple>
	struct link_features_tuple_impl;

	template<typename ...FeaturesList>
	struct link_features_tuple_impl<std::tuple<FeaturesList...>> {
	private:
		using IndexSequence = std::index_sequence<sizeof...(FeaturesList)>;
		template<size_t ...Indices>
		static void eval_impl(std::tuple<FeaturesList...>& tuple, std::index_sequence<Indices...>) {
			void* pNextList[sizeof...(Indices)] = {
				static_cast<void*>(& static_cast<std::tuple_element_t<Indices,std::tuple<FeaturesList...>>&>(std::get<Indices>(tuple)))...
			};
			void** ppNextList[sizeof...(Indices)] = {
				static_cast<void**>(&static_cast<std::tuple_element_t<Indices,std::tuple<FeaturesList...>>&>(std::get<Indices>(tuple)).pNext)...
			};
			for (auto i = 0; i < sizeof...(FeaturesList)-1; ++i) {
				*ppNextList[i] = pNextList[i+1];
			}
			*ppNextList[sizeof...(FeaturesList) - 1] = nullptr;
		}
	public:
		static void eval(std::tuple<FeaturesList...>& tuple) {
			eval_impl(tuple, std::make_index_sequence<sizeof...(FeaturesList)>());
		}
	};

	template<typename FeaturesTuple>
	inline void LinkFeaturesTuple(FeaturesTuple& tuple) {
		link_features_tuple_impl<FeaturesTuple>::eval(tuple);
		return;
	}


	template<AkariVKExtensionFlags... ExtensionFlagList>
	struct AkariVKExtensionListTraits
	{
	private:
		static inline constexpr std::array<AkariVKExtensionFlags,sizeof...(ExtensionFlagList)> requested_extension_flags =
		{
			ExtensionFlagList...
		};
		static inline constexpr auto internal_get_depended_extension_capacity()->uint32_t
		{
			uint32_t res = 0;
			for (uint32_t i = 0; i < sizeof...(ExtensionFlagList); ++i)
			{
				res += to_traits(requested_extension_flags[i]).depended_extension_count;
			}
			return res;
		}
		static inline constexpr size_t internal_depended_extension_capacity = internal_get_depended_extension_capacity();
		static inline constexpr auto internal_get_depended_extension_size()->uint32_t {
			uint32_t depended_extension_count = 0;
			std::array<AkariVKExtensionFlags, internal_depended_extension_capacity> depended_extension_flags = {};
			for (uint32_t i = 0; i < sizeof...(ExtensionFlagList); ++i)
			{
				auto extension_traits = to_traits(requested_extension_flags[i]);
				for (uint32_t j = 0; j < extension_traits.depended_extension_count; ++j)
				{
					auto depended_extension_flag = extension_traits.depended_extension_flags[j];
					bool isFound = false;
					for (uint32_t k = 0; k < depended_extension_count; ++k)
					{
						if (depended_extension_flags[k] == depended_extension_flag) {
							isFound = true;
						}
					}
					if (!isFound) {
						depended_extension_flags[depended_extension_count] = depended_extension_flag;
						depended_extension_count++;
					}
				}
			}
			return depended_extension_count;
		}
		static inline constexpr auto internal_get_depended_instance_extension_size()->uint32_t {
			uint32_t depended_extension_count = 0;
			std::array<AkariVKExtensionFlags, internal_depended_extension_capacity> depended_extension_flags = {};
			for (uint32_t i = 0; i < sizeof...(ExtensionFlagList); ++i)
			{
				auto extension_traits = to_traits(requested_extension_flags[i]);
				for (uint32_t j = 0; j < extension_traits.depended_extension_count; ++j)
				{
					auto depended_extension_flag = extension_traits.depended_extension_flags[j];
					auto depended_extension_traits = to_traits(depended_extension_flag);
					if (depended_extension_traits.extension_type == AkariVKExtensionType::eDevice) {
						continue;
					}
					bool isFound = false;
					for (uint32_t k = 0; k < depended_extension_count; ++k)
					{
						if (depended_extension_flags[k] == depended_extension_flag) {
							isFound = true;
						}
					}
					if (!isFound) {
						depended_extension_flags[depended_extension_count] = depended_extension_flag;
						depended_extension_count++;
					}
				}
			}
			return depended_extension_count;
		}
		static inline constexpr size_t internal_depended_extension_size     = internal_get_depended_extension_size();
		static inline constexpr size_t internal_depended_instance_extension_size = internal_get_depended_instance_extension_size();
		static inline constexpr size_t internal_depended_device_extension_size = internal_depended_extension_size - internal_depended_instance_extension_size;
		static inline constexpr auto internal_get_depended_instance_extension_flags()->std::array<AkariVKExtensionFlags, internal_depended_instance_extension_size+1> {
			uint32_t depended_extension_count = 0;
			std::array<AkariVKExtensionFlags, internal_depended_instance_extension_size+1>  depended_extension_flags = {
				AkariVKExtensionFlags::eCount
			};
			for (uint32_t i = 0; i < sizeof...(ExtensionFlagList); ++i)
			{
				auto extension_traits = to_traits(requested_extension_flags[i]);
				for (uint32_t j = 0; j < extension_traits.depended_extension_count; ++j)
				{
					auto depended_extension_flag = extension_traits.depended_extension_flags[j];
					auto depended_extension_traits = to_traits(depended_extension_flag);
					if (depended_extension_traits.extension_type == AkariVKExtensionType::eDevice) {
						continue;
					}
					bool isFound = false;
					for (uint32_t k = 0; k < depended_extension_count; ++k)
					{
						if (depended_extension_flags[k+1] == depended_extension_flag) {
							isFound = true;
						}
					}
					if (!isFound) {
						depended_extension_flags[depended_extension_count+1] = depended_extension_flag;
						depended_extension_count++;
					}
				}
			}
			return depended_extension_flags;
		}
		static inline constexpr auto internal_get_depended_device_extension_flags()->std::array<AkariVKExtensionFlags, internal_depended_device_extension_size+1> {
			uint32_t depended_extension_count = 0;
			std::array<AkariVKExtensionFlags, internal_depended_device_extension_size+1>  depended_extension_flags = {
				AkariVKExtensionFlags::eCount
			};
			for (uint32_t i = 0; i < sizeof...(ExtensionFlagList); ++i)
			{
				auto extension_traits = to_traits(requested_extension_flags[i]);
				for (uint32_t j = 0; j < extension_traits.depended_extension_count; ++j)
				{
					if (extension_traits.extension_type == AkariVKExtensionType::eInstance) { continue; }
					auto depended_extension_flag = extension_traits.depended_extension_flags[j];
					auto depended_extension_traits = to_traits(depended_extension_flag);
					if (depended_extension_traits.extension_type == AkariVKExtensionType::eInstance) {
						continue;
					}
					bool isFound = false;
					for (uint32_t k = 0; k < depended_extension_count; ++k)
					{
						if (depended_extension_flags[k+1] == depended_extension_flag) {
							isFound = true;
						}
					}
					if (!isFound) {
						depended_extension_flags[depended_extension_count+1] = depended_extension_flag;
						depended_extension_count++;
					}
				}
			}
			return depended_extension_flags;
		}
		static inline constexpr std::array<AkariVKExtensionFlags, internal_depended_instance_extension_size+1> depended_instance_extension_flags = internal_get_depended_instance_extension_flags();
		static inline constexpr std::array<AkariVKExtensionFlags, internal_depended_device_extension_size+1>   depended_device_extension_flags   = internal_get_depended_device_extension_flags();

		static inline constexpr std::array<const char*, internal_depended_instance_extension_size + 1> depended_instance_extension_names = to_string_array(depended_instance_extension_flags);
		static inline constexpr std::array<const char*, internal_depended_device_extension_size + 1> depended_device_extension_names = to_string_array(depended_device_extension_flags);

		template<typename AkariVKExtensionFlagsArray>
		static inline constexpr auto internal_get_not_promoted_extension_size(const AkariVKExtensionFlagsArray& extensionArray,uint32_t promotedVersion, uint32_t offset = 0) noexcept -> uint32_t {
			uint32_t size = 0;
			for (auto i = offset; i < std::size(extensionArray); ++i)
			{
				auto extension_traits = to_traits(extensionArray[i]);
				if ( extension_traits.is_partially_promoted || (extension_traits.promoted_core_version > promotedVersion))
				{
					++size;
				}
			}
			return size;
		}
		template<uint32_t ArrayCapacity, typename AkariVKExtensionFlagsArray>
		static inline constexpr auto internal_get_not_promoted_extension_flags(const AkariVKExtensionFlagsArray& extensionArray, uint32_t promotedVersion, uint32_t offset = 0)->std::array<AkariVKExtensionFlags, ArrayCapacity+1>{
			std::array<AkariVKExtensionFlags, ArrayCapacity+1> extensionFlags = {
				AkariVKExtensionFlags::eCount
			};
			uint32_t count = 0;
			for (auto i = offset; i < std::size(extensionArray); ++i)
			{
				auto extension_traits = to_traits(extensionArray[i]);
				if (extension_traits.is_partially_promoted || (extension_traits.promoted_core_version > promotedVersion))
				{
					extensionFlags[count + 1] = extensionArray[i];
					count++;
				}
			}
			return extensionFlags;
		}

		static inline constexpr size_t internal_depended_and_vulkan_1_1_not_promoted_instance_extension_size = internal_get_not_promoted_extension_size(depended_instance_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, 1);
		static inline constexpr size_t internal_depended_and_vulkan_1_2_not_promoted_instance_extension_size = internal_get_not_promoted_extension_size(depended_instance_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, 1);
		static inline constexpr size_t internal_depended_and_vulkan_1_3_not_promoted_instance_extension_size = internal_get_not_promoted_extension_size(depended_instance_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, 1);
		static inline constexpr size_t internal_depended_and_vulkan_1_1_not_promoted_device_extension_size = internal_get_not_promoted_extension_size(depended_device_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, 1);
		static inline constexpr size_t internal_depended_and_vulkan_1_2_not_promoted_device_extension_size = internal_get_not_promoted_extension_size(depended_device_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, 1);
		static inline constexpr size_t internal_depended_and_vulkan_1_3_not_promoted_device_extension_size = internal_get_not_promoted_extension_size(depended_device_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, 1);

		static inline constexpr std::array<AkariVKExtensionFlags, internal_depended_and_vulkan_1_1_not_promoted_instance_extension_size+1> depended_and_vulkan_1_1_not_promoted_instance_extension_flags = internal_get_not_promoted_extension_flags<internal_depended_and_vulkan_1_1_not_promoted_instance_extension_size>(depended_instance_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, 1);
		static inline constexpr std::array<AkariVKExtensionFlags, internal_depended_and_vulkan_1_2_not_promoted_instance_extension_size+1> depended_and_vulkan_1_2_not_promoted_instance_extension_flags = internal_get_not_promoted_extension_flags<internal_depended_and_vulkan_1_2_not_promoted_instance_extension_size>(depended_instance_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, 1);
		static inline constexpr std::array<AkariVKExtensionFlags, internal_depended_and_vulkan_1_3_not_promoted_instance_extension_size+1> depended_and_vulkan_1_3_not_promoted_instance_extension_flags = internal_get_not_promoted_extension_flags<internal_depended_and_vulkan_1_3_not_promoted_instance_extension_size>(depended_instance_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, 1);
		
		static inline constexpr std::array<AkariVKExtensionFlags, internal_depended_and_vulkan_1_1_not_promoted_device_extension_size + 1> depended_and_vulkan_1_1_not_promoted_device_extension_flags = internal_get_not_promoted_extension_flags<internal_depended_and_vulkan_1_1_not_promoted_device_extension_size>(depended_device_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, 1);
		static inline constexpr std::array<AkariVKExtensionFlags, internal_depended_and_vulkan_1_2_not_promoted_device_extension_size + 1> depended_and_vulkan_1_2_not_promoted_device_extension_flags = internal_get_not_promoted_extension_flags<internal_depended_and_vulkan_1_2_not_promoted_device_extension_size>(depended_device_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, 1);
		static inline constexpr std::array<AkariVKExtensionFlags, internal_depended_and_vulkan_1_3_not_promoted_device_extension_size + 1> depended_and_vulkan_1_3_not_promoted_device_extension_flags = internal_get_not_promoted_extension_flags<internal_depended_and_vulkan_1_3_not_promoted_device_extension_size>(depended_device_extension_flags, AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, 1);

		static inline constexpr std::array<const char*, internal_depended_and_vulkan_1_1_not_promoted_device_extension_size + 1> depended_and_vulkan_1_1_not_promoted_device_extension_names = to_string_array(depended_and_vulkan_1_1_not_promoted_device_extension_flags);
		static inline constexpr std::array<const char*, internal_depended_and_vulkan_1_2_not_promoted_device_extension_size + 1> depended_and_vulkan_1_2_not_promoted_device_extension_names = to_string_array(depended_and_vulkan_1_2_not_promoted_device_extension_flags);
		static inline constexpr std::array<const char*, internal_depended_and_vulkan_1_3_not_promoted_device_extension_size + 1> depended_and_vulkan_1_3_not_promoted_device_extension_names = to_string_array(depended_and_vulkan_1_3_not_promoted_device_extension_flags);

		static inline constexpr std::array<const char*, internal_depended_and_vulkan_1_1_not_promoted_instance_extension_size + 1> depended_and_vulkan_1_1_not_promoted_instance_extension_names = to_string_array(depended_and_vulkan_1_1_not_promoted_instance_extension_flags);
		static inline constexpr std::array<const char*, internal_depended_and_vulkan_1_2_not_promoted_instance_extension_size + 1> depended_and_vulkan_1_2_not_promoted_instance_extension_names = to_string_array(depended_and_vulkan_1_2_not_promoted_instance_extension_flags);
		static inline constexpr std::array<const char*, internal_depended_and_vulkan_1_3_not_promoted_instance_extension_size + 1> depended_and_vulkan_1_3_not_promoted_instance_extension_names = to_string_array(depended_and_vulkan_1_3_not_promoted_instance_extension_flags);
	
public:
		static constexpr auto EnumerateRequiredInstanceExtensionSize() { return std::size(depended_instance_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan10InstanceExtensionSize() { return std::size(depended_instance_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan11InstanceExtensionSize() { return std::size(depended_and_vulkan_1_1_not_promoted_instance_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan12InstanceExtensionSize() { return std::size(depended_and_vulkan_1_2_not_promoted_instance_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan13InstanceExtensionSize() { return std::size(depended_and_vulkan_1_3_not_promoted_instance_extension_flags) - 1; }

		static constexpr auto EnumerateRequiredInstanceExtensionsAreEmpty() { return std::size(depended_instance_extension_flags) == 1; }
		static constexpr auto EnumerateRequiredVulkan10InstanceExtensionsAreEmpty() { return std::size(depended_instance_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan11InstanceExtensionsAreEmpty() { return std::size(depended_and_vulkan_1_1_not_promoted_instance_extension_flags) == 1; }
		static constexpr auto EnumerateRequiredVulkan12InstanceExtensionsAreEmpty() { return std::size(depended_and_vulkan_1_2_not_promoted_instance_extension_flags) == 1; }
		static constexpr auto EnumerateRequiredVulkan13InstanceExtensionsAreEmpty() { return std::size(depended_and_vulkan_1_3_not_promoted_instance_extension_flags) == 1; }

		static constexpr auto EnumerateRequiredInstanceExtensionFlagStorageBegin() { return std::begin(depended_instance_extension_flags) + 1; }
		static constexpr auto EnumerateRequiredVulkan10InstanceExtensionFlagStorageBegin() { return std::begin(depended_instance_extension_flags) + 1; }
		static constexpr auto EnumerateRequiredVulkan11InstanceExtensionFlagStorageBegin() { return std::begin(depended_and_vulkan_1_1_not_promoted_instance_extension_flags) + 1; }
		static constexpr auto EnumerateRequiredVulkan12InstanceExtensionFlagStorageBegin() { return std::begin(depended_and_vulkan_1_2_not_promoted_instance_extension_flags) + 1; }
		static constexpr auto EnumerateRequiredVulkan13InstanceExtensionFlagStorageBegin() { return std::begin(depended_and_vulkan_1_3_not_promoted_instance_extension_flags) + 1; }

		static constexpr auto EnumerateRequiredInstanceExtensionFlagStorageEnd() { return std::end(depended_instance_extension_flags); }
		static constexpr auto EnumerateRequiredVulkan10InstanceExtensionFlagStorageEnd() { return std::end(depended_instance_extension_flags); }
		static constexpr auto EnumerateRequiredVulkan11InstanceExtensionFlagStorageEnd() { return std::end(depended_and_vulkan_1_1_not_promoted_instance_extension_flags); }
		static constexpr auto EnumerateRequiredVulkan12InstanceExtensionFlagStorageEnd() { return std::end(depended_and_vulkan_1_2_not_promoted_instance_extension_flags); }
		static constexpr auto EnumerateRequiredVulkan13InstanceExtensionFlagStorageEnd() { return std::end(depended_and_vulkan_1_3_not_promoted_instance_extension_flags); }

		static constexpr auto EnumerateRequiredInstanceExtensionNameStorageBegin() { return std::begin(depended_instance_extension_names) + 1; }
		static constexpr auto EnumerateRequiredVulkan10InstanceExtensionNameStorageBegin() { return std::begin(depended_instance_extension_names) + 1; }
		static constexpr auto EnumerateRequiredVulkan11InstanceExtensionNameStorageBegin() { return std::begin(depended_and_vulkan_1_1_not_promoted_instance_extension_names) + 1; }
		static constexpr auto EnumerateRequiredVulkan12InstanceExtensionNameStorageBegin() { return std::begin(depended_and_vulkan_1_2_not_promoted_instance_extension_names) + 1; }
		static constexpr auto EnumerateRequiredVulkan13InstanceExtensionNameStorageBegin() { return std::begin(depended_and_vulkan_1_3_not_promoted_instance_extension_names) + 1; }

		static constexpr auto EnumerateRequiredInstanceExtensionNameStorageEnd() { return std::end(depended_instance_extension_names); }
		static constexpr auto EnumerateRequiredVulkan10InstanceExtensionNameStorageEnd() { return std::end(depended_instance_extension_names); }
		static constexpr auto EnumerateRequiredVulkan11InstanceExtensionNameStorageEnd() { return std::end(depended_and_vulkan_1_1_not_promoted_instance_extension_names); }
		static constexpr auto EnumerateRequiredVulkan12InstanceExtensionNameStorageEnd() { return std::end(depended_and_vulkan_1_2_not_promoted_instance_extension_names); }
		static constexpr auto EnumerateRequiredVulkan13InstanceExtensionNameStorageEnd() { return std::end(depended_and_vulkan_1_3_not_promoted_instance_extension_names); }
		
		static constexpr auto EnumerateRequiredDeviceExtensionSize() { return std::size(depended_device_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan10DeviceExtensionSize() { return std::size(depended_device_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan11DeviceExtensionSize() { return std::size(depended_and_vulkan_1_1_not_promoted_device_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan12DeviceExtensionSize() { return std::size(depended_and_vulkan_1_2_not_promoted_device_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan13DeviceExtensionSize() { return std::size(depended_and_vulkan_1_3_not_promoted_device_extension_flags) - 1; }

		static constexpr auto EnumerateRequiredDeviceExtensionsAreEmpty() { return std::size(depended_device_extension_flags) == 1; }
		static constexpr auto EnumerateRequiredVulkan10DeviceExtensionsAreEmpty() { return std::size(depended_device_extension_flags) - 1; }
		static constexpr auto EnumerateRequiredVulkan11DeviceExtensionsAreEmpty() { return std::size(depended_and_vulkan_1_1_not_promoted_device_extension_flags) == 1; }
		static constexpr auto EnumerateRequiredVulkan12DeviceExtensionsAreEmpty() { return std::size(depended_and_vulkan_1_2_not_promoted_device_extension_flags) == 1; }
		static constexpr auto EnumerateRequiredVulkan13DeviceExtensionsAreEmpty() { return std::size(depended_and_vulkan_1_3_not_promoted_device_extension_flags) == 1; }

		static constexpr auto EnumerateRequiredDeviceExtensionFlagStorageBegin() { return std::begin(depended_device_extension_flags) + 1; }
		static constexpr auto EnumerateRequiredVulkan10DeviceExtensionFlagStorageBegin() { return std::begin(depended_device_extension_flags) + 1; }
		static constexpr auto EnumerateRequiredVulkan11DeviceExtensionFlagStorageBegin() { return std::begin(depended_and_vulkan_1_1_not_promoted_device_extension_flags) + 1; }
		static constexpr auto EnumerateRequiredVulkan12DeviceExtensionFlagStorageBegin() { return std::begin(depended_and_vulkan_1_2_not_promoted_device_extension_flags) + 1; }
		static constexpr auto EnumerateRequiredVulkan13DeviceExtensionFlagStorageBegin() { return std::begin(depended_and_vulkan_1_3_not_promoted_device_extension_flags) + 1; }

		static constexpr auto EnumerateRequiredDeviceExtensionFlagStorageEnd() { return std::end(depended_device_extension_flags); }
		static constexpr auto EnumerateRequiredVulkan10DeviceExtensionFlagStorageEnd() { return std::end(depended_device_extension_flags); }
		static constexpr auto EnumerateRequiredVulkan11DeviceExtensionFlagStorageEnd() { return std::end(depended_and_vulkan_1_1_not_promoted_device_extension_flags); }
		static constexpr auto EnumerateRequiredVulkan12DeviceExtensionFlagStorageEnd() { return std::end(depended_and_vulkan_1_2_not_promoted_device_extension_flags); }
		static constexpr auto EnumerateRequiredVulkan13DeviceExtensionFlagStorageEnd() { return std::end(depended_and_vulkan_1_3_not_promoted_device_extension_flags); }

		static constexpr auto EnumerateRequiredDeviceExtensionNameStorageBegin() { return std::begin(depended_device_extension_names) + 1; }
		static constexpr auto EnumerateRequiredVulkan10DeviceExtensionNameStorageBegin() { return std::begin(depended_device_extension_names) + 1; }
		static constexpr auto EnumerateRequiredVulkan11DeviceExtensionNameStorageBegin() { return std::begin(depended_and_vulkan_1_1_not_promoted_device_extension_names) + 1; }
		static constexpr auto EnumerateRequiredVulkan12DeviceExtensionNameStorageBegin() { return std::begin(depended_and_vulkan_1_2_not_promoted_device_extension_names) + 1; }
		static constexpr auto EnumerateRequiredVulkan13DeviceExtensionNameStorageBegin() { return std::begin(depended_and_vulkan_1_3_not_promoted_device_extension_names) + 1; }

		static constexpr auto EnumerateRequiredDeviceExtensionNameStorageEnd() { return std::end(depended_device_extension_names); }
		static constexpr auto EnumerateRequiredVulkan10DeviceExtensionNameStorageEnd() { return std::end(depended_device_extension_names); }
		static constexpr auto EnumerateRequiredVulkan11DeviceExtensionNameStorageEnd() { return std::end(depended_and_vulkan_1_1_not_promoted_device_extension_names); }
		static constexpr auto EnumerateRequiredVulkan12DeviceExtensionNameStorageEnd() { return std::end(depended_and_vulkan_1_2_not_promoted_device_extension_names); }
		static constexpr auto EnumerateRequiredVulkan13DeviceExtensionNameStorageEnd() { return std::end(depended_and_vulkan_1_3_not_promoted_device_extension_names); }
		//
		static auto EnumerateRequiredInstanceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredInstanceExtensionNameStorageBegin(),
				EnumerateRequiredInstanceExtensionNameStorageEnd()
				);
		}
		static auto EnumerateRequiredVulkan10InstanceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredVulkan10InstanceExtensionNameStorageBegin(),
				EnumerateRequiredVulkan10InstanceExtensionNameStorageEnd()
				);
		}
		static auto EnumerateRequiredVulkan11InstanceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredVulkan11InstanceExtensionNameStorageBegin(),
				EnumerateRequiredVulkan11InstanceExtensionNameStorageEnd()
				);
		}
		static auto EnumerateRequiredVulkan12InstanceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredVulkan12InstanceExtensionNameStorageBegin(),
				EnumerateRequiredVulkan12InstanceExtensionNameStorageEnd()
				);
		}
		static auto EnumerateRequiredVulkan13InstanceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredVulkan13InstanceExtensionNameStorageBegin(),
				EnumerateRequiredVulkan13InstanceExtensionNameStorageEnd()
				);
		}

		static auto EnumerateRequiredDeviceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredDeviceExtensionNameStorageBegin(),
				EnumerateRequiredDeviceExtensionNameStorageEnd()
			);
		}
		static auto EnumerateRequiredVulkan10DeviceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredVulkan10DeviceExtensionNameStorageBegin(),
				EnumerateRequiredVulkan10DeviceExtensionNameStorageEnd()
			);
		}
		static auto EnumerateRequiredVulkan11DeviceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredVulkan11DeviceExtensionNameStorageBegin(),
				EnumerateRequiredVulkan11DeviceExtensionNameStorageEnd()
				);
		}
		static auto EnumerateRequiredVulkan12DeviceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredVulkan12DeviceExtensionNameStorageBegin(),
				EnumerateRequiredVulkan12DeviceExtensionNameStorageEnd()
				);
		}
		static auto EnumerateRequiredVulkan13DeviceExtensionNames()noexcept -> std::vector<const char*> {
			return std::vector<const char*>(
				EnumerateRequiredVulkan13DeviceExtensionNameStorageBegin(),
				EnumerateRequiredVulkan13DeviceExtensionNameStorageEnd()
				);
		}

		using RequiredDeviceExtensionFlagStorageSequence = decltype(Akari::Core::convert_array_to_index_sequence<unsigned int, depended_device_extension_flags>());
		using RequiredVulkan10DeviceExtensionFlagStorageSequence = RequiredDeviceExtensionFlagStorageSequence;
		using RequiredVulkan11DeviceExtensionFlagStorageSequence = decltype(Akari::Core::convert_array_to_index_sequence<unsigned int, depended_and_vulkan_1_1_not_promoted_device_extension_flags>());
		using RequiredVulkan12DeviceExtensionFlagStorageSequence = decltype(Akari::Core::convert_array_to_index_sequence<unsigned int, depended_and_vulkan_1_2_not_promoted_device_extension_flags>());
		using RequiredVulkan13DeviceExtensionFlagStorageSequence = decltype(Akari::Core::convert_array_to_index_sequence<unsigned int, depended_and_vulkan_1_3_not_promoted_device_extension_flags>());

		//static constexpr auto EnumerateRequiredInstanceExtensionFlagStorage() { return depended_instance_extension_flags; }
		//static constexpr auto EnumerateRequiredVulkan10InstanceExtensionFlagStorage() { return depended_instance_extension_flags; }
		//static constexpr auto EnumerateRequiredVulkan11InstanceExtensionFlagStorage() { return depended_and_vulkan_1_1_not_promoted_instance_extension_flags; }
		//static constexpr auto EnumerateRequiredVulkan12InstanceExtensionFlagStorage() { return depended_and_vulkan_1_2_not_promoted_instance_extension_flags; }
		//static constexpr auto EnumerateRequiredVulkan13InstanceExtensionFlagStorage() { return depended_and_vulkan_1_3_not_promoted_instance_extension_flags; }
		//static constexpr auto EnumerateRequiredInstanceExtensionNameStorage() { return depended_instance_extension_names; }
		//static constexpr auto EnumerateRequiredVulkan10InstanceExtensionNameStorage() { return depended_instance_extension_names; }
		//static constexpr auto EnumerateRequiredVulkan11InstanceExtensionNameStorage() { return depended_and_vulkan_1_1_not_promoted_instance_extension_names; }
		//static constexpr auto EnumerateRequiredVulkan12InstanceExtensionNameStorage() { return depended_and_vulkan_1_2_not_promoted_instance_extension_names; }
		//static constexpr auto EnumerateRequiredVulkan13InstanceExtensionNameStorage() { return depended_and_vulkan_1_3_not_promoted_instance_extension_names; }

		//static constexpr auto EnumerateRequiredDeviceExtensionFlagStorage() { return depended_device_extension_flags; }
		//static constexpr auto EnumerateRequiredVulkan10DeviceExtensionFlagStorage() { return depended_device_extension_flags; }
		//static constexpr auto EnumerateRequiredVulkan11DeviceExtensionFlagStorage() { return depended_and_vulkan_1_1_not_promoted_device_extension_flags; }
		//static constexpr auto EnumerateRequiredVulkan12DeviceExtensionFlagStorage() { return depended_and_vulkan_1_2_not_promoted_device_extension_flags; }
		//static constexpr auto EnumerateRequiredVulkan13DeviceExtensionFlagStorage() { return depended_and_vulkan_1_3_not_promoted_device_extension_flags; }
		//static constexpr auto EnumerateRequiredDeviceExtensionNameStorage() { return depended_device_extension_names; }
		//static constexpr auto EnumerateRequiredVulkan10DeviceExtensionNameStorage() { return depended_device_extension_names; }
		//static constexpr auto EnumerateRequiredVulkan11DeviceExtensionNameStorage() { return depended_and_vulkan_1_1_not_promoted_device_extension_names; }
		//static constexpr auto EnumerateRequiredVulkan12DeviceExtensionNameStorage() { return depended_and_vulkan_1_2_not_promoted_device_extension_names; }
		//static constexpr auto EnumerateRequiredVulkan13DeviceExtensionNameStorage() { return depended_and_vulkan_1_3_not_promoted_device_extension_names; }

#ifdef VK_KHR_get_physical_device_properties2
		using RequiredDeviceExtensionFeaturesTuple = typename Akari::Core::add_tuple_right_1<
			vk::PhysicalDeviceFeatures2KHR,
			typename index_sequence_to_features_tuple<RequiredDeviceExtensionFlagStorageSequence>::type
		>::type;
		static auto MakeUniqueRequiredDeviceExtensionFeaturesTuple()->std::unique_ptr<RequiredDeviceExtensionFeaturesTuple>
		{
			auto features_ptr = std::make_unique<RequiredDeviceExtensionFeaturesTuple>();
			Akari::Graphics::Vulkan::Core::LinkFeaturesTuple(*features_ptr);
			return features_ptr;
		}
#else
		using RequiredDeviceExtensionFeaturesTuple = void;
#endif
		using RequiredVulkan11DeviceExtensionFeaturesTuple = RequiredDeviceExtensionFeaturesTuple;
#ifdef VK_API_VERSION_1_1
		static auto MakeUniqueRequiredVulkan11DeviceExtensionFeaturesTuple()->std::unique_ptr<RequiredVulkan11DeviceExtensionFeaturesTuple>
		{
			auto features_ptr = std::make_unique<RequiredVulkan11DeviceExtensionFeaturesTuple>();
			Akari::Graphics::Vulkan::Core::LinkFeaturesTuple(*features_ptr);
			return features_ptr;
		}
#endif
#ifdef VK_API_VERSION_1_2
		using RequiredVulkan12DeviceExtensionFeaturesTuple = typename Akari::Core::add_tuple_right_3<
			vk::PhysicalDeviceFeatures2KHR,
			vk::PhysicalDeviceVulkan11Features,
			vk::PhysicalDeviceVulkan12Features,
			typename index_sequence_to_features_tuple<RequiredVulkan12DeviceExtensionFlagStorageSequence>::type
		>::type;
		static auto MakeUniqueRequiredVulkan12DeviceExtensionFeaturesTuple()->std::unique_ptr<RequiredVulkan12DeviceExtensionFeaturesTuple>
		{
			auto features_ptr = std::make_unique<RequiredVulkan12DeviceExtensionFeaturesTuple>();
			Akari::Graphics::Vulkan::Core::LinkFeaturesTuple(*features_ptr);
			return features_ptr;
		}
#else
		using RequiredVulkan12DeviceExtensionFeaturesTuple = RequiredVulkan11DeviceExtensionFeaturesTuple;
#endif
#ifdef VK_API_VERSION_1_3
		using RequiredVulkan13DeviceExtensionFeaturesTuple = typename Akari::Core::add_tuple_right_4<
			vk::PhysicalDeviceFeatures2KHR,
			vk::PhysicalDeviceVulkan11Features,
			vk::PhysicalDeviceVulkan12Features,
			vk::PhysicalDeviceVulkan13Features,
			typename index_sequence_to_features_tuple<RequiredVulkan13DeviceExtensionFlagStorageSequence>::type
		>::type;

		static auto MakeUniqueRequiredVulkan13DeviceExtensionFeaturesTuple()->std::unique_ptr<RequiredVulkan13DeviceExtensionFeaturesTuple>
		{
			auto features_ptr = std::make_unique<RequiredVulkan13DeviceExtensionFeaturesTuple>();
			Akari::Graphics::Vulkan::Core::LinkFeaturesTuple(*features_ptr);
			return features_ptr;
		}
#else
		using RequiredVulkan13DeviceExtensionFeaturesTuple = RequiredVulkan12DeviceExtensionFeaturesTuple;
#endif
	};

}
AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_END
#endif