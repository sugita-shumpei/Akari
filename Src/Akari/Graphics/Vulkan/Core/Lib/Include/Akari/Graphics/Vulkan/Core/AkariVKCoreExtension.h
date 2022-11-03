#ifndef AKARI_GRAPHICS_VK_CORE_EXTENSION_H
#define AKARI_GRAPHICS_VK_CORE_EXTENSION_H
#include <Akari/Graphics/Vulkan/Core/AkariVKCore.h>
#include <tuple>
#define AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0 VK_MAKE_API_VERSION(0,1,0,0)
#define AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1 VK_MAKE_API_VERSION(0,1,1,0)
#define AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2 VK_MAKE_API_VERSION(0,1,2,0)
#define AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3 VK_MAKE_API_VERSION(0,1,3,0)

AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_BEGIN
namespace {
	enum class AkariVKExtensionType :unsigned short {
		eInstance,
		eDevice,
	};
	enum class AkariVKExtensionFlags :unsigned short {
		eVK_KHR_16bit_storage,
		eVK_KHR_8bit_storage,
		eVK_KHR_acceleration_structure,
		eVK_KHR_android_surface,
		eVK_KHR_bind_memory2,
		eVK_KHR_buffer_device_address,
		eVK_KHR_copy_commands2,
		eVK_KHR_create_renderpass2,
		eVK_KHR_dedicated_allocation,
		eVK_KHR_deferred_host_operations,
		eVK_KHR_depth_stencil_resolve,
		eVK_KHR_descriptor_update_template,
		eVK_KHR_device_group,
		eVK_KHR_device_group_creation,
		eVK_KHR_display,
		eVK_KHR_display_swapchain,
		eVK_KHR_draw_indirect_count,
		eVK_KHR_driver_properties,
		eVK_KHR_dynamic_rendering,
		eVK_KHR_external_fence_capabilities,
		eVK_KHR_external_fence,
		eVK_KHR_external_fence_fd,
		eVK_KHR_external_fence_win32,
		eVK_KHR_external_memory,
		eVK_KHR_external_memory_capabilities,
		eVK_KHR_external_memory_fd,
		eVK_KHR_external_memory_win32,
		eVK_KHR_external_semaphore_win32,
		eVK_KHR_external_semaphore,
		eVK_KHR_external_semaphore_capabilities,
		eVK_KHR_external_semaphore_fd,
		eVK_KHR_format_feature_flags2,
		eVK_KHR_fragment_shader_barycentric,
		eVK_KHR_fragment_shading_rate,
		eVK_KHR_get_display_properties2,
		eVK_KHR_get_memory_requirements2,
		eVK_KHR_get_physical_device_properties2,
		eVK_KHR_get_surface_capabilities2,
		eVK_KHR_global_priority,
		eVK_KHR_image_format_list,
		eVK_KHR_imageless_framebuffer,
		eVK_KHR_incremental_present,
		eVK_KHR_maintenance1,
		eVK_KHR_maintenance2,
		eVK_KHR_maintenance3,
		eVK_KHR_maintenance4,
		eVK_KHR_multiview,
		eVK_KHR_performance_query,
		eVK_KHR_pipeline_executable_properties,
		eVK_KHR_pipeline_library,
		eVK_KHR_portability_enumeration,
		eVK_KHR_portability_subset,
		eVK_KHR_present_id,
		eVK_KHR_present_wait,
		eVK_KHR_push_descriptor,
		eVK_KHR_ray_query,
		eVK_KHR_ray_tracing_maintenance1,
		eVK_KHR_ray_tracing_pipeline,
		eVK_KHR_relaxed_block_layout,
		eVK_KHR_sampler_mirror_clamp_to_edge,
		eVK_KHR_sampler_ycbcr_conversion,
		eVK_KHR_separate_depth_stencil_layouts,
		eVK_KHR_shader_atomic_int64,
		eVK_KHR_shader_clock,
		eVK_KHR_shader_draw_parameters,
		eVK_KHR_shader_float16_int8,
		eVK_KHR_shader_float_controls,
		eVK_KHR_shader_integer_dot_product,
		eVK_KHR_shader_non_semantic_info,
		eVK_KHR_shader_subgroup_extended_types,
		eVK_KHR_shader_subgroup_uniform_control_flow,
		eVK_KHR_shader_terminate_invocation,
		eVK_KHR_shared_presentable_image,
		eVK_KHR_spirv_1_4,
		eVK_KHR_storage_buffer_storage_class,
		eVK_KHR_surface,
		eVK_KHR_surface_protected_capabilities,
		eVK_KHR_swapchain,
		eVK_KHR_swapchain_mutable_format,
		eVK_KHR_synchronization2,
		eVK_KHR_timeline_semaphore,
		eVK_KHR_uniform_buffer_standard_layout,
		eVK_KHR_variable_pointers,
		eVK_KHR_video_decode_queue,
		eVK_KHR_video_encode_queue,
		eVK_KHR_video_queue,
		eVK_KHR_vulkan_memory_model,
		eVK_KHR_wayland_surface,
		eVK_KHR_win32_keyed_mutex,
		eVK_KHR_win32_surface,
		eVK_KHR_workgroup_memory_explicit_layout,
		eVK_KHR_xcb_surface,
		eVK_KHR_xlib_surface,
		eVK_KHR_zero_initialize_workgroup_memory,
		eVK_EXT_4444_formats,
		eVK_EXT_acquire_drm_display,
		eVK_EXT_acquire_xlib_display,
		eVK_EXT_astc_decode_mode,
		eVK_EXT_attachment_feedback_loop_layout,
		eVK_EXT_blend_operation_advanced,
		eVK_EXT_border_color_swizzle,
		eVK_EXT_buffer_device_address,
		eVK_EXT_calibrated_timestamps,
		eVK_EXT_color_write_enable,
		eVK_EXT_conditional_rendering,
		eVK_EXT_conservative_rasterization,
		eVK_EXT_custom_border_color,
		eVK_EXT_debug_marker,
		eVK_EXT_debug_report,
		eVK_EXT_debug_utils,
		eVK_EXT_depth_clamp_zero_one,
		eVK_EXT_depth_clip_control,
		eVK_EXT_depth_clip_enable,
		eVK_EXT_depth_range_unrestricted,
		eVK_EXT_descriptor_indexing,
		eVK_EXT_device_address_binding_report,
		eVK_EXT_device_fault,
		eVK_EXT_device_memory_report,
		eVK_EXT_direct_mode_display,
		eVK_EXT_directfb_surface,
		eVK_EXT_discard_rectangles,
		eVK_EXT_display_control,
		eVK_EXT_display_surface_counter,
		eVK_EXT_extended_dynamic_state2,
		eVK_EXT_extended_dynamic_state,
		eVK_EXT_extended_dynamic_state3,
		eVK_EXT_external_memory_dma_buf,
		eVK_EXT_external_memory_host,
		eVK_EXT_filter_cubic,
		eVK_EXT_fragment_density_map2,
		eVK_EXT_fragment_density_map,
		eVK_EXT_fragment_shader_interlock,
		eVK_EXT_full_screen_exclusive,
		eVK_EXT_global_priority_query,
		eVK_EXT_global_priority,
		eVK_EXT_graphics_pipeline_library,
		eVK_EXT_hdr_metadata,
		eVK_EXT_headless_surface,
		eVK_EXT_host_query_reset,
		eVK_EXT_image_2d_view_of_3d,
		eVK_EXT_image_compression_control,
		eVK_EXT_image_compression_control_swapchain,
		eVK_EXT_image_drm_format_modifier,
		eVK_EXT_image_robustness,
		eVK_EXT_image_view_min_lod,
		eVK_EXT_index_type_uint8,
		eVK_EXT_inline_uniform_block,
		eVK_EXT_legacy_dithering,
		eVK_EXT_line_rasterization,
		eVK_EXT_load_store_op_none,
		eVK_EXT_memory_budget,
		eVK_EXT_memory_priority,
		eVK_EXT_mesh_shader,
		eVK_EXT_metal_objects,
		eVK_EXT_metal_surface,
		eVK_EXT_multi_draw,
		eVK_EXT_multisampled_render_to_single_sampled,
		eVK_EXT_mutable_descriptor_type,
		eVK_EXT_non_seamless_cube_map,
		eVK_EXT_opacity_micromap,
		eVK_EXT_pageable_device_local_memory,
		eVK_EXT_pci_bus_info,
		eVK_EXT_physical_device_drm,
		eVK_EXT_pipeline_creation_cache_control,
		eVK_EXT_pipeline_creation_feedback,
		eVK_EXT_pipeline_properties,
		eVK_EXT_pipeline_protected_access,
		eVK_EXT_pipeline_robustness,
		eVK_EXT_post_depth_coverage,
		eVK_EXT_primitive_topology_list_restart,
		eVK_EXT_primitives_generated_query,
		eVK_EXT_private_data,
		eVK_EXT_provoking_vertex,
		eVK_EXT_queue_family_foreign,
		eVK_EXT_rasterization_order_attachment_access,
		eVK_EXT_rgba10x6_formats,
		eVK_EXT_robustness2,
		eVK_EXT_sample_locations,
		eVK_EXT_sampler_filter_minmax,
		eVK_EXT_scalar_block_layout,
		eVK_EXT_separate_stencil_usage,
		eVK_EXT_shader_atomic_float2,
		eVK_EXT_shader_atomic_float,
		eVK_EXT_shader_demote_to_helper_invocation,
		eVK_EXT_shader_image_atomic_int64,
		eVK_EXT_shader_module_identifier,
		eVK_EXT_shader_stencil_export,
		eVK_EXT_shader_subgroup_ballot,
		eVK_EXT_shader_subgroup_vote,
		eVK_EXT_shader_viewport_index_layer,
		eVK_EXT_subgroup_size_control,
		eVK_EXT_subpass_merge_feedback,
		eVK_EXT_swapchain_colorspace,
		eVK_EXT_texel_buffer_alignment,
		eVK_EXT_texture_compression_astc_hdr,
		eVK_EXT_tooling_info,
		eVK_EXT_transform_feedback,
		eVK_EXT_validation_cache,
		eVK_EXT_validation_features,
		eVK_EXT_validation_flags,
		eVK_EXT_vertex_attribute_divisor,
		eVK_EXT_vertex_input_dynamic_state,
		eVK_EXT_video_decode_h264,
		eVK_EXT_video_decode_h265,
		eVK_EXT_video_encode_h264,
		eVK_EXT_video_encode_h265,
		eVK_EXT_ycbcr_2plane_444_formats,
		eVK_EXT_ycbcr_image_arrays,
		eVK_AMD_buffer_marker,
		eVK_AMD_device_coherent_memory,
		eVK_AMD_display_native_hdr,
		eVK_AMD_draw_indirect_count,
		eVK_AMD_gcn_shader,
		eVK_AMD_gpu_shader_half_float,
		eVK_AMD_gpu_shader_int16,
		eVK_AMD_memory_overallocation_behavior,
		eVK_AMD_mixed_attachment_samples,
		eVK_AMD_negative_viewport_height,
		eVK_AMD_pipeline_compiler_control,
		eVK_AMD_rasterization_order,
		eVK_AMD_shader_ballot,
		eVK_AMD_shader_core_properties2,
		eVK_AMD_shader_core_properties,
		eVK_AMD_shader_early_and_late_fragment_tests,
		eVK_AMD_shader_explicit_vertex_parameter,
		eVK_AMD_shader_fragment_mask,
		eVK_AMD_shader_image_load_store_lod,
		eVK_AMD_shader_info,
		eVK_AMD_shader_trinary_minmax,
		eVK_AMD_texture_gather_bias_lod,
		eVK_NV_acquire_winrt_display,
		eVK_NV_clip_space_w_scaling,
		eVK_NV_compute_shader_derivatives,
		eVK_NV_cooperative_matrix,
		eVK_NV_corner_sampled_image,
		eVK_NV_coverage_reduction_mode,
		eVK_NV_dedicated_allocation,
		eVK_NV_dedicated_allocation_image_aliasing,
		eVK_NV_device_diagnostic_checkpoints,
		eVK_NV_device_diagnostics_config,
		eVK_NV_device_generated_commands,
		eVK_NV_external_memory,
		eVK_NV_external_memory_capabilities,
		eVK_NV_external_memory_rdma,
		eVK_NV_external_memory_win32,
		eVK_NV_fill_rectangle,
		eVK_NV_fragment_coverage_to_color,
		eVK_NV_fragment_shader_barycentric,
		eVK_NV_fragment_shading_rate_enums,
		eVK_NV_framebuffer_mixed_samples,
		eVK_NV_geometry_shader_passthrough,
		eVK_NV_glsl_shader,
		eVK_NV_inherited_viewport_scissor,
		eVK_NV_linear_color_attachment,
		eVK_NV_mesh_shader,
		eVK_NV_optical_flow,
		eVK_NV_present_barrier,
		eVK_NV_ray_tracing,
		eVK_NV_ray_tracing_motion_blur,
		eVK_NV_representative_fragment_test,
		eVK_NV_sample_mask_override_coverage,
		eVK_NV_scissor_exclusive,
		eVK_NV_shader_image_footprint,
		eVK_NV_shader_sm_builtins,
		eVK_NV_shader_subgroup_partitioned,
		eVK_NV_shading_rate_image,
		eVK_NV_viewport_array2,
		eVK_NV_viewport_swizzle,
		eVK_NV_win32_keyed_mutex,
		eVK_NVX_binary_import,
		eVK_NVX_image_view_handle,
		eVK_NVX_multiview_per_view_attributes,
		eVK_ANDROID_external_memory_android_hardware_buffer,
		eVK_ARM_rasterization_order_attachment_access,
		eVK_ARM_shader_core_builtins,
		eVK_FUCHSIA_buffer_collection,
		eVK_FUCHSIA_external_memory,
		eVK_FUCHSIA_external_semaphore,
		eVK_FUCHSIA_imagepipe_surface,
		eVK_GGP_frame_token,
		eVK_GGP_stream_descriptor_surface,
		eVK_GOOGLE_decorate_string,
		eVK_GOOGLE_display_timing,
		eVK_GOOGLE_hlsl_functionality1,
		eVK_GOOGLE_surfaceless_query,
		eVK_GOOGLE_user_type,
		eVK_HUAWEI_invocation_mask,
		eVK_HUAWEI_subpass_shading,
		eVK_IMG_filter_cubic,
		eVK_IMG_format_pvrtc,
		eVK_INTEL_performance_query,
		eVK_INTEL_shader_integer_functions2,
		eVK_MVK_ios_surface,
		eVK_MVK_macos_surface,
		eVK_NN_vi_surface,
		eVK_QCOM_fragment_density_map_offset,
		eVK_QCOM_image_processing,
		eVK_QCOM_render_pass_shader_resolve,
		eVK_QCOM_render_pass_store_ops,
		eVK_QCOM_render_pass_transform,
		eVK_QCOM_rotated_copy_commands,
		eVK_QCOM_tile_properties,
		eVK_QNX_screen_surface,
		eVK_SEC_amigo_profiling,
		eVK_VALVE_descriptor_set_host_mapping,
		eVK_VALVE_mutable_descriptor_type,
		eCount
	};
	enum class AkariVKInstanceExtensionFlags :unsigned short {
		eVK_KHR_android_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_android_surface),
		eVK_KHR_device_group_creation = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_device_group_creation),
		eVK_KHR_display = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_display),
		eVK_KHR_external_fence_capabilities = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities),
		eVK_KHR_external_memory_capabilities = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities),
		eVK_KHR_external_semaphore_capabilities = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities),
		eVK_KHR_get_display_properties2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_get_display_properties2),
		eVK_KHR_get_physical_device_properties2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2),
		eVK_KHR_get_surface_capabilities2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2),
		eVK_KHR_portability_enumeration = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_portability_enumeration),
		eVK_KHR_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_surface),
		eVK_KHR_surface_protected_capabilities = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities),
		eVK_KHR_wayland_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_wayland_surface),
		eVK_KHR_win32_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_win32_surface),
		eVK_KHR_xcb_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_xcb_surface),
		eVK_KHR_xlib_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_xlib_surface),
		eVK_EXT_acquire_drm_display = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_acquire_drm_display),
		eVK_EXT_acquire_xlib_display = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display),
		eVK_EXT_debug_report = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_debug_report),
		eVK_EXT_debug_utils = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_debug_utils),
		eVK_EXT_direct_mode_display = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_direct_mode_display),
		eVK_EXT_directfb_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_directfb_surface),
		eVK_EXT_display_surface_counter = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_display_surface_counter),
		eVK_EXT_headless_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_headless_surface),
		eVK_EXT_metal_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_metal_surface),
		eVK_EXT_swapchain_colorspace = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace),
		eVK_EXT_validation_features = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_validation_features),
		eVK_EXT_validation_flags = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_validation_flags),
		eVK_NV_external_memory_capabilities = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_external_memory_capabilities),
		eVK_FUCHSIA_imagepipe_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface),
		eVK_GGP_stream_descriptor_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface),
		eVK_GOOGLE_surfaceless_query = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query),
		eVK_MVK_ios_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_MVK_ios_surface),
		eVK_MVK_macos_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_MVK_macos_surface),
		eVK_NN_vi_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NN_vi_surface),
		eVK_QNX_screen_surface = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_QNX_screen_surface),
	};
	enum class AkariVKDeviceExtensionFlags :unsigned short {
		eVK_KHR_16bit_storage = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_16bit_storage),
		eVK_KHR_8bit_storage = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_8bit_storage),
		eVK_KHR_acceleration_structure = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_acceleration_structure),
		eVK_KHR_bind_memory2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_bind_memory2),
		eVK_KHR_buffer_device_address = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_buffer_device_address),
		eVK_KHR_copy_commands2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_copy_commands2),
		eVK_KHR_create_renderpass2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_create_renderpass2),
		eVK_KHR_dedicated_allocation = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_dedicated_allocation),
		eVK_KHR_deferred_host_operations = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_deferred_host_operations),
		eVK_KHR_depth_stencil_resolve = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve),
		eVK_KHR_descriptor_update_template = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_descriptor_update_template),
		eVK_KHR_device_group = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_device_group),
		eVK_KHR_display_swapchain = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_display_swapchain),
		eVK_KHR_draw_indirect_count = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_draw_indirect_count),
		eVK_KHR_driver_properties = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_driver_properties),
		eVK_KHR_dynamic_rendering = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_dynamic_rendering),
		eVK_KHR_external_fence = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_fence),
		eVK_KHR_external_fence_fd = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_fence_fd),
		eVK_KHR_external_fence_win32 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_fence_win32),
		eVK_KHR_external_memory = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_memory),
		eVK_KHR_external_memory_fd = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_memory_fd),
		eVK_KHR_external_memory_win32 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_memory_win32),
		eVK_KHR_external_semaphore_win32 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32),
		eVK_KHR_external_semaphore = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_semaphore),
		eVK_KHR_external_semaphore_fd = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd),
		eVK_KHR_format_feature_flags2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_format_feature_flags2),
		eVK_KHR_fragment_shader_barycentric = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric),
		eVK_KHR_fragment_shading_rate = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate),
		eVK_KHR_get_memory_requirements2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2),
		eVK_KHR_global_priority = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_global_priority),
		eVK_KHR_image_format_list = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_image_format_list),
		eVK_KHR_imageless_framebuffer = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer),
		eVK_KHR_incremental_present = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_incremental_present),
		eVK_KHR_maintenance1 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_maintenance1),
		eVK_KHR_maintenance2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_maintenance2),
		eVK_KHR_maintenance3 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_maintenance3),
		eVK_KHR_maintenance4 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_maintenance4),
		eVK_KHR_multiview = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_multiview),
		eVK_KHR_performance_query = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_performance_query),
		eVK_KHR_pipeline_executable_properties = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties),
		eVK_KHR_pipeline_library = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_pipeline_library),
		eVK_KHR_portability_subset = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_portability_subset),
		eVK_KHR_present_id = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_present_id),
		eVK_KHR_present_wait = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_present_wait),
		eVK_KHR_push_descriptor = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_push_descriptor),
		eVK_KHR_ray_query = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_ray_query),
		eVK_KHR_ray_tracing_maintenance1 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1),
		eVK_KHR_ray_tracing_pipeline = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline),
		eVK_KHR_relaxed_block_layout = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout),
		eVK_KHR_sampler_mirror_clamp_to_edge = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge),
		eVK_KHR_sampler_ycbcr_conversion = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion),
		eVK_KHR_separate_depth_stencil_layouts = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts),
		eVK_KHR_shader_atomic_int64 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64),
		eVK_KHR_shader_clock = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_clock),
		eVK_KHR_shader_draw_parameters = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters),
		eVK_KHR_shader_float16_int8 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_float16_int8),
		eVK_KHR_shader_float_controls = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_float_controls),
		eVK_KHR_shader_integer_dot_product = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product),
		eVK_KHR_shader_non_semantic_info = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info),
		eVK_KHR_shader_subgroup_extended_types = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types),
		eVK_KHR_shader_subgroup_uniform_control_flow = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow),
		eVK_KHR_shader_terminate_invocation = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation),
		eVK_KHR_shared_presentable_image = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_shared_presentable_image),
		eVK_KHR_spirv_1_4 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_spirv_1_4),
		eVK_KHR_storage_buffer_storage_class = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class),
		eVK_KHR_swapchain = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_swapchain),
		eVK_KHR_swapchain_mutable_format = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format),
		eVK_KHR_synchronization2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_synchronization2),
		eVK_KHR_timeline_semaphore = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_timeline_semaphore),
		eVK_KHR_uniform_buffer_standard_layout = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout),
		eVK_KHR_variable_pointers = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_variable_pointers),
		eVK_KHR_video_decode_queue = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_video_decode_queue),
		eVK_KHR_video_encode_queue = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_video_encode_queue),
		eVK_KHR_video_queue = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_video_queue),
		eVK_KHR_vulkan_memory_model = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model),
		eVK_KHR_win32_keyed_mutex = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex),
		eVK_KHR_workgroup_memory_explicit_layout = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout),
		eVK_KHR_zero_initialize_workgroup_memory = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory),
		eVK_EXT_4444_formats = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_4444_formats),
		eVK_EXT_astc_decode_mode = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_astc_decode_mode),
		eVK_EXT_attachment_feedback_loop_layout = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout),
		eVK_EXT_blend_operation_advanced = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced),
		eVK_EXT_border_color_swizzle = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_border_color_swizzle),
		eVK_EXT_buffer_device_address = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_buffer_device_address),
		eVK_EXT_calibrated_timestamps = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps),
		eVK_EXT_color_write_enable = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_color_write_enable),
		eVK_EXT_conditional_rendering = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_conditional_rendering),
		eVK_EXT_conservative_rasterization = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_conservative_rasterization),
		eVK_EXT_custom_border_color = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_custom_border_color),
		eVK_EXT_debug_marker = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_debug_marker),
		eVK_EXT_depth_clamp_zero_one = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one),
		eVK_EXT_depth_clip_control = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_depth_clip_control),
		eVK_EXT_depth_clip_enable = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_depth_clip_enable),
		eVK_EXT_depth_range_unrestricted = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted),
		eVK_EXT_descriptor_indexing = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_descriptor_indexing),
		eVK_EXT_device_address_binding_report = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_device_address_binding_report),
		eVK_EXT_device_fault = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_device_fault),
		eVK_EXT_device_memory_report = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_device_memory_report),
		eVK_EXT_discard_rectangles = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_discard_rectangles),
		eVK_EXT_display_control = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_display_control),
		eVK_EXT_extended_dynamic_state2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2),
		eVK_EXT_extended_dynamic_state = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state),
		eVK_EXT_extended_dynamic_state3 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3),
		eVK_EXT_external_memory_dma_buf = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf),
		eVK_EXT_external_memory_host = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_external_memory_host),
		eVK_EXT_filter_cubic = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_filter_cubic),
		eVK_EXT_fragment_density_map2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_fragment_density_map2),
		eVK_EXT_fragment_density_map = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_fragment_density_map),
		eVK_EXT_fragment_shader_interlock = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock),
		eVK_EXT_full_screen_exclusive = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive),
		eVK_EXT_global_priority_query = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_global_priority_query),
		eVK_EXT_global_priority = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_global_priority),
		eVK_EXT_graphics_pipeline_library = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library),
		eVK_EXT_hdr_metadata = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_hdr_metadata),
		eVK_EXT_host_query_reset = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_host_query_reset),
		eVK_EXT_image_2d_view_of_3d = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d),
		eVK_EXT_image_compression_control = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_image_compression_control),
		eVK_EXT_image_compression_control_swapchain = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain),
		eVK_EXT_image_drm_format_modifier = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier),
		eVK_EXT_image_robustness = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_image_robustness),
		eVK_EXT_image_view_min_lod = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_image_view_min_lod),
		eVK_EXT_index_type_uint8 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_index_type_uint8),
		eVK_EXT_inline_uniform_block = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_inline_uniform_block),
		eVK_EXT_legacy_dithering = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_legacy_dithering),
		eVK_EXT_line_rasterization = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_line_rasterization),
		eVK_EXT_load_store_op_none = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_load_store_op_none),
		eVK_EXT_memory_budget = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_memory_budget),
		eVK_EXT_memory_priority = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_memory_priority),
		eVK_EXT_mesh_shader = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_mesh_shader),
		eVK_EXT_metal_objects = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_metal_objects),
		eVK_EXT_multi_draw = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_multi_draw),
		eVK_EXT_multisampled_render_to_single_sampled = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled),
		eVK_EXT_mutable_descriptor_type = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type),
		eVK_EXT_non_seamless_cube_map = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map),
		eVK_EXT_opacity_micromap = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_opacity_micromap),
		eVK_EXT_pageable_device_local_memory = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory),
		eVK_EXT_pci_bus_info = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_pci_bus_info),
		eVK_EXT_physical_device_drm = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_physical_device_drm),
		eVK_EXT_pipeline_creation_cache_control = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control),
		eVK_EXT_pipeline_creation_feedback = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback),
		eVK_EXT_pipeline_properties = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_pipeline_properties),
		eVK_EXT_pipeline_protected_access = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access),
		eVK_EXT_pipeline_robustness = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_pipeline_robustness),
		eVK_EXT_post_depth_coverage = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_post_depth_coverage),
		eVK_EXT_primitive_topology_list_restart = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart),
		eVK_EXT_primitives_generated_query = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_primitives_generated_query),
		eVK_EXT_private_data = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_private_data),
		eVK_EXT_provoking_vertex = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_provoking_vertex),
		eVK_EXT_queue_family_foreign = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_queue_family_foreign),
		eVK_EXT_rasterization_order_attachment_access = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access),
		eVK_EXT_rgba10x6_formats = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats),
		eVK_EXT_robustness2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_robustness2),
		eVK_EXT_sample_locations = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_sample_locations),
		eVK_EXT_sampler_filter_minmax = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax),
		eVK_EXT_scalar_block_layout = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_scalar_block_layout),
		eVK_EXT_separate_stencil_usage = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage),
		eVK_EXT_shader_atomic_float2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2),
		eVK_EXT_shader_atomic_float = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_shader_atomic_float),
		eVK_EXT_shader_demote_to_helper_invocation = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation),
		eVK_EXT_shader_image_atomic_int64 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64),
		eVK_EXT_shader_module_identifier = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_shader_module_identifier),
		eVK_EXT_shader_stencil_export = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_shader_stencil_export),
		eVK_EXT_shader_subgroup_ballot = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot),
		eVK_EXT_shader_subgroup_vote = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote),
		eVK_EXT_shader_viewport_index_layer = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer),
		eVK_EXT_subgroup_size_control = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_subgroup_size_control),
		eVK_EXT_subpass_merge_feedback = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback),
		eVK_EXT_texel_buffer_alignment = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment),
		eVK_EXT_texture_compression_astc_hdr = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr),
		eVK_EXT_tooling_info = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_tooling_info),
		eVK_EXT_transform_feedback = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_transform_feedback),
		eVK_EXT_validation_cache = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_validation_cache),
		eVK_EXT_vertex_attribute_divisor = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor),
		eVK_EXT_vertex_input_dynamic_state = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state),
		eVK_EXT_video_decode_h264 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_video_decode_h264),
		eVK_EXT_video_decode_h265 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_video_decode_h265),
		eVK_EXT_video_encode_h264 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_video_encode_h264),
		eVK_EXT_video_encode_h265 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_video_encode_h265),
		eVK_EXT_ycbcr_2plane_444_formats = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats),
		eVK_EXT_ycbcr_image_arrays = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays),
		eVK_AMD_buffer_marker = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_buffer_marker),
		eVK_AMD_device_coherent_memory = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_device_coherent_memory),
		eVK_AMD_display_native_hdr = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_display_native_hdr),
		eVK_AMD_draw_indirect_count = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_draw_indirect_count),
		eVK_AMD_gcn_shader = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_gcn_shader),
		eVK_AMD_gpu_shader_half_float = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float),
		eVK_AMD_gpu_shader_int16 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16),
		eVK_AMD_memory_overallocation_behavior = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior),
		eVK_AMD_mixed_attachment_samples = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples),
		eVK_AMD_negative_viewport_height = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_negative_viewport_height),
		eVK_AMD_pipeline_compiler_control = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control),
		eVK_AMD_rasterization_order = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_rasterization_order),
		eVK_AMD_shader_ballot = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_shader_ballot),
		eVK_AMD_shader_core_properties2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_shader_core_properties2),
		eVK_AMD_shader_core_properties = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_shader_core_properties),
		eVK_AMD_shader_early_and_late_fragment_tests = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests),
		eVK_AMD_shader_explicit_vertex_parameter = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter),
		eVK_AMD_shader_fragment_mask = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask),
		eVK_AMD_shader_image_load_store_lod = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod),
		eVK_AMD_shader_info = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_shader_info),
		eVK_AMD_shader_trinary_minmax = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax),
		eVK_AMD_texture_gather_bias_lod = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod),
		eVK_NV_acquire_winrt_display = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_acquire_winrt_display),
		eVK_NV_clip_space_w_scaling = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling),
		eVK_NV_compute_shader_derivatives = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives),
		eVK_NV_cooperative_matrix = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_cooperative_matrix),
		eVK_NV_corner_sampled_image = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_corner_sampled_image),
		eVK_NV_coverage_reduction_mode = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode),
		eVK_NV_dedicated_allocation = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_dedicated_allocation),
		eVK_NV_dedicated_allocation_image_aliasing = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing),
		eVK_NV_device_diagnostic_checkpoints = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints),
		eVK_NV_device_diagnostics_config = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_device_diagnostics_config),
		eVK_NV_device_generated_commands = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_device_generated_commands),
		eVK_NV_external_memory = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_external_memory),
		eVK_NV_external_memory_rdma = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_external_memory_rdma),
		eVK_NV_external_memory_win32 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_external_memory_win32),
		eVK_NV_fill_rectangle = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_fill_rectangle),
		eVK_NV_fragment_coverage_to_color = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color),
		eVK_NV_fragment_shader_barycentric = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric),
		eVK_NV_fragment_shading_rate_enums = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums),
		eVK_NV_framebuffer_mixed_samples = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples),
		eVK_NV_geometry_shader_passthrough = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough),
		eVK_NV_glsl_shader = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_glsl_shader),
		eVK_NV_inherited_viewport_scissor = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor),
		eVK_NV_linear_color_attachment = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_linear_color_attachment),
		eVK_NV_mesh_shader = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_mesh_shader),
		eVK_NV_optical_flow = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_optical_flow),
		eVK_NV_present_barrier = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_present_barrier),
		eVK_NV_ray_tracing = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_ray_tracing),
		eVK_NV_ray_tracing_motion_blur = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur),
		eVK_NV_representative_fragment_test = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_representative_fragment_test),
		eVK_NV_sample_mask_override_coverage = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage),
		eVK_NV_scissor_exclusive = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_scissor_exclusive),
		eVK_NV_shader_image_footprint = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_shader_image_footprint),
		eVK_NV_shader_sm_builtins = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_shader_sm_builtins),
		eVK_NV_shader_subgroup_partitioned = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned),
		eVK_NV_shading_rate_image = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_shading_rate_image),
		eVK_NV_viewport_array2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_viewport_array2),
		eVK_NV_viewport_swizzle = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_viewport_swizzle),
		eVK_NV_win32_keyed_mutex = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex),
		eVK_NVX_binary_import = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NVX_binary_import),
		eVK_NVX_image_view_handle = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NVX_image_view_handle),
		eVK_NVX_multiview_per_view_attributes = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes),
		eVK_ANDROID_external_memory_android_hardware_buffer = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer),
		eVK_ARM_rasterization_order_attachment_access = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access),
		eVK_ARM_shader_core_builtins = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_ARM_shader_core_builtins),
		eVK_FUCHSIA_buffer_collection = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection),
		eVK_FUCHSIA_external_memory = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_FUCHSIA_external_memory),
		eVK_FUCHSIA_external_semaphore = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore),
		eVK_GGP_frame_token = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_GGP_frame_token),
		eVK_GOOGLE_decorate_string = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_GOOGLE_decorate_string),
		eVK_GOOGLE_display_timing = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_GOOGLE_display_timing),
		eVK_GOOGLE_hlsl_functionality1 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1),
		eVK_GOOGLE_user_type = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_GOOGLE_user_type),
		eVK_HUAWEI_invocation_mask = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask),
		eVK_HUAWEI_subpass_shading = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading),
		eVK_IMG_filter_cubic = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_IMG_filter_cubic),
		eVK_IMG_format_pvrtc = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_IMG_format_pvrtc),
		eVK_INTEL_performance_query = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_INTEL_performance_query),
		eVK_INTEL_shader_integer_functions2 = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2),
		eVK_QCOM_fragment_density_map_offset = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset),
		eVK_QCOM_image_processing = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_QCOM_image_processing),
		eVK_QCOM_render_pass_shader_resolve = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve),
		eVK_QCOM_render_pass_store_ops = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops),
		eVK_QCOM_render_pass_transform = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_QCOM_render_pass_transform),
		eVK_QCOM_rotated_copy_commands = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands),
		eVK_QCOM_tile_properties = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_QCOM_tile_properties),
		eVK_SEC_amigo_profiling = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_SEC_amigo_profiling),
		eVK_VALVE_descriptor_set_host_mapping = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping),
		eVK_VALVE_mutable_descriptor_type = static_cast<unsigned short>(AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type),
	};
	struct AkariVKExtensionFeaturesNotAvailable {};
	struct AkariVKExtensionFeaturesNotNecessary {};
	template<AkariVKExtensionFlags flags>
	struct AkariVKExtensionFeaturesTraits;
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_16bit_storage> {
#if defined(VK_KHR_16bit_storage)
		using type = vk::PhysicalDevice16BitStorageFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_8bit_storage> {
#if defined(VK_KHR_8bit_storage)
		using type = vk::PhysicalDevice8BitStorageFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_acceleration_structure> {
#if defined(VK_KHR_acceleration_structure)
		using type = vk::PhysicalDeviceAccelerationStructureFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_android_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_bind_memory2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_buffer_device_address> {
#if defined(VK_KHR_buffer_device_address)
		using type = vk::PhysicalDeviceBufferDeviceAddressFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_copy_commands2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_create_renderpass2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_dedicated_allocation> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_deferred_host_operations> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_descriptor_update_template> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_device_group> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_device_group_creation> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_display> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_display_swapchain> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_draw_indirect_count> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_driver_properties> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_dynamic_rendering> {
#if defined(VK_KHR_dynamic_rendering)
		using type = vk::PhysicalDeviceDynamicRenderingFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_fence> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_fence_fd> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_fence_win32> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_memory> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_memory_fd> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_memory_win32> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_format_feature_flags2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric> {
#if defined(VK_KHR_fragment_shader_barycentric)
		using type = vk::PhysicalDeviceFragmentShaderBarycentricFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate> {
#if defined(VK_KHR_fragment_shading_rate)
		using type = vk::PhysicalDeviceFragmentShadingRateFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_get_display_properties2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2> {
#if defined(VK_KHR_get_physical_device_properties2)
		using type = vk::PhysicalDeviceFeatures2KHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_global_priority> {
#if defined(VK_KHR_global_priority)
		using type = vk::PhysicalDeviceGlobalPriorityQueryFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_image_format_list> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer> {
#if defined(VK_KHR_imageless_framebuffer)
		using type = vk::PhysicalDeviceImagelessFramebufferFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_incremental_present> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_maintenance1> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_maintenance2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_maintenance3> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_maintenance4> {
#if defined(VK_KHR_maintenance4)
		using type = vk::PhysicalDeviceMaintenance4FeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_multiview> {
#if defined(VK_KHR_multiview)
		using type = vk::PhysicalDeviceMultiviewFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_performance_query> {
#if defined(VK_KHR_performance_query)
		using type = vk::PhysicalDevicePerformanceQueryFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties> {
#if defined(VK_KHR_pipeline_executable_properties)
		using type = vk::PhysicalDevicePipelineExecutablePropertiesFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_pipeline_library> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_portability_enumeration> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_portability_subset> {
#if defined(VK_KHR_portability_subset)
		using type = vk::PhysicalDevicePortabilitySubsetFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_present_id> {
#if defined(VK_KHR_present_id)
		using type = vk::PhysicalDevicePresentIdFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_present_wait> {
#if defined(VK_KHR_present_wait)
		using type = vk::PhysicalDevicePresentWaitFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_push_descriptor> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_ray_query> {
#if defined(VK_KHR_ray_query)
		using type = vk::PhysicalDeviceRayQueryFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1> {
#if defined(VK_KHR_ray_tracing_maintenance1)
		using type = vk::PhysicalDeviceRayTracingMaintenance1FeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline> {
#if defined(VK_KHR_ray_tracing_pipeline)
		using type = vk::PhysicalDeviceRayTracingPipelineFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion> {
#if defined(VK_KHR_sampler_ycbcr_conversion)
		using type = vk::PhysicalDeviceSamplerYcbcrConversionFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts> {
#if defined(VK_KHR_separate_depth_stencil_layouts)
		using type = vk::PhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64> {
#if defined(VK_KHR_shader_atomic_int64)
		using type = vk::PhysicalDeviceShaderAtomicInt64FeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_clock> {
#if defined(VK_KHR_shader_clock)
		using type = vk::PhysicalDeviceShaderClockFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_float16_int8> {
#if defined(VK_KHR_shader_float16_int8)
		using type = vk::PhysicalDeviceFloat16Int8FeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_float_controls> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product> {
#if defined(VK_KHR_shader_integer_dot_product)
		using type = vk::PhysicalDeviceShaderIntegerDotProductFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types> {
#if defined(VK_KHR_shader_subgroup_extended_types)
		using type = vk::PhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow> {
#if defined(VK_KHR_shader_subgroup_uniform_control_flow)
		using type = vk::PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation> {
#if defined(VK_KHR_shader_terminate_invocation)
		using type = vk::PhysicalDeviceShaderTerminateInvocationFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shared_presentable_image> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_spirv_1_4> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_swapchain> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_synchronization2> {
#if defined(VK_KHR_synchronization2)
		using type = vk::PhysicalDeviceSynchronization2FeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_timeline_semaphore> {
#if defined(VK_KHR_timeline_semaphore)
		using type = vk::PhysicalDeviceTimelineSemaphoreFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout> {
#if defined(VK_KHR_uniform_buffer_standard_layout)
		using type = vk::PhysicalDeviceUniformBufferStandardLayoutFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_variable_pointers> {
#if defined(VK_KHR_variable_pointers)
		using type = vk::PhysicalDeviceVariablePointersFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_video_decode_queue> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_video_encode_queue> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_video_queue> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model> {
#if defined(VK_KHR_vulkan_memory_model)
		using type = vk::PhysicalDeviceVulkanMemoryModelFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_wayland_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_win32_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout> {
#if defined(VK_KHR_workgroup_memory_explicit_layout)
		using type = vk::PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_xcb_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_xlib_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory> {
#if defined(VK_KHR_zero_initialize_workgroup_memory)
		using type = vk::PhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_4444_formats> {
#if defined(VK_EXT_4444_formats)
		using type = vk::PhysicalDevice4444FormatsFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_acquire_drm_display> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_astc_decode_mode> {
#if defined(VK_EXT_astc_decode_mode)
		using type = vk::PhysicalDeviceASTCDecodeFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout> {
#if defined(VK_EXT_attachment_feedback_loop_layout)
		using type = vk::PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced> {
#if defined(VK_EXT_blend_operation_advanced)
		using type = vk::PhysicalDeviceBlendOperationAdvancedFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_border_color_swizzle> {
#if defined(VK_EXT_border_color_swizzle)
		using type = vk::PhysicalDeviceBorderColorSwizzleFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_buffer_device_address> {
#if defined(VK_EXT_buffer_device_address)
		using type = vk::PhysicalDeviceBufferDeviceAddressFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_color_write_enable> {
#if defined(VK_EXT_color_write_enable)
		using type = vk::PhysicalDeviceColorWriteEnableFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_conditional_rendering> {
#if defined(VK_EXT_conditional_rendering)
		using type = vk::PhysicalDeviceConditionalRenderingFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_conservative_rasterization> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_custom_border_color> {
#if defined(VK_EXT_custom_border_color)
		using type = vk::PhysicalDeviceCustomBorderColorFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_debug_marker> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_debug_report> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_debug_utils> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one> {
#if defined(VK_EXT_depth_clamp_zero_one)
		using type = vk::PhysicalDeviceDepthClampZeroOneFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_depth_clip_control> {
#if defined(VK_EXT_depth_clip_control)
		using type = vk::PhysicalDeviceDepthClipControlFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_depth_clip_enable> {
#if defined(VK_EXT_depth_clip_enable)
		using type = vk::PhysicalDeviceDepthClipEnableFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_descriptor_indexing> {
#if defined(VK_EXT_descriptor_indexing)
		using type = vk::PhysicalDeviceDescriptorIndexingFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_device_address_binding_report> {
#if defined(VK_EXT_device_address_binding_report)
		using type = vk::PhysicalDeviceAddressBindingReportFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_device_fault> {
#if defined(VK_EXT_device_fault)
		using type = vk::PhysicalDeviceFaultFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_device_memory_report> {
#if defined(VK_EXT_device_memory_report)
		using type = vk::PhysicalDeviceDeviceMemoryReportFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_direct_mode_display> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_directfb_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_discard_rectangles> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_display_control> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_display_surface_counter> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2> {
#if defined(VK_EXT_extended_dynamic_state2)
		using type = vk::PhysicalDeviceExtendedDynamicState2FeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state> {
#if defined(VK_EXT_extended_dynamic_state)
		using type = vk::PhysicalDeviceExtendedDynamicStateFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3> {
#if defined(VK_EXT_extended_dynamic_state3)
		using type = vk::PhysicalDeviceExtendedDynamicState3FeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_external_memory_host> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_filter_cubic> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_fragment_density_map2> {
#if defined(VK_EXT_fragment_density_map2)
		using type = vk::PhysicalDeviceFragmentDensityMap2FeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_fragment_density_map> {
#if defined(VK_EXT_fragment_density_map)
		using type = vk::PhysicalDeviceFragmentDensityMapFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock> {
#if defined(VK_EXT_fragment_shader_interlock)
		using type = vk::PhysicalDeviceFragmentShaderInterlockFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_global_priority_query> {
#if defined(VK_EXT_global_priority_query)
		using type = vk::PhysicalDeviceGlobalPriorityQueryFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_global_priority> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library> {
#if defined(VK_EXT_graphics_pipeline_library)
		using type = vk::PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_hdr_metadata> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_headless_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_host_query_reset> {
#if defined(VK_EXT_host_query_reset)
		using type = vk::PhysicalDeviceHostQueryResetFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d> {
#if defined(VK_EXT_image_2d_view_of_3d)
		using type = vk::PhysicalDeviceImage2DViewOf3DFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_compression_control> {
#if defined(VK_EXT_image_compression_control)
		using type = vk::PhysicalDeviceImageCompressionControlFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain> {
#if defined(VK_EXT_image_compression_control_swapchain)
		using type = vk::PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_robustness> {
#if defined(VK_EXT_image_robustness)
		using type = vk::PhysicalDeviceImageRobustnessFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_view_min_lod> {
#if defined(VK_EXT_image_view_min_lod)
		using type = vk::PhysicalDeviceImageViewMinLodFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_index_type_uint8> {
#if defined(VK_EXT_index_type_uint8)
		using type = vk::PhysicalDeviceIndexTypeUint8FeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_inline_uniform_block> {
#if defined(VK_EXT_inline_uniform_block)
		using type = vk::PhysicalDeviceInlineUniformBlockFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_legacy_dithering> {
#if defined(VK_EXT_legacy_dithering)
		using type = vk::PhysicalDeviceLegacyDitheringFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_line_rasterization> {
#if defined(VK_EXT_line_rasterization)
		using type = vk::PhysicalDeviceLineRasterizationFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_load_store_op_none> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_memory_budget> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_memory_priority> {
#if defined(VK_EXT_memory_priority)
		using type = vk::PhysicalDeviceMemoryPriorityFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_mesh_shader> {
#if defined(VK_EXT_mesh_shader)
		using type = vk::PhysicalDeviceMeshShaderFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_metal_objects> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_metal_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_multi_draw> {
#if defined(VK_EXT_multi_draw)
		using type = vk::PhysicalDeviceMultiDrawFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled> {
#if defined(VK_EXT_multisampled_render_to_single_sampled)
		using type = vk::PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type> {
#if defined(VK_EXT_mutable_descriptor_type)
		using type = vk::PhysicalDeviceMutableDescriptorTypeFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map> {
#if defined(VK_EXT_non_seamless_cube_map)
		using type = vk::PhysicalDeviceNonSeamlessCubeMapFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_opacity_micromap> {
#if defined(VK_EXT_opacity_micromap)
		using type = vk::PhysicalDeviceOpacityMicromapFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory> {
#if defined(VK_EXT_pageable_device_local_memory)
		using type = vk::PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pci_bus_info> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_physical_device_drm> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control> {
#if defined(VK_EXT_pipeline_creation_cache_control)
		using type = vk::PhysicalDevicePipelineCreationCacheControlFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_properties> {
#if defined(VK_EXT_pipeline_properties)
		using type = vk::PhysicalDevicePipelinePropertiesFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access> {
#if defined(VK_EXT_pipeline_protected_access)
		using type = vk::PhysicalDevicePipelineProtectedAccessFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_robustness> {
#if defined(VK_EXT_pipeline_robustness)
		using type = vk::PhysicalDevicePipelineRobustnessFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_post_depth_coverage> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart> {
#if defined(VK_EXT_primitive_topology_list_restart)
		using type = vk::PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_primitives_generated_query> {
#if defined(VK_EXT_primitives_generated_query)
		using type = vk::PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_private_data> {
#if defined(VK_EXT_private_data)
		using type = vk::PhysicalDevicePrivateDataFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_provoking_vertex> {
#if defined(VK_EXT_provoking_vertex)
		using type = vk::PhysicalDeviceProvokingVertexFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_queue_family_foreign> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access> {
#if defined(VK_EXT_rasterization_order_attachment_access)
		using type = vk::PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats> {
#if defined(VK_EXT_rgba10x6_formats)
		using type = vk::PhysicalDeviceRGBA10X6FormatsFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_robustness2> {
#if defined(VK_EXT_robustness2)
		using type = vk::PhysicalDeviceRobustness2FeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_sample_locations> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_scalar_block_layout> {
#if defined(VK_EXT_scalar_block_layout)
		using type = vk::PhysicalDeviceScalarBlockLayoutFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2> {
#if defined(VK_EXT_shader_atomic_float2)
		using type = vk::PhysicalDeviceShaderAtomicFloat2FeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_atomic_float> {
#if defined(VK_EXT_shader_atomic_float)
		using type = vk::PhysicalDeviceShaderAtomicFloatFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation> {
#if defined(VK_EXT_shader_demote_to_helper_invocation)
		using type = vk::PhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64> {
#if defined(VK_EXT_shader_image_atomic_int64)
		using type = vk::PhysicalDeviceShaderImageAtomicInt64FeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_module_identifier> {
#if defined(VK_EXT_shader_module_identifier)
		using type = vk::PhysicalDeviceShaderModuleIdentifierFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_stencil_export> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_subgroup_size_control> {
#if defined(VK_EXT_subgroup_size_control)
		using type = vk::PhysicalDeviceSubgroupSizeControlFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback> {
#if defined(VK_EXT_subpass_merge_feedback)
		using type = vk::PhysicalDeviceSubpassMergeFeedbackFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment> {
#if defined(VK_EXT_texel_buffer_alignment)
		using type = vk::PhysicalDeviceTexelBufferAlignmentFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr> {
#if defined(VK_EXT_texture_compression_astc_hdr)
		using type = vk::PhysicalDeviceTextureCompressionASTCHDRFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_tooling_info> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_transform_feedback> {
#if defined(VK_EXT_transform_feedback)
		using type = vk::PhysicalDeviceTransformFeedbackFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_validation_cache> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_validation_features> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_validation_flags> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor> {
#if defined(VK_EXT_vertex_attribute_divisor)
		using type = vk::PhysicalDeviceVertexAttributeDivisorFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state> {
#if defined(VK_EXT_vertex_input_dynamic_state)
		using type = vk::PhysicalDeviceVertexInputDynamicStateFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_video_decode_h264> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_video_decode_h265> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_video_encode_h264> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_video_encode_h265> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats> {
#if defined(VK_EXT_ycbcr_2plane_444_formats)
		using type = vk::PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays> {
#if defined(VK_EXT_ycbcr_image_arrays)
		using type = vk::PhysicalDeviceYcbcrImageArraysFeaturesEXT;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_buffer_marker> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_device_coherent_memory> {
#if defined(VK_AMD_device_coherent_memory)
		using type = vk::PhysicalDeviceCoherentMemoryFeaturesAMD;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_display_native_hdr> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_draw_indirect_count> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_gcn_shader> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_negative_viewport_height> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_rasterization_order> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_ballot> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_core_properties2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_core_properties> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests> {
#if defined(VK_AMD_shader_early_and_late_fragment_tests)
		using type = vk::PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_info> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_acquire_winrt_display> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives> {
#if defined(VK_NV_compute_shader_derivatives)
		using type = vk::PhysicalDeviceComputeShaderDerivativesFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_cooperative_matrix> {
#if defined(VK_NV_cooperative_matrix)
		using type = vk::PhysicalDeviceCooperativeMatrixFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_corner_sampled_image> {
#if defined(VK_NV_corner_sampled_image)
		using type = vk::PhysicalDeviceCornerSampledImageFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode> {
#if defined(VK_NV_coverage_reduction_mode)
		using type = vk::PhysicalDeviceCoverageReductionModeFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_dedicated_allocation> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing> {
#if defined(VK_NV_dedicated_allocation_image_aliasing)
		using type = vk::PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_device_diagnostics_config> {
#if defined(VK_NV_device_diagnostics_config)
		using type = vk::PhysicalDeviceDiagnosticsConfigFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_device_generated_commands> {
#if defined(VK_NV_device_generated_commands)
		using type = vk::PhysicalDeviceDeviceGeneratedCommandsFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_external_memory> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_external_memory_capabilities> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_external_memory_rdma> {
#if defined(VK_NV_external_memory_rdma)
		using type = vk::PhysicalDeviceExternalMemoryRDMAFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_external_memory_win32> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_fill_rectangle> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric> {
#if defined(VK_NV_fragment_shader_barycentric)
		using type = vk::PhysicalDeviceFragmentShaderBarycentricFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums> {
#if defined(VK_NV_fragment_shading_rate_enums)
		using type = vk::PhysicalDeviceFragmentShadingRateEnumsFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_glsl_shader> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor> {
#if defined(VK_NV_inherited_viewport_scissor)
		using type = vk::PhysicalDeviceInheritedViewportScissorFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_linear_color_attachment> {
#if defined(VK_NV_linear_color_attachment)
		using type = vk::PhysicalDeviceLinearColorAttachmentFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_mesh_shader> {
#if defined(VK_NV_mesh_shader)
		using type = vk::PhysicalDeviceMeshShaderFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_optical_flow> {
#if defined(VK_NV_optical_flow)
		using type = vk::PhysicalDeviceOpticalFlowFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_present_barrier> {
#if defined(VK_NV_present_barrier)
		using type = vk::PhysicalDevicePresentBarrierFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_ray_tracing> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur> {
#if defined(VK_NV_ray_tracing_motion_blur)
		using type = vk::PhysicalDeviceRayTracingMotionBlurFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_representative_fragment_test> {
#if defined(VK_NV_representative_fragment_test)
		using type = vk::PhysicalDeviceRepresentativeFragmentTestFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_scissor_exclusive> {
#if defined(VK_NV_scissor_exclusive)
		using type = vk::PhysicalDeviceExclusiveScissorFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_shader_image_footprint> {
#if defined(VK_NV_shader_image_footprint)
		using type = vk::PhysicalDeviceShaderImageFootprintFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_shader_sm_builtins> {
#if defined(VK_NV_shader_sm_builtins)
		using type = vk::PhysicalDeviceShaderSMBuiltinsFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_shading_rate_image> {
#if defined(VK_NV_shading_rate_image)
		using type = vk::PhysicalDeviceShadingRateImageFeaturesNV;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_viewport_array2> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_viewport_swizzle> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NVX_binary_import> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NVX_image_view_handle> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access> {
#if defined(VK_ARM_rasterization_order_attachment_access)
		using type = vk::PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_ARM_shader_core_builtins> {
#if defined(VK_ARM_shader_core_builtins)
		using type = vk::PhysicalDeviceShaderCoreBuiltinsFeaturesARM;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_FUCHSIA_external_memory> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GGP_frame_token> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_decorate_string> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_display_timing> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_user_type> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask> {
#if defined(VK_HUAWEI_invocation_mask)
		using type = vk::PhysicalDeviceInvocationMaskFeaturesHUAWEI;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading> {
#if defined(VK_HUAWEI_subpass_shading)
		using type = vk::PhysicalDeviceSubpassShadingFeaturesHUAWEI;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_IMG_filter_cubic> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_IMG_format_pvrtc> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_INTEL_performance_query> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2> {
#if defined(VK_INTEL_shader_integer_functions2)
		using type = vk::PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_MVK_ios_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_MVK_macos_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NN_vi_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset> {
#if defined(VK_QCOM_fragment_density_map_offset)
		using type = vk::PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_image_processing> {
#if defined(VK_QCOM_image_processing)
		using type = vk::PhysicalDeviceImageProcessingFeaturesQCOM;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_render_pass_transform> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_tile_properties> {
#if defined(VK_QCOM_tile_properties)
		using type = vk::PhysicalDeviceTilePropertiesFeaturesQCOM;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QNX_screen_surface> {
		using type = AkariVKExtensionFeaturesNotNecessary;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_SEC_amigo_profiling> {
#if defined(VK_SEC_amigo_profiling)
		using type = vk::PhysicalDeviceAmigoProfilingFeaturesSEC;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping> {
#if defined(VK_VALVE_descriptor_set_host_mapping)
		using type = vk::PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type> {
#if defined(VK_VALVE_mutable_descriptor_type)
		using type = vk::PhysicalDeviceMutableDescriptorTypeFeaturesVALVE;
#else
		using type = AkariVKExtensionFeaturesNotAvailable;
#endif;
	};
	struct AkariVKExtensionTraits {
		const char                                           extension_name[64];
		Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags extension_flags;
		Akari::Graphics::Vulkan::Core::AkariVKExtensionType  extension_type;
		uint32_t                                             required_core_version;
		uint32_t                                             promoted_core_version;
		bool                                                 is_partially_promoted;
		uint32_t                                             required_extension_count;
		uint32_t                                             depended_extension_count;
		Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags required_extension_flags[32];
		Akari::Graphics::Vulkan::Core::AkariVKExtensionFlags depended_extension_flags[32];
	};
	namespace Internals {

		static inline constexpr std::array<AkariVKExtensionTraits, static_cast<unsigned int>(AkariVKExtensionFlags::eCount)> AkariVKSupportedExtensionTraitsList = {
			AkariVKExtensionTraits{
				"VK_KHR_16bit_storage", AkariVKExtensionFlags::eVK_KHR_16bit_storage, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_16bit_storage,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_16bit_storage,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_8bit_storage", AkariVKExtensionFlags::eVK_KHR_8bit_storage, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_8bit_storage,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_8bit_storage,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_acceleration_structure", AkariVKExtensionFlags::eVK_KHR_acceleration_structure, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				4, 6,
				{
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_android_surface", AkariVKExtensionFlags::eVK_KHR_android_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_android_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_android_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_bind_memory2", AkariVKExtensionFlags::eVK_KHR_bind_memory2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_buffer_device_address", AkariVKExtensionFlags::eVK_KHR_buffer_device_address, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_copy_commands2", AkariVKExtensionFlags::eVK_KHR_copy_commands2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_copy_commands2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_copy_commands2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_create_renderpass2", AkariVKExtensionFlags::eVK_KHR_create_renderpass2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_dedicated_allocation", AkariVKExtensionFlags::eVK_KHR_dedicated_allocation, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_deferred_host_operations", AkariVKExtensionFlags::eVK_KHR_deferred_host_operations, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_depth_stencil_resolve", AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 5,
				{
					AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_descriptor_update_template", AkariVKExtensionFlags::eVK_KHR_descriptor_update_template, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_descriptor_update_template,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_descriptor_update_template,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_device_group", AkariVKExtensionFlags::eVK_KHR_device_group, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_device_group,
					AkariVKExtensionFlags::eVK_KHR_device_group_creation,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_device_group,
					AkariVKExtensionFlags::eVK_KHR_device_group_creation,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_device_group_creation", AkariVKExtensionFlags::eVK_KHR_device_group_creation, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_device_group_creation,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_device_group_creation,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_display", AkariVKExtensionFlags::eVK_KHR_display, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_display,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_display,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_display_swapchain", AkariVKExtensionFlags::eVK_KHR_display_swapchain, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_display_swapchain,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_display,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_display_swapchain,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_display,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_draw_indirect_count", AkariVKExtensionFlags::eVK_KHR_draw_indirect_count, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_draw_indirect_count,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_draw_indirect_count,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_driver_properties", AkariVKExtensionFlags::eVK_KHR_driver_properties, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_driver_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_driver_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_dynamic_rendering", AkariVKExtensionFlags::eVK_KHR_dynamic_rendering, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				3, 6,
				{
					AkariVKExtensionFlags::eVK_KHR_dynamic_rendering,
					AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_dynamic_rendering,
					AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_fence_capabilities", AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_fence", AkariVKExtensionFlags::eVK_KHR_external_fence, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_external_fence,
					AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_fence,
					AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_fence_fd", AkariVKExtensionFlags::eVK_KHR_external_fence_fd, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_external_fence_fd,
					AkariVKExtensionFlags::eVK_KHR_external_fence,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_fence_fd,
					AkariVKExtensionFlags::eVK_KHR_external_fence,
					AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_fence_win32", AkariVKExtensionFlags::eVK_KHR_external_fence_win32, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_external_fence_win32,
					AkariVKExtensionFlags::eVK_KHR_external_fence,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_fence_win32,
					AkariVKExtensionFlags::eVK_KHR_external_fence,
					AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_memory", AkariVKExtensionFlags::eVK_KHR_external_memory, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_memory_capabilities", AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_memory_fd", AkariVKExtensionFlags::eVK_KHR_external_memory_fd, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_external_memory_fd,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_memory_fd,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_memory_win32", AkariVKExtensionFlags::eVK_KHR_external_memory_win32, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_external_memory_win32,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_memory_win32,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_semaphore_win32", AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_semaphore", AkariVKExtensionFlags::eVK_KHR_external_semaphore, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_external_semaphore,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_semaphore,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_semaphore_capabilities", AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_external_semaphore_fd", AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_format_feature_flags2", AkariVKExtensionFlags::eVK_KHR_format_feature_flags2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_fragment_shader_barycentric", AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_fragment_shading_rate", AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 5,
				{
					AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_get_display_properties2", AkariVKExtensionFlags::eVK_KHR_get_display_properties2, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_get_display_properties2,
					AkariVKExtensionFlags::eVK_KHR_display,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_get_display_properties2,
					AkariVKExtensionFlags::eVK_KHR_display,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_get_memory_requirements2", AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_get_physical_device_properties2", AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_get_surface_capabilities2", AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_global_priority", AkariVKExtensionFlags::eVK_KHR_global_priority, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_global_priority,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_global_priority,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_image_format_list", AkariVKExtensionFlags::eVK_KHR_image_format_list, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_image_format_list,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_image_format_list,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_imageless_framebuffer", AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
					AkariVKExtensionFlags::eVK_KHR_image_format_list,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
					AkariVKExtensionFlags::eVK_KHR_image_format_list,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_incremental_present", AkariVKExtensionFlags::eVK_KHR_incremental_present, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_incremental_present,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_incremental_present,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_maintenance1", AkariVKExtensionFlags::eVK_KHR_maintenance1, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_maintenance2", AkariVKExtensionFlags::eVK_KHR_maintenance2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_maintenance3", AkariVKExtensionFlags::eVK_KHR_maintenance3, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_maintenance4", AkariVKExtensionFlags::eVK_KHR_maintenance4, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_maintenance4,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_maintenance4,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_multiview", AkariVKExtensionFlags::eVK_KHR_multiview, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_performance_query", AkariVKExtensionFlags::eVK_KHR_performance_query, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_performance_query,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_performance_query,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_pipeline_executable_properties", AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_pipeline_library", AkariVKExtensionFlags::eVK_KHR_pipeline_library, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_pipeline_library,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_pipeline_library,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_portability_enumeration", AkariVKExtensionFlags::eVK_KHR_portability_enumeration, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_portability_enumeration,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_portability_enumeration,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_portability_subset", AkariVKExtensionFlags::eVK_KHR_portability_subset, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_portability_subset,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_portability_subset,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_present_id", AkariVKExtensionFlags::eVK_KHR_present_id, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_present_id,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_present_id,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_present_wait", AkariVKExtensionFlags::eVK_KHR_present_wait, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_present_wait,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_present_id,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_present_wait,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_present_id,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_push_descriptor", AkariVKExtensionFlags::eVK_KHR_push_descriptor, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_push_descriptor,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_push_descriptor,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_ray_query", AkariVKExtensionFlags::eVK_KHR_ray_query, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				3, 9,
				{
					AkariVKExtensionFlags::eVK_KHR_ray_query,
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_ray_query,
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_ray_tracing_maintenance1", AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 7,
				{
					AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_ray_tracing_pipeline", AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				3, 9,
				{
					AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_relaxed_block_layout", AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_sampler_mirror_clamp_to_edge", AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_sampler_ycbcr_conversion", AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				5, 5,
				{
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_separate_depth_stencil_layouts", AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				3, 5,
				{
					AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_multiview,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_atomic_int64", AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_clock", AkariVKExtensionFlags::eVK_KHR_shader_clock, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_clock,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_clock,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_draw_parameters", AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_float16_int8", AkariVKExtensionFlags::eVK_KHR_shader_float16_int8, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_float16_int8,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_float16_int8,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_float_controls", AkariVKExtensionFlags::eVK_KHR_shader_float_controls, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_integer_dot_product", AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_non_semantic_info", AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_subgroup_extended_types", AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_subgroup_uniform_control_flow", AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shader_terminate_invocation", AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_shared_presentable_image", AkariVKExtensionFlags::eVK_KHR_shared_presentable_image, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				4, 5,
				{
					AkariVKExtensionFlags::eVK_KHR_shared_presentable_image,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_shared_presentable_image,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_spirv_1_4", AkariVKExtensionFlags::eVK_KHR_spirv_1_4, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
					AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
					AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_storage_buffer_storage_class", AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_surface", AkariVKExtensionFlags::eVK_KHR_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_surface_protected_capabilities", AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_swapchain", AkariVKExtensionFlags::eVK_KHR_swapchain, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_swapchain_mutable_format", AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				4, 5,
				{
					AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
					AkariVKExtensionFlags::eVK_KHR_image_format_list,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
					AkariVKExtensionFlags::eVK_KHR_image_format_list,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_synchronization2", AkariVKExtensionFlags::eVK_KHR_synchronization2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_timeline_semaphore", AkariVKExtensionFlags::eVK_KHR_timeline_semaphore, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_timeline_semaphore,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_timeline_semaphore,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_uniform_buffer_standard_layout", AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_variable_pointers", AkariVKExtensionFlags::eVK_KHR_variable_pointers, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_variable_pointers,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_variable_pointers,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_video_decode_queue", AkariVKExtensionFlags::eVK_KHR_video_decode_queue, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_video_encode_queue", AkariVKExtensionFlags::eVK_KHR_video_encode_queue, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_video_queue", AkariVKExtensionFlags::eVK_KHR_video_queue, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_vulkan_memory_model", AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_wayland_surface", AkariVKExtensionFlags::eVK_KHR_wayland_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_wayland_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_wayland_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_win32_keyed_mutex", AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 5,
				{
					AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex,
					AkariVKExtensionFlags::eVK_KHR_external_memory_win32,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex,
					AkariVKExtensionFlags::eVK_KHR_external_memory_win32,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_win32_surface", AkariVKExtensionFlags::eVK_KHR_win32_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_win32_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_win32_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_workgroup_memory_explicit_layout", AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_xcb_surface", AkariVKExtensionFlags::eVK_KHR_xcb_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_xcb_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_xcb_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_xlib_surface", AkariVKExtensionFlags::eVK_KHR_xlib_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_xlib_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_xlib_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_KHR_zero_initialize_workgroup_memory", AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_4444_formats", AkariVKExtensionFlags::eVK_EXT_4444_formats, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, true,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_4444_formats,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_4444_formats,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_acquire_drm_display", AkariVKExtensionFlags::eVK_EXT_acquire_drm_display, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_EXT_acquire_drm_display,
					AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_acquire_drm_display,
					AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
					AkariVKExtensionFlags::eVK_KHR_display,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_acquire_xlib_display", AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display,
					AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display,
					AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
					AkariVKExtensionFlags::eVK_KHR_display,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_astc_decode_mode", AkariVKExtensionFlags::eVK_EXT_astc_decode_mode, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_astc_decode_mode,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_astc_decode_mode,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_attachment_feedback_loop_layout", AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_blend_operation_advanced", AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_border_color_swizzle", AkariVKExtensionFlags::eVK_EXT_border_color_swizzle, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_border_color_swizzle,
					AkariVKExtensionFlags::eVK_EXT_custom_border_color,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_border_color_swizzle,
					AkariVKExtensionFlags::eVK_EXT_custom_border_color,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_buffer_device_address", AkariVKExtensionFlags::eVK_EXT_buffer_device_address, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_calibrated_timestamps", AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_color_write_enable", AkariVKExtensionFlags::eVK_EXT_color_write_enable, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_color_write_enable,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_color_write_enable,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_conditional_rendering", AkariVKExtensionFlags::eVK_EXT_conditional_rendering, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_conditional_rendering,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_conditional_rendering,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_conservative_rasterization", AkariVKExtensionFlags::eVK_EXT_conservative_rasterization, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_conservative_rasterization,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_conservative_rasterization,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_custom_border_color", AkariVKExtensionFlags::eVK_EXT_custom_border_color, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_custom_border_color,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_custom_border_color,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_debug_marker", AkariVKExtensionFlags::eVK_EXT_debug_marker, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_debug_marker,
					AkariVKExtensionFlags::eVK_EXT_debug_report,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_debug_marker,
					AkariVKExtensionFlags::eVK_EXT_debug_report,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_debug_report", AkariVKExtensionFlags::eVK_EXT_debug_report, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_debug_report,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_debug_report,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_debug_utils", AkariVKExtensionFlags::eVK_EXT_debug_utils, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_debug_utils,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_debug_utils,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_depth_clamp_zero_one", AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_depth_clip_control", AkariVKExtensionFlags::eVK_EXT_depth_clip_control, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_depth_clip_control,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_depth_clip_control,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_depth_clip_enable", AkariVKExtensionFlags::eVK_EXT_depth_clip_enable, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_depth_clip_enable,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_depth_clip_enable,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_depth_range_unrestricted", AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_descriptor_indexing", AkariVKExtensionFlags::eVK_EXT_descriptor_indexing, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_device_address_binding_report", AkariVKExtensionFlags::eVK_EXT_device_address_binding_report, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_device_address_binding_report,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_EXT_debug_utils,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_device_address_binding_report,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_EXT_debug_utils,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_device_fault", AkariVKExtensionFlags::eVK_EXT_device_fault, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_device_fault,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_device_fault,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_device_memory_report", AkariVKExtensionFlags::eVK_EXT_device_memory_report, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_device_memory_report,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_device_memory_report,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_direct_mode_display", AkariVKExtensionFlags::eVK_EXT_direct_mode_display, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
					AkariVKExtensionFlags::eVK_KHR_display,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
					AkariVKExtensionFlags::eVK_KHR_display,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_directfb_surface", AkariVKExtensionFlags::eVK_EXT_directfb_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_directfb_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_directfb_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_discard_rectangles", AkariVKExtensionFlags::eVK_EXT_discard_rectangles, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_discard_rectangles,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_discard_rectangles,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_display_control", AkariVKExtensionFlags::eVK_EXT_display_control, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 5,
				{
					AkariVKExtensionFlags::eVK_EXT_display_control,
					AkariVKExtensionFlags::eVK_EXT_display_surface_counter,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_display_control,
					AkariVKExtensionFlags::eVK_EXT_display_surface_counter,
					AkariVKExtensionFlags::eVK_KHR_display,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_display_surface_counter", AkariVKExtensionFlags::eVK_EXT_display_surface_counter, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_display_surface_counter,
					AkariVKExtensionFlags::eVK_KHR_display,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_display_surface_counter,
					AkariVKExtensionFlags::eVK_KHR_display,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_extended_dynamic_state2", AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_extended_dynamic_state", AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_extended_dynamic_state3", AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_external_memory_dma_buf", AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 5,
				{
					AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf,
					AkariVKExtensionFlags::eVK_KHR_external_memory_fd,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf,
					AkariVKExtensionFlags::eVK_KHR_external_memory_fd,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_external_memory_host", AkariVKExtensionFlags::eVK_EXT_external_memory_host, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_EXT_external_memory_host,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_external_memory_host,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_filter_cubic", AkariVKExtensionFlags::eVK_EXT_filter_cubic, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_filter_cubic,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_filter_cubic,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_fragment_density_map2", AkariVKExtensionFlags::eVK_EXT_fragment_density_map2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_fragment_density_map2,
					AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_fragment_density_map2,
					AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_fragment_density_map", AkariVKExtensionFlags::eVK_EXT_fragment_density_map, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_fragment_shader_interlock", AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_full_screen_exclusive", AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				5, 5,
				{
					AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_global_priority_query", AkariVKExtensionFlags::eVK_EXT_global_priority_query, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_global_priority_query,
					AkariVKExtensionFlags::eVK_EXT_global_priority,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_global_priority_query,
					AkariVKExtensionFlags::eVK_EXT_global_priority,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_global_priority", AkariVKExtensionFlags::eVK_EXT_global_priority, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_global_priority,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_global_priority,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_graphics_pipeline_library", AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_pipeline_library,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_pipeline_library,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_hdr_metadata", AkariVKExtensionFlags::eVK_EXT_hdr_metadata, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_hdr_metadata,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_hdr_metadata,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_headless_surface", AkariVKExtensionFlags::eVK_EXT_headless_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_headless_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_headless_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_host_query_reset", AkariVKExtensionFlags::eVK_EXT_host_query_reset, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_host_query_reset,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_host_query_reset,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_image_2d_view_of_3d", AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_image_compression_control", AkariVKExtensionFlags::eVK_EXT_image_compression_control, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_image_compression_control,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_image_compression_control,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_image_compression_control_swapchain", AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain,
					AkariVKExtensionFlags::eVK_EXT_image_compression_control,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain,
					AkariVKExtensionFlags::eVK_EXT_image_compression_control,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_image_drm_format_modifier", AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				5, 7,
				{
					AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier,
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_image_format_list,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier,
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
					AkariVKExtensionFlags::eVK_KHR_image_format_list,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_image_robustness", AkariVKExtensionFlags::eVK_EXT_image_robustness, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_image_robustness,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_image_robustness,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_image_view_min_lod", AkariVKExtensionFlags::eVK_EXT_image_view_min_lod, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_image_view_min_lod,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_image_view_min_lod,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_index_type_uint8", AkariVKExtensionFlags::eVK_EXT_index_type_uint8, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_index_type_uint8,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_index_type_uint8,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_inline_uniform_block", AkariVKExtensionFlags::eVK_EXT_inline_uniform_block, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_inline_uniform_block,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_inline_uniform_block,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_legacy_dithering", AkariVKExtensionFlags::eVK_EXT_legacy_dithering, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_legacy_dithering,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_legacy_dithering,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_line_rasterization", AkariVKExtensionFlags::eVK_EXT_line_rasterization, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_line_rasterization,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_line_rasterization,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_load_store_op_none", AkariVKExtensionFlags::eVK_EXT_load_store_op_none, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_load_store_op_none,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_load_store_op_none,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_memory_budget", AkariVKExtensionFlags::eVK_EXT_memory_budget, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_memory_budget,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_memory_budget,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_memory_priority", AkariVKExtensionFlags::eVK_EXT_memory_priority, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_memory_priority,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_memory_priority,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_mesh_shader", AkariVKExtensionFlags::eVK_EXT_mesh_shader, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_EXT_mesh_shader,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_mesh_shader,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
					AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_metal_objects", AkariVKExtensionFlags::eVK_EXT_metal_objects, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_metal_objects,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_metal_objects,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_metal_surface", AkariVKExtensionFlags::eVK_EXT_metal_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_metal_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_metal_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_multi_draw", AkariVKExtensionFlags::eVK_EXT_multi_draw, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_multi_draw,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_multi_draw,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_multisampled_render_to_single_sampled", AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 6,
				{
					AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_mutable_descriptor_type", AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_non_seamless_cube_map", AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_opacity_micromap", AkariVKExtensionFlags::eVK_EXT_opacity_micromap, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 8,
				{
					AkariVKExtensionFlags::eVK_EXT_opacity_micromap,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_opacity_micromap,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_pageable_device_local_memory", AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory,
					AkariVKExtensionFlags::eVK_EXT_memory_priority,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory,
					AkariVKExtensionFlags::eVK_EXT_memory_priority,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_pci_bus_info", AkariVKExtensionFlags::eVK_EXT_pci_bus_info, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_pci_bus_info,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_pci_bus_info,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_physical_device_drm", AkariVKExtensionFlags::eVK_EXT_physical_device_drm, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_physical_device_drm,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_physical_device_drm,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_pipeline_creation_cache_control", AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_pipeline_creation_feedback", AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_pipeline_properties", AkariVKExtensionFlags::eVK_EXT_pipeline_properties, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_pipeline_protected_access", AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_pipeline_robustness", AkariVKExtensionFlags::eVK_EXT_pipeline_robustness, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_robustness,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_pipeline_robustness,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_post_depth_coverage", AkariVKExtensionFlags::eVK_EXT_post_depth_coverage, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_post_depth_coverage,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_post_depth_coverage,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_primitive_topology_list_restart", AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_primitives_generated_query", AkariVKExtensionFlags::eVK_EXT_primitives_generated_query, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_primitives_generated_query,
					AkariVKExtensionFlags::eVK_EXT_transform_feedback,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_primitives_generated_query,
					AkariVKExtensionFlags::eVK_EXT_transform_feedback,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_private_data", AkariVKExtensionFlags::eVK_EXT_private_data, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_private_data,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_private_data,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_provoking_vertex", AkariVKExtensionFlags::eVK_EXT_provoking_vertex, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_provoking_vertex,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_provoking_vertex,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_queue_family_foreign", AkariVKExtensionFlags::eVK_EXT_queue_family_foreign, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_EXT_queue_family_foreign,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_queue_family_foreign,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_rasterization_order_attachment_access", AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_rgba10x6_formats", AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 6,
				{
					AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_robustness2", AkariVKExtensionFlags::eVK_EXT_robustness2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_robustness2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_robustness2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_sample_locations", AkariVKExtensionFlags::eVK_EXT_sample_locations, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_sample_locations,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_sample_locations,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_sampler_filter_minmax", AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_scalar_block_layout", AkariVKExtensionFlags::eVK_EXT_scalar_block_layout, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_scalar_block_layout,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_scalar_block_layout,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_separate_stencil_usage", AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_shader_atomic_float2", AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2,
					AkariVKExtensionFlags::eVK_EXT_shader_atomic_float,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2,
					AkariVKExtensionFlags::eVK_EXT_shader_atomic_float,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_shader_atomic_float", AkariVKExtensionFlags::eVK_EXT_shader_atomic_float, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_shader_atomic_float,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_shader_atomic_float,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_shader_demote_to_helper_invocation", AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_shader_image_atomic_int64", AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_shader_module_identifier", AkariVKExtensionFlags::eVK_EXT_shader_module_identifier, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_EXT_shader_module_identifier,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_shader_module_identifier,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_shader_stencil_export", AkariVKExtensionFlags::eVK_EXT_shader_stencil_export, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_shader_stencil_export,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_shader_stencil_export,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_shader_subgroup_ballot", AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_shader_subgroup_vote", AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_shader_viewport_index_layer", AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_2, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_subgroup_size_control", AkariVKExtensionFlags::eVK_EXT_subgroup_size_control, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_subgroup_size_control,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_subgroup_size_control,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_subpass_merge_feedback", AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_swapchain_colorspace", AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_texel_buffer_alignment", AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_texture_compression_astc_hdr", AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_tooling_info", AkariVKExtensionFlags::eVK_EXT_tooling_info, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_tooling_info,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_tooling_info,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_transform_feedback", AkariVKExtensionFlags::eVK_EXT_transform_feedback, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_transform_feedback,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_transform_feedback,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_validation_cache", AkariVKExtensionFlags::eVK_EXT_validation_cache, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_validation_cache,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_validation_cache,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_validation_features", AkariVKExtensionFlags::eVK_EXT_validation_features, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_validation_features,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_validation_features,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_validation_flags", AkariVKExtensionFlags::eVK_EXT_validation_flags, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_EXT_validation_flags,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_validation_flags,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_vertex_attribute_divisor", AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_vertex_input_dynamic_state", AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_video_decode_h264", AkariVKExtensionFlags::eVK_EXT_video_decode_h264, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 5,
				{
					AkariVKExtensionFlags::eVK_EXT_video_decode_h264,
					AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_video_decode_h264,
					AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_video_decode_h265", AkariVKExtensionFlags::eVK_EXT_video_decode_h265, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 5,
				{
					AkariVKExtensionFlags::eVK_EXT_video_decode_h265,
					AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_video_decode_h265,
					AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_video_encode_h264", AkariVKExtensionFlags::eVK_EXT_video_encode_h264, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 5,
				{
					AkariVKExtensionFlags::eVK_EXT_video_encode_h264,
					AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_video_encode_h264,
					AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_video_encode_h265", AkariVKExtensionFlags::eVK_EXT_video_encode_h265, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 5,
				{
					AkariVKExtensionFlags::eVK_EXT_video_encode_h265,
					AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_video_encode_h265,
					AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
					AkariVKExtensionFlags::eVK_KHR_video_queue,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_ycbcr_2plane_444_formats", AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_3, UINT32_MAX, true,
				2, 6,
				{
					AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
				},
			},
			AkariVKExtensionTraits{
				"VK_EXT_ycbcr_image_arrays", AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 6,
				{
					AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
				},
				{
					AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_buffer_marker", AkariVKExtensionFlags::eVK_AMD_buffer_marker, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_buffer_marker,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_buffer_marker,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_device_coherent_memory", AkariVKExtensionFlags::eVK_AMD_device_coherent_memory, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_device_coherent_memory,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_device_coherent_memory,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_display_native_hdr", AkariVKExtensionFlags::eVK_AMD_display_native_hdr, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				4, 5,
				{
					AkariVKExtensionFlags::eVK_AMD_display_native_hdr,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_display_native_hdr,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_draw_indirect_count", AkariVKExtensionFlags::eVK_AMD_draw_indirect_count, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_draw_indirect_count,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_draw_indirect_count,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_gcn_shader", AkariVKExtensionFlags::eVK_AMD_gcn_shader, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_gcn_shader,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_gcn_shader,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_gpu_shader_half_float", AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_gpu_shader_int16", AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_memory_overallocation_behavior", AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_mixed_attachment_samples", AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_negative_viewport_height", AkariVKExtensionFlags::eVK_AMD_negative_viewport_height, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_negative_viewport_height,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_negative_viewport_height,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_pipeline_compiler_control", AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_rasterization_order", AkariVKExtensionFlags::eVK_AMD_rasterization_order, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_rasterization_order,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_rasterization_order,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_shader_ballot", AkariVKExtensionFlags::eVK_AMD_shader_ballot, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_shader_ballot,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_shader_ballot,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_shader_core_properties2", AkariVKExtensionFlags::eVK_AMD_shader_core_properties2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_AMD_shader_core_properties2,
					AkariVKExtensionFlags::eVK_AMD_shader_core_properties,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_shader_core_properties2,
					AkariVKExtensionFlags::eVK_AMD_shader_core_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_shader_core_properties", AkariVKExtensionFlags::eVK_AMD_shader_core_properties, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_AMD_shader_core_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_shader_core_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_shader_early_and_late_fragment_tests", AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_shader_explicit_vertex_parameter", AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_shader_fragment_mask", AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_shader_image_load_store_lod", AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_shader_info", AkariVKExtensionFlags::eVK_AMD_shader_info, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_shader_info,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_shader_info,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_shader_trinary_minmax", AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax,
				},
			},
			AkariVKExtensionTraits{
				"VK_AMD_texture_gather_bias_lod", AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_acquire_winrt_display", AkariVKExtensionFlags::eVK_NV_acquire_winrt_display, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_NV_acquire_winrt_display,
					AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
				},
				{
					AkariVKExtensionFlags::eVK_NV_acquire_winrt_display,
					AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
					AkariVKExtensionFlags::eVK_KHR_display,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_clip_space_w_scaling", AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling,
				},
				{
					AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_compute_shader_derivatives", AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_cooperative_matrix", AkariVKExtensionFlags::eVK_NV_cooperative_matrix, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_cooperative_matrix,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_cooperative_matrix,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_corner_sampled_image", AkariVKExtensionFlags::eVK_NV_corner_sampled_image, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_corner_sampled_image,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_corner_sampled_image,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_coverage_reduction_mode", AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode,
					AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples,
				},
				{
					AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode,
					AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_dedicated_allocation", AkariVKExtensionFlags::eVK_NV_dedicated_allocation, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_dedicated_allocation,
				},
				{
					AkariVKExtensionFlags::eVK_NV_dedicated_allocation,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_dedicated_allocation_image_aliasing", AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing,
					AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
				},
				{
					AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing,
					AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_device_diagnostic_checkpoints", AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_device_diagnostics_config", AkariVKExtensionFlags::eVK_NV_device_diagnostics_config, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_device_diagnostics_config,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_device_diagnostics_config,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_device_generated_commands", AkariVKExtensionFlags::eVK_NV_device_generated_commands, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_NV_device_generated_commands,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
				},
				{
					AkariVKExtensionFlags::eVK_NV_device_generated_commands,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_external_memory", AkariVKExtensionFlags::eVK_NV_external_memory, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_external_memory,
					AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
				},
				{
					AkariVKExtensionFlags::eVK_NV_external_memory,
					AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_external_memory_capabilities", AkariVKExtensionFlags::eVK_NV_external_memory_capabilities, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
				},
				{
					AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_external_memory_rdma", AkariVKExtensionFlags::eVK_NV_external_memory_rdma, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_NV_external_memory_rdma,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
				},
				{
					AkariVKExtensionFlags::eVK_NV_external_memory_rdma,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_external_memory_win32", AkariVKExtensionFlags::eVK_NV_external_memory_win32, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_NV_external_memory_win32,
					AkariVKExtensionFlags::eVK_NV_external_memory,
				},
				{
					AkariVKExtensionFlags::eVK_NV_external_memory_win32,
					AkariVKExtensionFlags::eVK_NV_external_memory,
					AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_fill_rectangle", AkariVKExtensionFlags::eVK_NV_fill_rectangle, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_fill_rectangle,
				},
				{
					AkariVKExtensionFlags::eVK_NV_fill_rectangle,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_fragment_coverage_to_color", AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color,
				},
				{
					AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_fragment_shader_barycentric", AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_fragment_shading_rate_enums", AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 6,
				{
					AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums,
					AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate,
				},
				{
					AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums,
					AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate,
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_framebuffer_mixed_samples", AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples,
				},
				{
					AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_geometry_shader_passthrough", AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough,
				},
				{
					AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_glsl_shader", AkariVKExtensionFlags::eVK_NV_glsl_shader, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_glsl_shader,
				},
				{
					AkariVKExtensionFlags::eVK_NV_glsl_shader,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_inherited_viewport_scissor", AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor,
				},
				{
					AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_linear_color_attachment", AkariVKExtensionFlags::eVK_NV_linear_color_attachment, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_linear_color_attachment,
				},
				{
					AkariVKExtensionFlags::eVK_NV_linear_color_attachment,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_mesh_shader", AkariVKExtensionFlags::eVK_NV_mesh_shader, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_mesh_shader,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_mesh_shader,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_optical_flow", AkariVKExtensionFlags::eVK_NV_optical_flow, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				4, 4,
				{
					AkariVKExtensionFlags::eVK_NV_optical_flow,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_optical_flow,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_present_barrier", AkariVKExtensionFlags::eVK_NV_present_barrier, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				5, 5,
				{
					AkariVKExtensionFlags::eVK_NV_present_barrier,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
				{
					AkariVKExtensionFlags::eVK_NV_present_barrier,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_ray_tracing", AkariVKExtensionFlags::eVK_NV_ray_tracing, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_NV_ray_tracing,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_ray_tracing,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_ray_tracing_motion_blur", AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 10,
				{
					AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur,
					AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
				},
				{
					AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur,
					AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_representative_fragment_test", AkariVKExtensionFlags::eVK_NV_representative_fragment_test, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_representative_fragment_test,
				},
				{
					AkariVKExtensionFlags::eVK_NV_representative_fragment_test,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_sample_mask_override_coverage", AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage,
				},
				{
					AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_scissor_exclusive", AkariVKExtensionFlags::eVK_NV_scissor_exclusive, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_scissor_exclusive,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_scissor_exclusive,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_shader_image_footprint", AkariVKExtensionFlags::eVK_NV_shader_image_footprint, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_shader_image_footprint,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_shader_image_footprint,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_shader_sm_builtins", AkariVKExtensionFlags::eVK_NV_shader_sm_builtins, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_shader_sm_builtins,
				},
				{
					AkariVKExtensionFlags::eVK_NV_shader_sm_builtins,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_shader_subgroup_partitioned", AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_1, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned,
				},
				{
					AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_shading_rate_image", AkariVKExtensionFlags::eVK_NV_shading_rate_image, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NV_shading_rate_image,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_shading_rate_image,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_viewport_array2", AkariVKExtensionFlags::eVK_NV_viewport_array2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_viewport_array2,
				},
				{
					AkariVKExtensionFlags::eVK_NV_viewport_array2,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_viewport_swizzle", AkariVKExtensionFlags::eVK_NV_viewport_swizzle, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NV_viewport_swizzle,
				},
				{
					AkariVKExtensionFlags::eVK_NV_viewport_swizzle,
				},
			},
			AkariVKExtensionTraits{
				"VK_NV_win32_keyed_mutex", AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 4,
				{
					AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex,
					AkariVKExtensionFlags::eVK_NV_external_memory_win32,
				},
				{
					AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex,
					AkariVKExtensionFlags::eVK_NV_external_memory_win32,
					AkariVKExtensionFlags::eVK_NV_external_memory,
					AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
				},
			},
			AkariVKExtensionTraits{
				"VK_NVX_binary_import", AkariVKExtensionFlags::eVK_NVX_binary_import, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NVX_binary_import,
				},
				{
					AkariVKExtensionFlags::eVK_NVX_binary_import,
				},
			},
			AkariVKExtensionTraits{
				"VK_NVX_image_view_handle", AkariVKExtensionFlags::eVK_NVX_image_view_handle, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_NVX_image_view_handle,
				},
				{
					AkariVKExtensionFlags::eVK_NVX_image_view_handle,
				},
			},
			AkariVKExtensionTraits{
				"VK_NVX_multiview_per_view_attributes", AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes,
					AkariVKExtensionFlags::eVK_KHR_multiview,
				},
				{
					AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes,
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_ANDROID_external_memory_android_hardware_buffer", AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				5, 10,
				{
					AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_EXT_queue_family_foreign,
					AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
				},
				{
					AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
					AkariVKExtensionFlags::eVK_EXT_queue_family_foreign,
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
					AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
				},
			},
			AkariVKExtensionTraits{
				"VK_ARM_rasterization_order_attachment_access", AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_ARM_shader_core_builtins", AkariVKExtensionFlags::eVK_ARM_shader_core_builtins, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_ARM_shader_core_builtins,
				},
				{
					AkariVKExtensionFlags::eVK_ARM_shader_core_builtins,
				},
			},
			AkariVKExtensionTraits{
				"VK_FUCHSIA_buffer_collection", AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 9,
				{
					AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection,
					AkariVKExtensionFlags::eVK_FUCHSIA_external_memory,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
				},
				{
					AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection,
					AkariVKExtensionFlags::eVK_FUCHSIA_external_memory,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
					AkariVKExtensionFlags::eVK_KHR_bind_memory2,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_maintenance1,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
					AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
				},
			},
			AkariVKExtensionTraits{
				"VK_FUCHSIA_external_memory", AkariVKExtensionFlags::eVK_FUCHSIA_external_memory, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_FUCHSIA_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
				},
				{
					AkariVKExtensionFlags::eVK_FUCHSIA_external_memory,
					AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_external_memory,
				},
			},
			AkariVKExtensionTraits{
				"VK_FUCHSIA_external_semaphore", AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore,
				},
				{
					AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_external_semaphore,
				},
			},
			AkariVKExtensionTraits{
				"VK_FUCHSIA_imagepipe_surface", AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_GGP_frame_token", AkariVKExtensionFlags::eVK_GGP_frame_token, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_GGP_frame_token,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface,
				},
				{
					AkariVKExtensionFlags::eVK_GGP_frame_token,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
					AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_GGP_stream_descriptor_surface", AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_GOOGLE_decorate_string", AkariVKExtensionFlags::eVK_GOOGLE_decorate_string, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_GOOGLE_decorate_string,
				},
				{
					AkariVKExtensionFlags::eVK_GOOGLE_decorate_string,
				},
			},
			AkariVKExtensionTraits{
				"VK_GOOGLE_display_timing", AkariVKExtensionFlags::eVK_GOOGLE_display_timing, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_GOOGLE_display_timing,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
				},
				{
					AkariVKExtensionFlags::eVK_GOOGLE_display_timing,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_GOOGLE_hlsl_functionality1", AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1,
				},
				{
					AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1,
				},
			},
			AkariVKExtensionTraits{
				"VK_GOOGLE_surfaceless_query", AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_GOOGLE_user_type", AkariVKExtensionFlags::eVK_GOOGLE_user_type, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_GOOGLE_user_type,
				},
				{
					AkariVKExtensionFlags::eVK_GOOGLE_user_type,
				},
			},
			AkariVKExtensionTraits{
				"VK_HUAWEI_invocation_mask", AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 11,
				{
					AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask,
					AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
				{
					AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask,
					AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
					AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
					AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
					AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
					AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
			},
			AkariVKExtensionTraits{
				"VK_HUAWEI_subpass_shading", AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 6,
				{
					AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
				{
					AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading,
					AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
					AkariVKExtensionFlags::eVK_KHR_multiview,
					AkariVKExtensionFlags::eVK_KHR_maintenance2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_KHR_synchronization2,
				},
			},
			AkariVKExtensionTraits{
				"VK_IMG_filter_cubic", AkariVKExtensionFlags::eVK_IMG_filter_cubic, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_IMG_filter_cubic,
				},
				{
					AkariVKExtensionFlags::eVK_IMG_filter_cubic,
				},
			},
			AkariVKExtensionTraits{
				"VK_IMG_format_pvrtc", AkariVKExtensionFlags::eVK_IMG_format_pvrtc, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_IMG_format_pvrtc,
				},
				{
					AkariVKExtensionFlags::eVK_IMG_format_pvrtc,
				},
			},
			AkariVKExtensionTraits{
				"VK_INTEL_performance_query", AkariVKExtensionFlags::eVK_INTEL_performance_query, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_INTEL_performance_query,
				},
				{
					AkariVKExtensionFlags::eVK_INTEL_performance_query,
				},
			},
			AkariVKExtensionTraits{
				"VK_INTEL_shader_integer_functions2", AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_MVK_ios_surface", AkariVKExtensionFlags::eVK_MVK_ios_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_MVK_ios_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_MVK_ios_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_MVK_macos_surface", AkariVKExtensionFlags::eVK_MVK_macos_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_MVK_macos_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_MVK_macos_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_NN_vi_surface", AkariVKExtensionFlags::eVK_NN_vi_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_NN_vi_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_NN_vi_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_QCOM_fragment_density_map_offset", AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
				},
				{
					AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
					AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
				},
			},
			AkariVKExtensionTraits{
				"VK_QCOM_image_processing", AkariVKExtensionFlags::eVK_QCOM_image_processing, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_QCOM_image_processing,
					AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
				},
				{
					AkariVKExtensionFlags::eVK_QCOM_image_processing,
					AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_QCOM_render_pass_shader_resolve", AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve,
				},
				{
					AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve,
				},
			},
			AkariVKExtensionTraits{
				"VK_QCOM_render_pass_store_ops", AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops,
				},
				{
					AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops,
				},
			},
			AkariVKExtensionTraits{
				"VK_QCOM_render_pass_transform", AkariVKExtensionFlags::eVK_QCOM_render_pass_transform, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 3,
				{
					AkariVKExtensionFlags::eVK_QCOM_render_pass_transform,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_QCOM_render_pass_transform,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_QCOM_rotated_copy_commands", AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				3, 4,
				{
					AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_copy_commands2,
				},
				{
					AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands,
					AkariVKExtensionFlags::eVK_KHR_swapchain,
					AkariVKExtensionFlags::eVK_KHR_copy_commands2,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_QCOM_tile_properties", AkariVKExtensionFlags::eVK_QCOM_tile_properties, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_QCOM_tile_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_QCOM_tile_properties,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_QNX_screen_surface", AkariVKExtensionFlags::eVK_QNX_screen_surface, AkariVKExtensionType::eInstance,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_QNX_screen_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
				{
					AkariVKExtensionFlags::eVK_QNX_screen_surface,
					AkariVKExtensionFlags::eVK_KHR_surface,
				},
			},
			AkariVKExtensionTraits{
				"VK_SEC_amigo_profiling", AkariVKExtensionFlags::eVK_SEC_amigo_profiling, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 2,
				{
					AkariVKExtensionFlags::eVK_SEC_amigo_profiling,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
				{
					AkariVKExtensionFlags::eVK_SEC_amigo_profiling,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
			AkariVKExtensionTraits{
				"VK_VALVE_descriptor_set_host_mapping", AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				1, 1,
				{
					AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping,
				},
				{
					AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping,
				},
			},
			AkariVKExtensionTraits{
				"VK_VALVE_mutable_descriptor_type", AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type, AkariVKExtensionType::eDevice,
				AKARI_GRAPHICS_VK_CORE_API_VERSION_1_0, UINT32_MAX, false,
				2, 3,
				{
					AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
				},
				{
					AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type,
					AkariVKExtensionFlags::eVK_KHR_maintenance3,
					AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
				},
			},
		};
	}

}
inline constexpr auto  to_traits(AkariVKExtensionFlags flags)->AkariVKExtensionTraits
{
	return Internals::AkariVKSupportedExtensionTraitsList[static_cast<unsigned short>(flags)];
}
inline constexpr auto  to_string(AkariVKExtensionFlags flags)->const char*
{
	return Internals::AkariVKSupportedExtensionTraitsList[static_cast<unsigned short>(flags)].extension_name;
}
inline constexpr auto find_flags(const char* extension_name)->AkariVKExtensionFlags
{
	uint16_t i = 0;
	for (auto& extension_traits : Internals::AkariVKSupportedExtensionTraitsList)
	{
		if (std::string_view(extension_name) == std::string_view(extension_traits.extension_name))
		{
			return static_cast<AkariVKExtensionFlags>(i);
		}
		++i;
	}
	return AkariVKExtensionFlags::eCount;
}
AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_END
#endif