#include <Akari/Graphics/Vulkan/Core/AkariVKCoreExtensionUtils.h>
#include <iostream>
#include <tuple>
#include <array>
template<unsigned int ...Indices>
void PrintExtensionFlagsSequence(std::integer_sequence<unsigned int, Indices...>)
{
    using swallow = int[];
    (void)swallow {
        ((void)(std::cout << Akari::Graphics::Vulkan::Core::Test::to_string
         (static_cast<Akari::Graphics::Vulkan::Core::Test::AkariVKExtensionFlags>
         (Indices)) << std::endl), 0)...
    };
}
struct TestDevice {
    using extension_traits = typename Akari::Graphics::Vulkan::Core::AkariVKExtensionListTraits <
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_KHR_dynamic_rendering,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_opacity_micromap,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_mesh_shader,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library
    >;
public:
    Akari::Graphics::Vulkan::Core::AkariVKExtensionTraitsDependedExtensionFlags2FeaturesTuple<extension_traits>::type v;
};
int main(int argc, const char* argv[])
{
    using namespace Akari::Graphics::Vulkan::Core;

    std::tuple_element<0,typename AkariVKExtensionTraitsDependedExtensionFlags2FeaturesTuple<AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline>>::type>::type v0;
    std::tuple_element<1,typename AkariVKExtensionTraitsDependedExtensionFlags2FeaturesTuple<AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline>>::type>::type v1;
    std::tuple_element<2,typename AkariVKExtensionTraitsDependedExtensionFlags2FeaturesTuple<AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline>>::type>::type v2;
    std::tuple_element<3,typename AkariVKExtensionTraitsDependedExtensionFlags2FeaturesTuple<AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline>>::type>::type v3;
    std::tuple_element<4,typename AkariVKExtensionTraitsDependedExtensionFlags2FeaturesTuple<AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline>>::type>::type v4;

    AkariVKExtensionFlagsIndexSequneces2FeaturesTuple <
        std::integer_sequence<
        unsigned int,
        static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline),
        static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_ray_query)
        >
    >::type v111;

    AkariVKExtensionTraitsRequiredExtensionFlags2FeaturesTuple<AkariVKExtensionListTraits<
        AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
        AkariVKExtensionFlags::eVK_EXT_opacity_micromap,
        AkariVKExtensionFlags::eVK_EXT_mesh_shader>
    >::type v222;

    using extension_list_traits = AkariVKExtensionListTraits<
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_KHR_dynamic_rendering,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_opacity_micromap,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_mesh_shader,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3,
        Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library
    >;

    AkariVKExtensionTraitsDependedExtensionFlags2FeaturesTuple<
        extension_list_traits
    >::type v333;

    extension_list_traits::depended_extension_flags;
    std::cout << VK_API_VERSION_MAJOR(extension_list_traits::required_core_version) << std::endl;
    std::cout << VK_API_VERSION_MINOR(extension_list_traits::required_core_version) << std::endl;
    std::cout << VK_API_VERSION_PATCH(extension_list_traits::required_core_version) << std::endl;


    std::tuple_element<0, decltype(v333)>::type v11110;
    std::tuple_element<1, decltype(v333)>::type v11111;
    std::tuple_element<2, decltype(v333)>::type v11112;
    std::tuple_element<3, decltype(v333)>::type v11113;
    std::tuple_element<4, decltype(v333)>::type v11114;
    std::tuple_element<5, decltype(v333)>::type v11115;
    std::tuple_element<6, decltype(v333)>::type v11116;


	return 0;
}