#ifndef AKARI_VK_CORE_AKARI_CORE_EXTENSION_UTILS_H
#define AKARI_VK_CORE_AKARI_CORE_EXTENSION_UTILS_H
#include <Akari/Graphics/Vulkan/Core/AkariVKCoreExtension.h>
#include <Akari/Core/AkariCoreUtility.h>
AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_BEGIN
// features unnecessary
template <typename SrcFeaturesTupleT, typename DstFeaturesTupleT = void>
struct AkariVKExtensionFeaturesRemoveUnnecessary;

template <template <typename...> typename SrcFeaturesTuple, typename DstFeaturesTupleT, typename ChkFeaturesT, typename... FeaturesT>
struct AkariVKExtensionFeaturesRemoveUnnecessary<SrcFeaturesTuple<ChkFeaturesT, FeaturesT...>, DstFeaturesTupleT>
{
    using type =
        typename AkariVKExtensionFeaturesRemoveUnnecessary<
            SrcFeaturesTuple<FeaturesT...>,
            std::conditional_t<
                std::is_same_v<ChkFeaturesT, AkariVKExtensionFeaturesNotNecessary>,
                DstFeaturesTupleT, typename Akari::Core::add_tuple_right_1<DstFeaturesTupleT, ChkFeaturesT>::type>>::type;
};

template <template <typename...> typename SrcFeaturesTuple, typename DstFeaturesTupleT, typename ChkFeaturesT>
struct AkariVKExtensionFeaturesRemoveUnnecessary<SrcFeaturesTuple<ChkFeaturesT>, DstFeaturesTupleT>
{
    using type =
        std::conditional_t<
            std::is_same_v<ChkFeaturesT, AkariVKExtensionFeaturesNotNecessary>,
            DstFeaturesTupleT,
            typename Akari::Core::add_tuple_right_1<DstFeaturesTupleT, ChkFeaturesT>::type>;
};

// features 2tuple
template <typename AkariVKExtensionFlagsIndexSequence>
struct AkariVKExtensionFlagsIndexSequneces2FeaturesTuple;

template <unsigned int... Indices>
struct AkariVKExtensionFlagsIndexSequneces2FeaturesTuple<std::integer_sequence<unsigned int, Indices...>>
{
    using type = typename AkariVKExtensionFeaturesRemoveUnnecessary<std::tuple<typename AkariVKExtensionFeaturesTraits<
        static_cast<AkariVKExtensionFlags>(Indices)>::type...>>::type;
};

// required extension count
template <typename AkariVKExtensionTraitsLikeT>
struct AkariVKExtensionTraitsRequiredExtensionFlags2IndexSequence : Akari::Core::static_const_array_to_integer_sequence<AkariVKExtensionFlags,
                                                                                                                        std::size(AkariVKExtensionTraitsLikeT::required_extension_flags),
                                                                                                                        AkariVKExtensionTraitsLikeT::required_extension_flags,
                                                                                                                        unsigned int>
{
};

template <typename AkariVKExtensionTraitsLike>
struct AkariVKExtensionTraitsRequiredExtensionFlags2FeaturesTuple : AkariVKExtensionFlagsIndexSequneces2FeaturesTuple<typename AkariVKExtensionTraitsRequiredExtensionFlags2IndexSequence<AkariVKExtensionTraitsLike>::type>
{
};

template <typename AkariVKExtensionTraitsLikeT>
struct AkariVKExtensionTraitsDependedExtensionFlags2IndexSequence : Akari::Core::static_const_array_to_integer_sequence<AkariVKExtensionFlags, std::size(AkariVKExtensionTraitsLikeT::depended_extension_flags), AkariVKExtensionTraitsLikeT::depended_extension_flags, unsigned int>
{
};

template <typename AkariVKExtensionTraitsLike>
struct AkariVKExtensionTraitsDependedExtensionFlags2FeaturesTuple : AkariVKExtensionFlagsIndexSequneces2FeaturesTuple<typename AkariVKExtensionTraitsDependedExtensionFlags2IndexSequence<AkariVKExtensionTraitsLike>::type>
{
};

template <AkariVKExtensionFlags... ExtensionFlags>
struct AkariVKExtensionListTraits;

template <typename RequestedFlagsSet>
struct AkariVKExtensionListTraitsRequestedImpl;
template <unsigned int... RequestedFlagsIndices>
struct AkariVKExtensionListTraitsRequestedImpl<
    std::integer_sequence<unsigned int, RequestedFlagsIndices...>>
{
    static inline constexpr AkariVKExtensionFlags requested_extension_flags[] = {
        static_cast<AkariVKExtensionFlags>(RequestedFlagsIndices)...};
};

template <typename RequiredFlagsSet>
struct AkariVKExtensionListTraitsRequiredImpl1;
template <unsigned int... RequiredFlagsIndices>
struct AkariVKExtensionListTraitsRequiredImpl1<
    std::integer_sequence<unsigned int, RequiredFlagsIndices...>>
{
    static inline constexpr AkariVKExtensionFlags required_extension_flags[] =
        {
            static_cast<AkariVKExtensionFlags>(RequiredFlagsIndices)...};
};

template <typename... RequiredFlagsSets>
struct AkariVKExtensionListTraitsRequiredImpl2
    : AkariVKExtensionListTraitsRequiredImpl1<typename Akari::Core::merge_integer_sequence_sets<RequiredFlagsSets...>::type>
{
};

template <typename DependedFlagsSet>
struct AkariVKExtensionListTraitsDependedImpl1;
template <unsigned int... DependedFlagsIndices>
struct AkariVKExtensionListTraitsDependedImpl1<
    std::integer_sequence<unsigned int, DependedFlagsIndices...>>
{
    static inline constexpr AkariVKExtensionFlags depended_extension_flags[] =
        {
            static_cast<AkariVKExtensionFlags>(DependedFlagsIndices)...};
};

template <typename... DependedFlagsSets>
struct AkariVKExtensionListTraitsDependedImpl2
    : AkariVKExtensionListTraitsDependedImpl1<typename Akari::Core::merge_integer_sequence_sets<DependedFlagsSets...>::type>
{
};

template <unsigned int... SupportedVersions>
struct AkariVKExtensionListTraitsSupportedImpl1;
template <unsigned int SupportedVersion1, unsigned int SupportedVersion2>
struct AkariVKExtensionListTraitsSupportedImpl1<SupportedVersion1, SupportedVersion2>
{
    static inline constexpr uint32_t required_core_version = std::max<unsigned int>(SupportedVersion1, SupportedVersion2);
};
template <unsigned int SupportedVersion1, unsigned int... SupportedVersions2>
struct AkariVKExtensionListTraitsSupportedImpl1<SupportedVersion1, SupportedVersions2...>
{
    static inline constexpr uint32_t required_core_version = std::max<unsigned int>(SupportedVersion1, AkariVKExtensionListTraitsSupportedImpl1<SupportedVersions2...>::required_core_version);
};

template <unsigned int SupportedVersion>
struct AkariVKExtensionListTraitsSupportedImpl1<SupportedVersion>
{
    static inline constexpr uint32_t required_core_version = SupportedVersion;
};
template <AkariVKExtensionFlags... SupportedFlags>
struct AkariVKExtensionListTraitsSupportedImpl2
    : AkariVKExtensionListTraitsSupportedImpl1<AkariVKExtensionTraits<SupportedFlags>::required_core_version...>
{
};

template <AkariVKExtensionFlags... ExtensionFlags>
struct AkariVKExtensionListTraits : AkariVKExtensionListTraitsRequestedImpl<std::integer_sequence<unsigned int, static_cast<unsigned int>(ExtensionFlags)...>>,
                                    AkariVKExtensionListTraitsRequiredImpl2<typename AkariVKExtensionTraitsRequiredExtensionFlags2IndexSequence<AkariVKExtensionTraits<ExtensionFlags>>::type...>,
                                    AkariVKExtensionListTraitsDependedImpl2<typename AkariVKExtensionTraitsDependedExtensionFlags2IndexSequence<AkariVKExtensionTraits<ExtensionFlags>>::type...>,
                                    AkariVKExtensionListTraitsSupportedImpl2<ExtensionFlags...>
{};


AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_END
#endif