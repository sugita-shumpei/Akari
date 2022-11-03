#ifndef AKARI_GRAPHICS_VK_CORE_EXTENSION_H
#define AKARI_GRAPHICS_VK_CORE_EXTENSION_H
#include <Akari/Graphics/Vulkan/Core/AkariVKCore.h>
#include <tuple>
AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_BEGIN
namespace {
	enum class AkariVKExtensionType :unsigned int {
		eInstance,
		eDevice,
	};
	enum class AkariVKExtensionFlags :unsigned int {
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
	enum class AkariVKInstanceExtensionFlags :unsigned int {
		eVK_KHR_android_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_android_surface),
		eVK_KHR_device_group_creation = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_device_group_creation),
		eVK_KHR_display = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_display),
		eVK_KHR_external_fence_capabilities = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities),
		eVK_KHR_external_memory_capabilities = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities),
		eVK_KHR_external_semaphore_capabilities = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities),
		eVK_KHR_get_display_properties2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_get_display_properties2),
		eVK_KHR_get_physical_device_properties2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2),
		eVK_KHR_get_surface_capabilities2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2),
		eVK_KHR_portability_enumeration = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_portability_enumeration),
		eVK_KHR_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_surface),
		eVK_KHR_surface_protected_capabilities = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities),
		eVK_KHR_wayland_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_wayland_surface),
		eVK_KHR_win32_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_win32_surface),
		eVK_KHR_xcb_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_xcb_surface),
		eVK_KHR_xlib_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_xlib_surface),
		eVK_EXT_acquire_drm_display = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_acquire_drm_display),
		eVK_EXT_acquire_xlib_display = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display),
		eVK_EXT_debug_report = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_debug_report),
		eVK_EXT_debug_utils = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_debug_utils),
		eVK_EXT_direct_mode_display = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_direct_mode_display),
		eVK_EXT_directfb_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_directfb_surface),
		eVK_EXT_display_surface_counter = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_display_surface_counter),
		eVK_EXT_headless_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_headless_surface),
		eVK_EXT_metal_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_metal_surface),
		eVK_EXT_swapchain_colorspace = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace),
		eVK_EXT_validation_features = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_validation_features),
		eVK_EXT_validation_flags = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_validation_flags),
		eVK_NV_external_memory_capabilities = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_external_memory_capabilities),
		eVK_FUCHSIA_imagepipe_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface),
		eVK_GGP_stream_descriptor_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface),
		eVK_GOOGLE_surfaceless_query = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query),
		eVK_MVK_ios_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_MVK_ios_surface),
		eVK_MVK_macos_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_MVK_macos_surface),
		eVK_NN_vi_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NN_vi_surface),
		eVK_QNX_screen_surface = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_QNX_screen_surface),
	};
	enum class AkariVKDeviceExtensionFlags :unsigned int {
		eVK_KHR_16bit_storage = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_16bit_storage),
		eVK_KHR_8bit_storage = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_8bit_storage),
		eVK_KHR_acceleration_structure = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_acceleration_structure),
		eVK_KHR_bind_memory2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_bind_memory2),
		eVK_KHR_buffer_device_address = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_buffer_device_address),
		eVK_KHR_copy_commands2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_copy_commands2),
		eVK_KHR_create_renderpass2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_create_renderpass2),
		eVK_KHR_dedicated_allocation = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_dedicated_allocation),
		eVK_KHR_deferred_host_operations = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_deferred_host_operations),
		eVK_KHR_depth_stencil_resolve = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve),
		eVK_KHR_descriptor_update_template = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_descriptor_update_template),
		eVK_KHR_device_group = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_device_group),
		eVK_KHR_display_swapchain = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_display_swapchain),
		eVK_KHR_draw_indirect_count = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_draw_indirect_count),
		eVK_KHR_driver_properties = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_driver_properties),
		eVK_KHR_dynamic_rendering = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_dynamic_rendering),
		eVK_KHR_external_fence = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_fence),
		eVK_KHR_external_fence_fd = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_fence_fd),
		eVK_KHR_external_fence_win32 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_fence_win32),
		eVK_KHR_external_memory = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_memory),
		eVK_KHR_external_memory_fd = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_memory_fd),
		eVK_KHR_external_memory_win32 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_memory_win32),
		eVK_KHR_external_semaphore_win32 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32),
		eVK_KHR_external_semaphore = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_semaphore),
		eVK_KHR_external_semaphore_fd = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd),
		eVK_KHR_format_feature_flags2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_format_feature_flags2),
		eVK_KHR_fragment_shader_barycentric = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric),
		eVK_KHR_fragment_shading_rate = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate),
		eVK_KHR_get_memory_requirements2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2),
		eVK_KHR_global_priority = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_global_priority),
		eVK_KHR_image_format_list = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_image_format_list),
		eVK_KHR_imageless_framebuffer = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer),
		eVK_KHR_incremental_present = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_incremental_present),
		eVK_KHR_maintenance1 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_maintenance1),
		eVK_KHR_maintenance2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_maintenance2),
		eVK_KHR_maintenance3 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_maintenance3),
		eVK_KHR_maintenance4 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_maintenance4),
		eVK_KHR_multiview = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_multiview),
		eVK_KHR_performance_query = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_performance_query),
		eVK_KHR_pipeline_executable_properties = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties),
		eVK_KHR_pipeline_library = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_pipeline_library),
		eVK_KHR_portability_subset = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_portability_subset),
		eVK_KHR_present_id = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_present_id),
		eVK_KHR_present_wait = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_present_wait),
		eVK_KHR_push_descriptor = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_push_descriptor),
		eVK_KHR_ray_query = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_ray_query),
		eVK_KHR_ray_tracing_maintenance1 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1),
		eVK_KHR_ray_tracing_pipeline = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline),
		eVK_KHR_relaxed_block_layout = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout),
		eVK_KHR_sampler_mirror_clamp_to_edge = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge),
		eVK_KHR_sampler_ycbcr_conversion = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion),
		eVK_KHR_separate_depth_stencil_layouts = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts),
		eVK_KHR_shader_atomic_int64 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64),
		eVK_KHR_shader_clock = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_clock),
		eVK_KHR_shader_draw_parameters = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters),
		eVK_KHR_shader_float16_int8 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_float16_int8),
		eVK_KHR_shader_float_controls = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_float_controls),
		eVK_KHR_shader_integer_dot_product = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product),
		eVK_KHR_shader_non_semantic_info = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info),
		eVK_KHR_shader_subgroup_extended_types = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types),
		eVK_KHR_shader_subgroup_uniform_control_flow = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow),
		eVK_KHR_shader_terminate_invocation = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation),
		eVK_KHR_shared_presentable_image = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_shared_presentable_image),
		eVK_KHR_spirv_1_4 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_spirv_1_4),
		eVK_KHR_storage_buffer_storage_class = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class),
		eVK_KHR_swapchain = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_swapchain),
		eVK_KHR_swapchain_mutable_format = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format),
		eVK_KHR_synchronization2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_synchronization2),
		eVK_KHR_timeline_semaphore = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_timeline_semaphore),
		eVK_KHR_uniform_buffer_standard_layout = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout),
		eVK_KHR_variable_pointers = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_variable_pointers),
		eVK_KHR_video_decode_queue = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_video_decode_queue),
		eVK_KHR_video_encode_queue = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_video_encode_queue),
		eVK_KHR_video_queue = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_video_queue),
		eVK_KHR_vulkan_memory_model = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model),
		eVK_KHR_win32_keyed_mutex = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex),
		eVK_KHR_workgroup_memory_explicit_layout = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout),
		eVK_KHR_zero_initialize_workgroup_memory = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory),
		eVK_EXT_4444_formats = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_4444_formats),
		eVK_EXT_astc_decode_mode = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_astc_decode_mode),
		eVK_EXT_attachment_feedback_loop_layout = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout),
		eVK_EXT_blend_operation_advanced = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced),
		eVK_EXT_border_color_swizzle = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_border_color_swizzle),
		eVK_EXT_buffer_device_address = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_buffer_device_address),
		eVK_EXT_calibrated_timestamps = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps),
		eVK_EXT_color_write_enable = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_color_write_enable),
		eVK_EXT_conditional_rendering = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_conditional_rendering),
		eVK_EXT_conservative_rasterization = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_conservative_rasterization),
		eVK_EXT_custom_border_color = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_custom_border_color),
		eVK_EXT_debug_marker = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_debug_marker),
		eVK_EXT_depth_clamp_zero_one = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one),
		eVK_EXT_depth_clip_control = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_depth_clip_control),
		eVK_EXT_depth_clip_enable = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_depth_clip_enable),
		eVK_EXT_depth_range_unrestricted = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted),
		eVK_EXT_descriptor_indexing = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_descriptor_indexing),
		eVK_EXT_device_address_binding_report = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_device_address_binding_report),
		eVK_EXT_device_fault = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_device_fault),
		eVK_EXT_device_memory_report = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_device_memory_report),
		eVK_EXT_discard_rectangles = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_discard_rectangles),
		eVK_EXT_display_control = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_display_control),
		eVK_EXT_extended_dynamic_state2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2),
		eVK_EXT_extended_dynamic_state = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state),
		eVK_EXT_extended_dynamic_state3 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3),
		eVK_EXT_external_memory_dma_buf = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf),
		eVK_EXT_external_memory_host = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_external_memory_host),
		eVK_EXT_filter_cubic = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_filter_cubic),
		eVK_EXT_fragment_density_map2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_fragment_density_map2),
		eVK_EXT_fragment_density_map = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_fragment_density_map),
		eVK_EXT_fragment_shader_interlock = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock),
		eVK_EXT_full_screen_exclusive = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive),
		eVK_EXT_global_priority_query = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_global_priority_query),
		eVK_EXT_global_priority = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_global_priority),
		eVK_EXT_graphics_pipeline_library = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library),
		eVK_EXT_hdr_metadata = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_hdr_metadata),
		eVK_EXT_host_query_reset = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_host_query_reset),
		eVK_EXT_image_2d_view_of_3d = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d),
		eVK_EXT_image_compression_control = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_image_compression_control),
		eVK_EXT_image_compression_control_swapchain = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain),
		eVK_EXT_image_drm_format_modifier = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier),
		eVK_EXT_image_robustness = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_image_robustness),
		eVK_EXT_image_view_min_lod = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_image_view_min_lod),
		eVK_EXT_index_type_uint8 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_index_type_uint8),
		eVK_EXT_inline_uniform_block = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_inline_uniform_block),
		eVK_EXT_legacy_dithering = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_legacy_dithering),
		eVK_EXT_line_rasterization = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_line_rasterization),
		eVK_EXT_load_store_op_none = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_load_store_op_none),
		eVK_EXT_memory_budget = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_memory_budget),
		eVK_EXT_memory_priority = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_memory_priority),
		eVK_EXT_mesh_shader = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_mesh_shader),
		eVK_EXT_metal_objects = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_metal_objects),
		eVK_EXT_multi_draw = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_multi_draw),
		eVK_EXT_multisampled_render_to_single_sampled = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled),
		eVK_EXT_mutable_descriptor_type = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type),
		eVK_EXT_non_seamless_cube_map = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map),
		eVK_EXT_opacity_micromap = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_opacity_micromap),
		eVK_EXT_pageable_device_local_memory = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory),
		eVK_EXT_pci_bus_info = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_pci_bus_info),
		eVK_EXT_physical_device_drm = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_physical_device_drm),
		eVK_EXT_pipeline_creation_cache_control = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control),
		eVK_EXT_pipeline_creation_feedback = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback),
		eVK_EXT_pipeline_properties = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_pipeline_properties),
		eVK_EXT_pipeline_protected_access = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access),
		eVK_EXT_pipeline_robustness = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_pipeline_robustness),
		eVK_EXT_post_depth_coverage = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_post_depth_coverage),
		eVK_EXT_primitive_topology_list_restart = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart),
		eVK_EXT_primitives_generated_query = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_primitives_generated_query),
		eVK_EXT_private_data = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_private_data),
		eVK_EXT_provoking_vertex = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_provoking_vertex),
		eVK_EXT_queue_family_foreign = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_queue_family_foreign),
		eVK_EXT_rasterization_order_attachment_access = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access),
		eVK_EXT_rgba10x6_formats = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats),
		eVK_EXT_robustness2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_robustness2),
		eVK_EXT_sample_locations = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_sample_locations),
		eVK_EXT_sampler_filter_minmax = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax),
		eVK_EXT_scalar_block_layout = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_scalar_block_layout),
		eVK_EXT_separate_stencil_usage = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage),
		eVK_EXT_shader_atomic_float2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2),
		eVK_EXT_shader_atomic_float = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_shader_atomic_float),
		eVK_EXT_shader_demote_to_helper_invocation = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation),
		eVK_EXT_shader_image_atomic_int64 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64),
		eVK_EXT_shader_module_identifier = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_shader_module_identifier),
		eVK_EXT_shader_stencil_export = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_shader_stencil_export),
		eVK_EXT_shader_subgroup_ballot = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot),
		eVK_EXT_shader_subgroup_vote = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote),
		eVK_EXT_shader_viewport_index_layer = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer),
		eVK_EXT_subgroup_size_control = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_subgroup_size_control),
		eVK_EXT_subpass_merge_feedback = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback),
		eVK_EXT_texel_buffer_alignment = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment),
		eVK_EXT_texture_compression_astc_hdr = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr),
		eVK_EXT_tooling_info = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_tooling_info),
		eVK_EXT_transform_feedback = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_transform_feedback),
		eVK_EXT_validation_cache = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_validation_cache),
		eVK_EXT_vertex_attribute_divisor = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor),
		eVK_EXT_vertex_input_dynamic_state = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state),
		eVK_EXT_video_decode_h264 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_video_decode_h264),
		eVK_EXT_video_decode_h265 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_video_decode_h265),
		eVK_EXT_video_encode_h264 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_video_encode_h264),
		eVK_EXT_video_encode_h265 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_video_encode_h265),
		eVK_EXT_ycbcr_2plane_444_formats = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats),
		eVK_EXT_ycbcr_image_arrays = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays),
		eVK_AMD_buffer_marker = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_buffer_marker),
		eVK_AMD_device_coherent_memory = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_device_coherent_memory),
		eVK_AMD_display_native_hdr = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_display_native_hdr),
		eVK_AMD_draw_indirect_count = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_draw_indirect_count),
		eVK_AMD_gcn_shader = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_gcn_shader),
		eVK_AMD_gpu_shader_half_float = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float),
		eVK_AMD_gpu_shader_int16 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16),
		eVK_AMD_memory_overallocation_behavior = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior),
		eVK_AMD_mixed_attachment_samples = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples),
		eVK_AMD_negative_viewport_height = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_negative_viewport_height),
		eVK_AMD_pipeline_compiler_control = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control),
		eVK_AMD_rasterization_order = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_rasterization_order),
		eVK_AMD_shader_ballot = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_shader_ballot),
		eVK_AMD_shader_core_properties2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_shader_core_properties2),
		eVK_AMD_shader_core_properties = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_shader_core_properties),
		eVK_AMD_shader_early_and_late_fragment_tests = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests),
		eVK_AMD_shader_explicit_vertex_parameter = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter),
		eVK_AMD_shader_fragment_mask = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask),
		eVK_AMD_shader_image_load_store_lod = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod),
		eVK_AMD_shader_info = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_shader_info),
		eVK_AMD_shader_trinary_minmax = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax),
		eVK_AMD_texture_gather_bias_lod = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod),
		eVK_NV_acquire_winrt_display = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_acquire_winrt_display),
		eVK_NV_clip_space_w_scaling = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling),
		eVK_NV_compute_shader_derivatives = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives),
		eVK_NV_cooperative_matrix = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_cooperative_matrix),
		eVK_NV_corner_sampled_image = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_corner_sampled_image),
		eVK_NV_coverage_reduction_mode = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode),
		eVK_NV_dedicated_allocation = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_dedicated_allocation),
		eVK_NV_dedicated_allocation_image_aliasing = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing),
		eVK_NV_device_diagnostic_checkpoints = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints),
		eVK_NV_device_diagnostics_config = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_device_diagnostics_config),
		eVK_NV_device_generated_commands = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_device_generated_commands),
		eVK_NV_external_memory = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_external_memory),
		eVK_NV_external_memory_rdma = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_external_memory_rdma),
		eVK_NV_external_memory_win32 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_external_memory_win32),
		eVK_NV_fill_rectangle = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_fill_rectangle),
		eVK_NV_fragment_coverage_to_color = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color),
		eVK_NV_fragment_shader_barycentric = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric),
		eVK_NV_fragment_shading_rate_enums = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums),
		eVK_NV_framebuffer_mixed_samples = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples),
		eVK_NV_geometry_shader_passthrough = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough),
		eVK_NV_glsl_shader = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_glsl_shader),
		eVK_NV_inherited_viewport_scissor = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor),
		eVK_NV_linear_color_attachment = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_linear_color_attachment),
		eVK_NV_mesh_shader = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_mesh_shader),
		eVK_NV_optical_flow = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_optical_flow),
		eVK_NV_present_barrier = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_present_barrier),
		eVK_NV_ray_tracing = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_ray_tracing),
		eVK_NV_ray_tracing_motion_blur = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur),
		eVK_NV_representative_fragment_test = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_representative_fragment_test),
		eVK_NV_sample_mask_override_coverage = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage),
		eVK_NV_scissor_exclusive = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_scissor_exclusive),
		eVK_NV_shader_image_footprint = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_shader_image_footprint),
		eVK_NV_shader_sm_builtins = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_shader_sm_builtins),
		eVK_NV_shader_subgroup_partitioned = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned),
		eVK_NV_shading_rate_image = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_shading_rate_image),
		eVK_NV_viewport_array2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_viewport_array2),
		eVK_NV_viewport_swizzle = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_viewport_swizzle),
		eVK_NV_win32_keyed_mutex = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex),
		eVK_NVX_binary_import = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NVX_binary_import),
		eVK_NVX_image_view_handle = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NVX_image_view_handle),
		eVK_NVX_multiview_per_view_attributes = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes),
		eVK_ANDROID_external_memory_android_hardware_buffer = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer),
		eVK_ARM_rasterization_order_attachment_access = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access),
		eVK_ARM_shader_core_builtins = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_ARM_shader_core_builtins),
		eVK_FUCHSIA_buffer_collection = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection),
		eVK_FUCHSIA_external_memory = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_FUCHSIA_external_memory),
		eVK_FUCHSIA_external_semaphore = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore),
		eVK_GGP_frame_token = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_GGP_frame_token),
		eVK_GOOGLE_decorate_string = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_GOOGLE_decorate_string),
		eVK_GOOGLE_display_timing = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_GOOGLE_display_timing),
		eVK_GOOGLE_hlsl_functionality1 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1),
		eVK_GOOGLE_user_type = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_GOOGLE_user_type),
		eVK_HUAWEI_invocation_mask = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask),
		eVK_HUAWEI_subpass_shading = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading),
		eVK_IMG_filter_cubic = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_IMG_filter_cubic),
		eVK_IMG_format_pvrtc = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_IMG_format_pvrtc),
		eVK_INTEL_performance_query = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_INTEL_performance_query),
		eVK_INTEL_shader_integer_functions2 = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2),
		eVK_QCOM_fragment_density_map_offset = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset),
		eVK_QCOM_image_processing = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_QCOM_image_processing),
		eVK_QCOM_render_pass_shader_resolve = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve),
		eVK_QCOM_render_pass_store_ops = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops),
		eVK_QCOM_render_pass_transform = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_QCOM_render_pass_transform),
		eVK_QCOM_rotated_copy_commands = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands),
		eVK_QCOM_tile_properties = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_QCOM_tile_properties),
		eVK_SEC_amigo_profiling = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_SEC_amigo_profiling),
		eVK_VALVE_descriptor_set_host_mapping = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping),
		eVK_VALVE_mutable_descriptor_type = static_cast<unsigned int>(AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type),
	};
	static constexpr std::array<const char*, static_cast<uint32_t>(AkariVKExtensionFlags::eCount)> AkariVKSupportedExtensionNames{
		"VK_KHR_16bit_storage",
		"VK_KHR_8bit_storage",
		"VK_KHR_acceleration_structure",
		"VK_KHR_android_surface",
		"VK_KHR_bind_memory2",
		"VK_KHR_buffer_device_address",
		"VK_KHR_copy_commands2",
		"VK_KHR_create_renderpass2",
		"VK_KHR_dedicated_allocation",
		"VK_KHR_deferred_host_operations",
		"VK_KHR_depth_stencil_resolve",
		"VK_KHR_descriptor_update_template",
		"VK_KHR_device_group",
		"VK_KHR_device_group_creation",
		"VK_KHR_display",
		"VK_KHR_display_swapchain",
		"VK_KHR_draw_indirect_count",
		"VK_KHR_driver_properties",
		"VK_KHR_dynamic_rendering",
		"VK_KHR_external_fence_capabilities",
		"VK_KHR_external_fence",
		"VK_KHR_external_fence_fd",
		"VK_KHR_external_fence_win32",
		"VK_KHR_external_memory",
		"VK_KHR_external_memory_capabilities",
		"VK_KHR_external_memory_fd",
		"VK_KHR_external_memory_win32",
		"VK_KHR_external_semaphore_win32",
		"VK_KHR_external_semaphore",
		"VK_KHR_external_semaphore_capabilities",
		"VK_KHR_external_semaphore_fd",
		"VK_KHR_format_feature_flags2",
		"VK_KHR_fragment_shader_barycentric",
		"VK_KHR_fragment_shading_rate",
		"VK_KHR_get_display_properties2",
		"VK_KHR_get_memory_requirements2",
		"VK_KHR_get_physical_device_properties2",
		"VK_KHR_get_surface_capabilities2",
		"VK_KHR_global_priority",
		"VK_KHR_image_format_list",
		"VK_KHR_imageless_framebuffer",
		"VK_KHR_incremental_present",
		"VK_KHR_maintenance1",
		"VK_KHR_maintenance2",
		"VK_KHR_maintenance3",
		"VK_KHR_maintenance4",
		"VK_KHR_multiview",
		"VK_KHR_performance_query",
		"VK_KHR_pipeline_executable_properties",
		"VK_KHR_pipeline_library",
		"VK_KHR_portability_enumeration",
		"VK_KHR_portability_subset",
		"VK_KHR_present_id",
		"VK_KHR_present_wait",
		"VK_KHR_push_descriptor",
		"VK_KHR_ray_query",
		"VK_KHR_ray_tracing_maintenance1",
		"VK_KHR_ray_tracing_pipeline",
		"VK_KHR_relaxed_block_layout",
		"VK_KHR_sampler_mirror_clamp_to_edge",
		"VK_KHR_sampler_ycbcr_conversion",
		"VK_KHR_separate_depth_stencil_layouts",
		"VK_KHR_shader_atomic_int64",
		"VK_KHR_shader_clock",
		"VK_KHR_shader_draw_parameters",
		"VK_KHR_shader_float16_int8",
		"VK_KHR_shader_float_controls",
		"VK_KHR_shader_integer_dot_product",
		"VK_KHR_shader_non_semantic_info",
		"VK_KHR_shader_subgroup_extended_types",
		"VK_KHR_shader_subgroup_uniform_control_flow",
		"VK_KHR_shader_terminate_invocation",
		"VK_KHR_shared_presentable_image",
		"VK_KHR_spirv_1_4",
		"VK_KHR_storage_buffer_storage_class",
		"VK_KHR_surface",
		"VK_KHR_surface_protected_capabilities",
		"VK_KHR_swapchain",
		"VK_KHR_swapchain_mutable_format",
		"VK_KHR_synchronization2",
		"VK_KHR_timeline_semaphore",
		"VK_KHR_uniform_buffer_standard_layout",
		"VK_KHR_variable_pointers",
		"VK_KHR_video_decode_queue",
		"VK_KHR_video_encode_queue",
		"VK_KHR_video_queue",
		"VK_KHR_vulkan_memory_model",
		"VK_KHR_wayland_surface",
		"VK_KHR_win32_keyed_mutex",
		"VK_KHR_win32_surface",
		"VK_KHR_workgroup_memory_explicit_layout",
		"VK_KHR_xcb_surface",
		"VK_KHR_xlib_surface",
		"VK_KHR_zero_initialize_workgroup_memory",
		"VK_EXT_4444_formats",
		"VK_EXT_acquire_drm_display",
		"VK_EXT_acquire_xlib_display",
		"VK_EXT_astc_decode_mode",
		"VK_EXT_attachment_feedback_loop_layout",
		"VK_EXT_blend_operation_advanced",
		"VK_EXT_border_color_swizzle",
		"VK_EXT_buffer_device_address",
		"VK_EXT_calibrated_timestamps",
		"VK_EXT_color_write_enable",
		"VK_EXT_conditional_rendering",
		"VK_EXT_conservative_rasterization",
		"VK_EXT_custom_border_color",
		"VK_EXT_debug_marker",
		"VK_EXT_debug_report",
		"VK_EXT_debug_utils",
		"VK_EXT_depth_clamp_zero_one",
		"VK_EXT_depth_clip_control",
		"VK_EXT_depth_clip_enable",
		"VK_EXT_depth_range_unrestricted",
		"VK_EXT_descriptor_indexing",
		"VK_EXT_device_address_binding_report",
		"VK_EXT_device_fault",
		"VK_EXT_device_memory_report",
		"VK_EXT_direct_mode_display",
		"VK_EXT_directfb_surface",
		"VK_EXT_discard_rectangles",
		"VK_EXT_display_control",
		"VK_EXT_display_surface_counter",
		"VK_EXT_extended_dynamic_state2",
		"VK_EXT_extended_dynamic_state",
		"VK_EXT_extended_dynamic_state3",
		"VK_EXT_external_memory_dma_buf",
		"VK_EXT_external_memory_host",
		"VK_EXT_filter_cubic",
		"VK_EXT_fragment_density_map2",
		"VK_EXT_fragment_density_map",
		"VK_EXT_fragment_shader_interlock",
		"VK_EXT_full_screen_exclusive",
		"VK_EXT_global_priority_query",
		"VK_EXT_global_priority",
		"VK_EXT_graphics_pipeline_library",
		"VK_EXT_hdr_metadata",
		"VK_EXT_headless_surface",
		"VK_EXT_host_query_reset",
		"VK_EXT_image_2d_view_of_3d",
		"VK_EXT_image_compression_control",
		"VK_EXT_image_compression_control_swapchain",
		"VK_EXT_image_drm_format_modifier",
		"VK_EXT_image_robustness",
		"VK_EXT_image_view_min_lod",
		"VK_EXT_index_type_uint8",
		"VK_EXT_inline_uniform_block",
		"VK_EXT_legacy_dithering",
		"VK_EXT_line_rasterization",
		"VK_EXT_load_store_op_none",
		"VK_EXT_memory_budget",
		"VK_EXT_memory_priority",
		"VK_EXT_mesh_shader",
		"VK_EXT_metal_objects",
		"VK_EXT_metal_surface",
		"VK_EXT_multi_draw",
		"VK_EXT_multisampled_render_to_single_sampled",
		"VK_EXT_mutable_descriptor_type",
		"VK_EXT_non_seamless_cube_map",
		"VK_EXT_opacity_micromap",
		"VK_EXT_pageable_device_local_memory",
		"VK_EXT_pci_bus_info",
		"VK_EXT_physical_device_drm",
		"VK_EXT_pipeline_creation_cache_control",
		"VK_EXT_pipeline_creation_feedback",
		"VK_EXT_pipeline_properties",
		"VK_EXT_pipeline_protected_access",
		"VK_EXT_pipeline_robustness",
		"VK_EXT_post_depth_coverage",
		"VK_EXT_primitive_topology_list_restart",
		"VK_EXT_primitives_generated_query",
		"VK_EXT_private_data",
		"VK_EXT_provoking_vertex",
		"VK_EXT_queue_family_foreign",
		"VK_EXT_rasterization_order_attachment_access",
		"VK_EXT_rgba10x6_formats",
		"VK_EXT_robustness2",
		"VK_EXT_sample_locations",
		"VK_EXT_sampler_filter_minmax",
		"VK_EXT_scalar_block_layout",
		"VK_EXT_separate_stencil_usage",
		"VK_EXT_shader_atomic_float2",
		"VK_EXT_shader_atomic_float",
		"VK_EXT_shader_demote_to_helper_invocation",
		"VK_EXT_shader_image_atomic_int64",
		"VK_EXT_shader_module_identifier",
		"VK_EXT_shader_stencil_export",
		"VK_EXT_shader_subgroup_ballot",
		"VK_EXT_shader_subgroup_vote",
		"VK_EXT_shader_viewport_index_layer",
		"VK_EXT_subgroup_size_control",
		"VK_EXT_subpass_merge_feedback",
		"VK_EXT_swapchain_colorspace",
		"VK_EXT_texel_buffer_alignment",
		"VK_EXT_texture_compression_astc_hdr",
		"VK_EXT_tooling_info",
		"VK_EXT_transform_feedback",
		"VK_EXT_validation_cache",
		"VK_EXT_validation_features",
		"VK_EXT_validation_flags",
		"VK_EXT_vertex_attribute_divisor",
		"VK_EXT_vertex_input_dynamic_state",
		"VK_EXT_video_decode_h264",
		"VK_EXT_video_decode_h265",
		"VK_EXT_video_encode_h264",
		"VK_EXT_video_encode_h265",
		"VK_EXT_ycbcr_2plane_444_formats",
		"VK_EXT_ycbcr_image_arrays",
		"VK_AMD_buffer_marker",
		"VK_AMD_device_coherent_memory",
		"VK_AMD_display_native_hdr",
		"VK_AMD_draw_indirect_count",
		"VK_AMD_gcn_shader",
		"VK_AMD_gpu_shader_half_float",
		"VK_AMD_gpu_shader_int16",
		"VK_AMD_memory_overallocation_behavior",
		"VK_AMD_mixed_attachment_samples",
		"VK_AMD_negative_viewport_height",
		"VK_AMD_pipeline_compiler_control",
		"VK_AMD_rasterization_order",
		"VK_AMD_shader_ballot",
		"VK_AMD_shader_core_properties2",
		"VK_AMD_shader_core_properties",
		"VK_AMD_shader_early_and_late_fragment_tests",
		"VK_AMD_shader_explicit_vertex_parameter",
		"VK_AMD_shader_fragment_mask",
		"VK_AMD_shader_image_load_store_lod",
		"VK_AMD_shader_info",
		"VK_AMD_shader_trinary_minmax",
		"VK_AMD_texture_gather_bias_lod",
		"VK_NV_acquire_winrt_display",
		"VK_NV_clip_space_w_scaling",
		"VK_NV_compute_shader_derivatives",
		"VK_NV_cooperative_matrix",
		"VK_NV_corner_sampled_image",
		"VK_NV_coverage_reduction_mode",
		"VK_NV_dedicated_allocation",
		"VK_NV_dedicated_allocation_image_aliasing",
		"VK_NV_device_diagnostic_checkpoints",
		"VK_NV_device_diagnostics_config",
		"VK_NV_device_generated_commands",
		"VK_NV_external_memory",
		"VK_NV_external_memory_capabilities",
		"VK_NV_external_memory_rdma",
		"VK_NV_external_memory_win32",
		"VK_NV_fill_rectangle",
		"VK_NV_fragment_coverage_to_color",
		"VK_NV_fragment_shader_barycentric",
		"VK_NV_fragment_shading_rate_enums",
		"VK_NV_framebuffer_mixed_samples",
		"VK_NV_geometry_shader_passthrough",
		"VK_NV_glsl_shader",
		"VK_NV_inherited_viewport_scissor",
		"VK_NV_linear_color_attachment",
		"VK_NV_mesh_shader",
		"VK_NV_optical_flow",
		"VK_NV_present_barrier",
		"VK_NV_ray_tracing",
		"VK_NV_ray_tracing_motion_blur",
		"VK_NV_representative_fragment_test",
		"VK_NV_sample_mask_override_coverage",
		"VK_NV_scissor_exclusive",
		"VK_NV_shader_image_footprint",
		"VK_NV_shader_sm_builtins",
		"VK_NV_shader_subgroup_partitioned",
		"VK_NV_shading_rate_image",
		"VK_NV_viewport_array2",
		"VK_NV_viewport_swizzle",
		"VK_NV_win32_keyed_mutex",
		"VK_NVX_binary_import",
		"VK_NVX_image_view_handle",
		"VK_NVX_multiview_per_view_attributes",
		"VK_ANDROID_external_memory_android_hardware_buffer",
		"VK_ARM_rasterization_order_attachment_access",
		"VK_ARM_shader_core_builtins",
		"VK_FUCHSIA_buffer_collection",
		"VK_FUCHSIA_external_memory",
		"VK_FUCHSIA_external_semaphore",
		"VK_FUCHSIA_imagepipe_surface",
		"VK_GGP_frame_token",
		"VK_GGP_stream_descriptor_surface",
		"VK_GOOGLE_decorate_string",
		"VK_GOOGLE_display_timing",
		"VK_GOOGLE_hlsl_functionality1",
		"VK_GOOGLE_surfaceless_query",
		"VK_GOOGLE_user_type",
		"VK_HUAWEI_invocation_mask",
		"VK_HUAWEI_subpass_shading",
		"VK_IMG_filter_cubic",
		"VK_IMG_format_pvrtc",
		"VK_INTEL_performance_query",
		"VK_INTEL_shader_integer_functions2",
		"VK_MVK_ios_surface",
		"VK_MVK_macos_surface",
		"VK_NN_vi_surface",
		"VK_QCOM_fragment_density_map_offset",
		"VK_QCOM_image_processing",
		"VK_QCOM_render_pass_shader_resolve",
		"VK_QCOM_render_pass_store_ops",
		"VK_QCOM_render_pass_transform",
		"VK_QCOM_rotated_copy_commands",
		"VK_QCOM_tile_properties",
		"VK_QNX_screen_surface",
		"VK_SEC_amigo_profiling",
		"VK_VALVE_descriptor_set_host_mapping",
		"VK_VALVE_mutable_descriptor_type",
	};
	inline constexpr auto to_string(AkariVKExtensionFlags flags)->const char* {
		return AkariVKSupportedExtensionNames[static_cast<uint32_t>(flags)];
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
	template<AkariVKExtensionFlags flags>
	struct AkariVKExtensionTraits;
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_16bit_storage> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_16bit_storage;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_16bit_storage,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_16bit_storage,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_16bit_storage>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_8bit_storage> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_8bit_storage;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_8bit_storage,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_8bit_storage,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_8bit_storage>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_acceleration_structure> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_acceleration_structure;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
			AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
			AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
			AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
			AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_acceleration_structure>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_android_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_android_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_android_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_android_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_android_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_bind_memory2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_bind_memory2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_bind_memory2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_buffer_device_address> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_buffer_device_address;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_buffer_device_address>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_copy_commands2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_copy_commands2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_copy_commands2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_copy_commands2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_copy_commands2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_create_renderpass2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_create_renderpass2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_create_renderpass2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_dedicated_allocation> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_dedicated_allocation;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_dedicated_allocation>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_deferred_host_operations> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_deferred_host_operations;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_deferred_host_operations>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_descriptor_update_template> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_descriptor_update_template;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_descriptor_update_template,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_descriptor_update_template,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_descriptor_update_template>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_device_group> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_device_group;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_device_group,
			AkariVKExtensionFlags::eVK_KHR_device_group_creation,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_device_group,
			AkariVKExtensionFlags::eVK_KHR_device_group_creation,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_device_group>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_device_group_creation> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_device_group_creation;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_device_group_creation,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_device_group_creation,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_device_group_creation>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_display> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_display;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_display,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_display,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_display>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_display_swapchain> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_display_swapchain;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_display_swapchain,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_display,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_display_swapchain,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_display,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_display_swapchain>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_draw_indirect_count> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_draw_indirect_count;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_draw_indirect_count,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_draw_indirect_count,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_draw_indirect_count>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_driver_properties> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_driver_properties;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_driver_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_driver_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_driver_properties>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_dynamic_rendering> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_dynamic_rendering;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_dynamic_rendering,
			AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_dynamic_rendering,
			AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_dynamic_rendering>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_fence> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_fence;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_fence,
			AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_fence,
			AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_fence>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_fence_fd> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_fence_fd;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_fence_fd,
			AkariVKExtensionFlags::eVK_KHR_external_fence,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_fence_fd,
			AkariVKExtensionFlags::eVK_KHR_external_fence,
			AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_fence_fd>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_fence_win32> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_fence_win32;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_fence_win32,
			AkariVKExtensionFlags::eVK_KHR_external_fence,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_fence_win32,
			AkariVKExtensionFlags::eVK_KHR_external_fence,
			AkariVKExtensionFlags::eVK_KHR_external_fence_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_fence_win32>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_memory> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_memory;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_memory>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_memory_fd> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_memory_fd;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_memory_fd,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_memory_fd,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_memory_fd>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_memory_win32> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_memory_win32;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_memory_win32,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_memory_win32,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_memory_win32>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore_win32>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_semaphore;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_semaphore,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_semaphore,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_external_semaphore_fd>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_format_feature_flags2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_format_feature_flags2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_format_feature_flags2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_fragment_shader_barycentric>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_get_display_properties2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_get_display_properties2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_get_display_properties2,
			AkariVKExtensionFlags::eVK_KHR_display,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_get_display_properties2,
			AkariVKExtensionFlags::eVK_KHR_display,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_get_display_properties2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_global_priority> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_global_priority;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_global_priority,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_global_priority,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_global_priority>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_image_format_list> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_image_format_list;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_image_format_list,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_image_format_list,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_image_format_list>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
			AkariVKExtensionFlags::eVK_KHR_image_format_list,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
			AkariVKExtensionFlags::eVK_KHR_image_format_list,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_imageless_framebuffer>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_incremental_present> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_incremental_present;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_incremental_present,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_incremental_present,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_incremental_present>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_maintenance1> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_maintenance1;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_maintenance1>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_maintenance2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_maintenance2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_maintenance2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_maintenance3> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_maintenance3;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_maintenance3>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_maintenance4> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_maintenance4;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_maintenance4,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_maintenance4,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_maintenance4>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_multiview> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_multiview;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_multiview>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_performance_query> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_performance_query;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_performance_query,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_performance_query,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_performance_query>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_pipeline_executable_properties>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_pipeline_library> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_pipeline_library;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_pipeline_library,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_pipeline_library,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_pipeline_library>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_portability_enumeration> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_portability_enumeration;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_portability_enumeration,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_portability_enumeration,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_portability_enumeration>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_portability_subset> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_portability_subset;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_portability_subset,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_portability_subset,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_portability_subset>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_present_id> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_present_id;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_present_id,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_present_id,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_present_id>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_present_wait> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_present_wait;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_present_wait,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_present_id,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_present_wait,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_present_id,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_present_wait>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_push_descriptor> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_push_descriptor;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_push_descriptor,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_push_descriptor,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_push_descriptor>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_ray_query> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_ray_query;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_ray_query,
			AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_ray_query,
			AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
			AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
			AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_ray_query>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
			AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
			AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_maintenance1>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
			AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
			AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
			AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
			AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_relaxed_block_layout>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_sampler_mirror_clamp_to_edge>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_multiview,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_separate_depth_stencil_layouts>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_atomic_int64>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_clock> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_clock;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_clock,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_clock,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_clock>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_draw_parameters>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_float16_int8> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_float16_int8;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_float16_int8,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_float16_int8,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_float16_int8>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_float_controls> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_float_controls;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_float_controls>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_integer_dot_product>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_non_semantic_info>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_subgroup_extended_types>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_subgroup_uniform_control_flow>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shader_terminate_invocation>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_shared_presentable_image> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_shared_presentable_image;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shared_presentable_image,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_shared_presentable_image,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_shared_presentable_image>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_spirv_1_4> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_spirv_1_4;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
			AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
			AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_spirv_1_4>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_surface_protected_capabilities>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_swapchain> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_swapchain;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_swapchain>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
			AkariVKExtensionFlags::eVK_KHR_image_format_list,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
			AkariVKExtensionFlags::eVK_KHR_image_format_list,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_swapchain_mutable_format>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_synchronization2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_synchronization2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_synchronization2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_timeline_semaphore> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_timeline_semaphore;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_timeline_semaphore,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_timeline_semaphore,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_timeline_semaphore>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_uniform_buffer_standard_layout>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_variable_pointers> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_variable_pointers;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_variable_pointers,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_variable_pointers,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_storage_buffer_storage_class,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_variable_pointers>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_video_decode_queue> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_video_decode_queue;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_video_decode_queue>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_video_encode_queue> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_video_encode_queue;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_video_encode_queue>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_video_queue> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_video_queue;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_video_queue>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_vulkan_memory_model>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_wayland_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_wayland_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_wayland_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_wayland_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_wayland_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex,
			AkariVKExtensionFlags::eVK_KHR_external_memory_win32,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex,
			AkariVKExtensionFlags::eVK_KHR_external_memory_win32,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_win32_keyed_mutex>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_win32_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_win32_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_win32_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_win32_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_win32_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_workgroup_memory_explicit_layout>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_xcb_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_xcb_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_xcb_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_xcb_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_xcb_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_xlib_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_xlib_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_xlib_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_xlib_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_xlib_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_KHR_zero_initialize_workgroup_memory>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_4444_formats> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = true;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_4444_formats;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_4444_formats,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_4444_formats,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_4444_formats>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_acquire_drm_display> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_acquire_drm_display;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_acquire_drm_display,
			AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_acquire_drm_display,
			AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
			AkariVKExtensionFlags::eVK_KHR_display,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_acquire_drm_display>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display,
			AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display,
			AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
			AkariVKExtensionFlags::eVK_KHR_display,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_acquire_xlib_display>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_astc_decode_mode> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_astc_decode_mode;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_astc_decode_mode,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_astc_decode_mode,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_astc_decode_mode>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_attachment_feedback_loop_layout>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_blend_operation_advanced>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_border_color_swizzle> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_border_color_swizzle;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_border_color_swizzle,
			AkariVKExtensionFlags::eVK_EXT_custom_border_color,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_border_color_swizzle,
			AkariVKExtensionFlags::eVK_EXT_custom_border_color,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_border_color_swizzle>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_buffer_device_address> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_buffer_device_address;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_buffer_device_address,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_buffer_device_address,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_buffer_device_address>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_calibrated_timestamps>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_color_write_enable> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_color_write_enable;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_color_write_enable,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_color_write_enable,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_color_write_enable>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_conditional_rendering> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_conditional_rendering;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_conditional_rendering,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_conditional_rendering,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_conditional_rendering>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_conservative_rasterization> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_conservative_rasterization;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_conservative_rasterization,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_conservative_rasterization,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_conservative_rasterization>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_custom_border_color> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_custom_border_color;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_custom_border_color,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_custom_border_color,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_custom_border_color>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_debug_marker> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_debug_marker;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_debug_marker,
			AkariVKExtensionFlags::eVK_EXT_debug_report,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_debug_marker,
			AkariVKExtensionFlags::eVK_EXT_debug_report,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_debug_marker>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_debug_report> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_debug_report;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_debug_report,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_debug_report,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_debug_report>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_debug_utils> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_debug_utils;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_debug_utils,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_debug_utils,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_debug_utils>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_depth_clamp_zero_one>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_depth_clip_control> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_depth_clip_control;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_depth_clip_control,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_depth_clip_control,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_depth_clip_control>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_depth_clip_enable> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_depth_clip_enable;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_depth_clip_enable,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_depth_clip_enable,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_depth_clip_enable>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_depth_range_unrestricted>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_descriptor_indexing> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_descriptor_indexing;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_descriptor_indexing>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_device_address_binding_report> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_device_address_binding_report;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_device_address_binding_report,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_EXT_debug_utils,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_device_address_binding_report,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_EXT_debug_utils,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_device_address_binding_report>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_device_fault> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_device_fault;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_device_fault,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_device_fault,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_device_fault>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_device_memory_report> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_device_memory_report;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_device_memory_report,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_device_memory_report,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_device_memory_report>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_direct_mode_display> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_direct_mode_display;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
			AkariVKExtensionFlags::eVK_KHR_display,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
			AkariVKExtensionFlags::eVK_KHR_display,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_direct_mode_display>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_directfb_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_directfb_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_directfb_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_directfb_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_directfb_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_discard_rectangles> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_discard_rectangles;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_discard_rectangles,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_discard_rectangles,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_discard_rectangles>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_display_control> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_display_control;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_display_control,
			AkariVKExtensionFlags::eVK_EXT_display_surface_counter,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_display_control,
			AkariVKExtensionFlags::eVK_EXT_display_surface_counter,
			AkariVKExtensionFlags::eVK_KHR_display,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_display_control>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_display_surface_counter> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_display_surface_counter;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_display_surface_counter,
			AkariVKExtensionFlags::eVK_KHR_display,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_display_surface_counter,
			AkariVKExtensionFlags::eVK_KHR_display,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_display_surface_counter>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_extended_dynamic_state3>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf,
			AkariVKExtensionFlags::eVK_KHR_external_memory_fd,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf,
			AkariVKExtensionFlags::eVK_KHR_external_memory_fd,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_external_memory_dma_buf>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_external_memory_host> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_external_memory_host;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_external_memory_host,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_external_memory_host,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_external_memory_host>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_filter_cubic> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_filter_cubic;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_filter_cubic,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_filter_cubic,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_filter_cubic>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_fragment_density_map2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_fragment_density_map2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_fragment_density_map2,
			AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_fragment_density_map2,
			AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_fragment_density_map2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_fragment_density_map> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_fragment_density_map;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_fragment_density_map>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_fragment_shader_interlock>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_full_screen_exclusive>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_global_priority_query> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_global_priority_query;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_global_priority_query,
			AkariVKExtensionFlags::eVK_EXT_global_priority,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_global_priority_query,
			AkariVKExtensionFlags::eVK_EXT_global_priority,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_global_priority_query>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_global_priority> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_global_priority;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_global_priority,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_global_priority,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_global_priority>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_pipeline_library,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_pipeline_library,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_graphics_pipeline_library>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_hdr_metadata> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_hdr_metadata;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_hdr_metadata,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_hdr_metadata,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_hdr_metadata>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_headless_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_headless_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_headless_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_headless_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_headless_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_host_query_reset> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_host_query_reset;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_host_query_reset,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_host_query_reset,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_host_query_reset>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_2d_view_of_3d>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_image_compression_control> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_image_compression_control;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_compression_control,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_compression_control,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_compression_control>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain,
			AkariVKExtensionFlags::eVK_EXT_image_compression_control,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain,
			AkariVKExtensionFlags::eVK_EXT_image_compression_control,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_compression_control_swapchain>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier,
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_image_format_list,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier,
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
			AkariVKExtensionFlags::eVK_KHR_image_format_list,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_drm_format_modifier>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_image_robustness> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_image_robustness;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_robustness,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_robustness,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_robustness>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_image_view_min_lod> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_image_view_min_lod;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_view_min_lod,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_image_view_min_lod,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_image_view_min_lod>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_index_type_uint8> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_index_type_uint8;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_index_type_uint8,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_index_type_uint8,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_index_type_uint8>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_inline_uniform_block> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_inline_uniform_block;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_inline_uniform_block,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_inline_uniform_block,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_inline_uniform_block>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_legacy_dithering> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_legacy_dithering;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_legacy_dithering,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_legacy_dithering,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_legacy_dithering>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_line_rasterization> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_line_rasterization;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_line_rasterization,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_line_rasterization,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_line_rasterization>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_load_store_op_none> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_load_store_op_none;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_load_store_op_none,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_load_store_op_none,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_load_store_op_none>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_memory_budget> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_memory_budget;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_memory_budget,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_memory_budget,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_memory_budget>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_memory_priority> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_memory_priority;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_memory_priority,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_memory_priority,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_memory_priority>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_mesh_shader> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_mesh_shader;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_mesh_shader,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_mesh_shader,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_spirv_1_4,
			AkariVKExtensionFlags::eVK_KHR_shader_float_controls,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_mesh_shader>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_metal_objects> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_metal_objects;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_metal_objects,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_metal_objects,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_metal_objects>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_metal_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_metal_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_metal_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_metal_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_metal_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_multi_draw> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_multi_draw;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_multi_draw,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_multi_draw,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_multi_draw>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_depth_stencil_resolve,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_multisampled_render_to_single_sampled>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_mutable_descriptor_type>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_non_seamless_cube_map>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_opacity_micromap> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_opacity_micromap;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_opacity_micromap,
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_opacity_micromap,
			AkariVKExtensionFlags::eVK_KHR_acceleration_structure,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
			AkariVKExtensionFlags::eVK_EXT_descriptor_indexing,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
			AkariVKExtensionFlags::eVK_KHR_deferred_host_operations,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_opacity_micromap>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory,
			AkariVKExtensionFlags::eVK_EXT_memory_priority,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory,
			AkariVKExtensionFlags::eVK_EXT_memory_priority,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pageable_device_local_memory>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_pci_bus_info> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_pci_bus_info;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pci_bus_info,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pci_bus_info,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pci_bus_info>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_physical_device_drm> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_physical_device_drm;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_physical_device_drm,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_physical_device_drm,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_physical_device_drm>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_creation_feedback>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_properties> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_pipeline_properties;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_properties>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_protected_access>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_robustness> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_pipeline_robustness;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_robustness,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_pipeline_robustness,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_pipeline_robustness>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_post_depth_coverage> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_post_depth_coverage;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_post_depth_coverage,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_post_depth_coverage,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_post_depth_coverage>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_primitive_topology_list_restart>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_primitives_generated_query> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_primitives_generated_query;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_primitives_generated_query,
			AkariVKExtensionFlags::eVK_EXT_transform_feedback,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_primitives_generated_query,
			AkariVKExtensionFlags::eVK_EXT_transform_feedback,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_primitives_generated_query>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_private_data> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_private_data;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_private_data,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_private_data,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_private_data>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_provoking_vertex> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_provoking_vertex;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_provoking_vertex,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_provoking_vertex,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_provoking_vertex>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_queue_family_foreign> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_queue_family_foreign;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_queue_family_foreign,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_queue_family_foreign,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_queue_family_foreign>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_rasterization_order_attachment_access>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_rgba10x6_formats>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_robustness2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_robustness2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_robustness2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_robustness2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_robustness2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_sample_locations> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_sample_locations;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_sample_locations,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_sample_locations,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_sample_locations>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_sampler_filter_minmax>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_scalar_block_layout> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_scalar_block_layout;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_scalar_block_layout,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_scalar_block_layout,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_scalar_block_layout>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_separate_stencil_usage>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2,
			AkariVKExtensionFlags::eVK_EXT_shader_atomic_float,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2,
			AkariVKExtensionFlags::eVK_EXT_shader_atomic_float,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_atomic_float2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_shader_atomic_float> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_shader_atomic_float;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_atomic_float,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_atomic_float,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_atomic_float>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_demote_to_helper_invocation>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_image_atomic_int64>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_shader_module_identifier> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_shader_module_identifier;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_module_identifier,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_module_identifier,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_EXT_pipeline_creation_cache_control,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_module_identifier>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_shader_stencil_export> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_shader_stencil_export;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_stencil_export,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_stencil_export,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_stencil_export>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_subgroup_ballot>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_subgroup_vote>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_shader_viewport_index_layer>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_subgroup_size_control> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_subgroup_size_control;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_subgroup_size_control,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_subgroup_size_control,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_subgroup_size_control>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_subpass_merge_feedback>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_swapchain_colorspace>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_texel_buffer_alignment>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_texture_compression_astc_hdr>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_tooling_info> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_tooling_info;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_tooling_info,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_tooling_info,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_tooling_info>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_transform_feedback> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_transform_feedback;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_transform_feedback,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_transform_feedback,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_transform_feedback>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_validation_cache> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_validation_cache;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_validation_cache,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_validation_cache,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_validation_cache>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_validation_features> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_validation_features;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_validation_features,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_validation_features,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_validation_features>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_validation_flags> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_validation_flags;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_validation_flags,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_validation_flags,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_validation_flags>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_vertex_attribute_divisor>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_vertex_input_dynamic_state>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_video_decode_h264> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_video_decode_h264;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_video_decode_h264,
			AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_video_decode_h264,
			AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_video_decode_h264>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_video_decode_h265> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_video_decode_h265;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_video_decode_h265,
			AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_video_decode_h265,
			AkariVKExtensionFlags::eVK_KHR_video_decode_queue,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_video_decode_h265>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_video_encode_h264> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_video_encode_h264;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_video_encode_h264,
			AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_video_encode_h264,
			AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_video_encode_h264>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_video_encode_h265> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_video_encode_h265;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_video_encode_h265,
			AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_video_encode_h265,
			AkariVKExtensionFlags::eVK_KHR_video_encode_queue,
			AkariVKExtensionFlags::eVK_KHR_video_queue,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_video_encode_h265>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;
		static inline bool is_partially_promoted = true;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_ycbcr_2plane_444_formats>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_EXT_ycbcr_image_arrays>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_buffer_marker> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_buffer_marker;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_buffer_marker,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_buffer_marker,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_buffer_marker>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_device_coherent_memory> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_device_coherent_memory;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_device_coherent_memory,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_device_coherent_memory,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_device_coherent_memory>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_display_native_hdr> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_display_native_hdr;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_display_native_hdr,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_display_native_hdr,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_display_native_hdr>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_draw_indirect_count> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_draw_indirect_count;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_draw_indirect_count,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_draw_indirect_count,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_draw_indirect_count>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_gcn_shader> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_gcn_shader;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_gcn_shader,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_gcn_shader,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_gcn_shader>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_gpu_shader_half_float>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_gpu_shader_int16>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_memory_overallocation_behavior>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_mixed_attachment_samples>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_negative_viewport_height> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_negative_viewport_height;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_negative_viewport_height,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_negative_viewport_height,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_negative_viewport_height>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_pipeline_compiler_control>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_rasterization_order> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_rasterization_order;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_rasterization_order,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_rasterization_order,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_rasterization_order>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_shader_ballot> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_shader_ballot;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_ballot,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_ballot,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_ballot>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_shader_core_properties2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_shader_core_properties2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_core_properties2,
			AkariVKExtensionFlags::eVK_AMD_shader_core_properties,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_core_properties2,
			AkariVKExtensionFlags::eVK_AMD_shader_core_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_core_properties2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_shader_core_properties> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_shader_core_properties;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_core_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_core_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_core_properties>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_early_and_late_fragment_tests>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_explicit_vertex_parameter>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_fragment_mask>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_image_load_store_lod>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_shader_info> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_shader_info;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_info,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_info,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_info>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_shader_trinary_minmax>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_AMD_texture_gather_bias_lod>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_acquire_winrt_display> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_acquire_winrt_display;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_acquire_winrt_display,
			AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_acquire_winrt_display,
			AkariVKExtensionFlags::eVK_EXT_direct_mode_display,
			AkariVKExtensionFlags::eVK_KHR_display,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_acquire_winrt_display>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_clip_space_w_scaling>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_compute_shader_derivatives>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_cooperative_matrix> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_cooperative_matrix;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_cooperative_matrix,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_cooperative_matrix,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_cooperative_matrix>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_corner_sampled_image> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_corner_sampled_image;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_corner_sampled_image,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_corner_sampled_image,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_corner_sampled_image>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode,
			AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode,
			AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_coverage_reduction_mode>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_dedicated_allocation> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_dedicated_allocation;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_dedicated_allocation,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_dedicated_allocation,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_dedicated_allocation>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing,
			AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing,
			AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_dedicated_allocation_image_aliasing>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_device_diagnostic_checkpoints>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_device_diagnostics_config> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_device_diagnostics_config;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_device_diagnostics_config,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_device_diagnostics_config,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_device_diagnostics_config>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_device_generated_commands> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_device_generated_commands;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_device_generated_commands,
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_device_generated_commands,
			AkariVKExtensionFlags::eVK_KHR_buffer_device_address,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_device_generated_commands>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_external_memory> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_external_memory;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_external_memory,
			AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_external_memory,
			AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_external_memory>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_external_memory_capabilities> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_external_memory_capabilities;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_external_memory_capabilities>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_external_memory_rdma> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_external_memory_rdma;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_external_memory_rdma,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_external_memory_rdma,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_external_memory_rdma>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_external_memory_win32> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_external_memory_win32;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_external_memory_win32,
			AkariVKExtensionFlags::eVK_NV_external_memory,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_external_memory_win32,
			AkariVKExtensionFlags::eVK_NV_external_memory,
			AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_external_memory_win32>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_fill_rectangle> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_fill_rectangle;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_fill_rectangle,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_fill_rectangle,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_fill_rectangle>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_fragment_coverage_to_color>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_fragment_shader_barycentric>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums,
			AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums,
			AkariVKExtensionFlags::eVK_KHR_fragment_shading_rate,
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_fragment_shading_rate_enums>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_framebuffer_mixed_samples>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_geometry_shader_passthrough>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_glsl_shader> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_glsl_shader;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_glsl_shader,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_glsl_shader,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_glsl_shader>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_inherited_viewport_scissor>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_linear_color_attachment> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_linear_color_attachment;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_linear_color_attachment,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_linear_color_attachment,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_linear_color_attachment>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_mesh_shader> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_mesh_shader;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_mesh_shader,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_mesh_shader,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_mesh_shader>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_optical_flow> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_optical_flow;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_optical_flow,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_optical_flow,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_optical_flow>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_present_barrier> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_present_barrier;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_present_barrier,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_present_barrier,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_KHR_get_surface_capabilities2,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_present_barrier>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_ray_tracing> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_ray_tracing;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_ray_tracing,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_ray_tracing,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_ray_tracing>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur,
			AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
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
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_ray_tracing_motion_blur>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_representative_fragment_test> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_representative_fragment_test;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_representative_fragment_test,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_representative_fragment_test,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_representative_fragment_test>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_sample_mask_override_coverage>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_scissor_exclusive> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_scissor_exclusive;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_scissor_exclusive,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_scissor_exclusive,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_scissor_exclusive>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_shader_image_footprint> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_shader_image_footprint;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_shader_image_footprint,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_shader_image_footprint,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_shader_image_footprint>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_shader_sm_builtins> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_shader_sm_builtins;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_shader_sm_builtins,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_shader_sm_builtins,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_shader_sm_builtins>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_shader_subgroup_partitioned>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_shading_rate_image> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_shading_rate_image;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_shading_rate_image,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_shading_rate_image,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_shading_rate_image>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_viewport_array2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_viewport_array2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_viewport_array2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_viewport_array2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_viewport_array2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_viewport_swizzle> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_viewport_swizzle;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_viewport_swizzle,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_viewport_swizzle,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_viewport_swizzle>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex,
			AkariVKExtensionFlags::eVK_NV_external_memory_win32,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex,
			AkariVKExtensionFlags::eVK_NV_external_memory_win32,
			AkariVKExtensionFlags::eVK_NV_external_memory,
			AkariVKExtensionFlags::eVK_NV_external_memory_capabilities,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NV_win32_keyed_mutex>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NVX_binary_import> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NVX_binary_import;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NVX_binary_import,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NVX_binary_import,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NVX_binary_import>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NVX_image_view_handle> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NVX_image_view_handle;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NVX_image_view_handle,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NVX_image_view_handle,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NVX_image_view_handle>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes,
			AkariVKExtensionFlags::eVK_KHR_multiview,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes,
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NVX_multiview_per_view_attributes>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_EXT_queue_family_foreign,
			AkariVKExtensionFlags::eVK_KHR_dedicated_allocation,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
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
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_ANDROID_external_memory_android_hardware_buffer>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_ARM_rasterization_order_attachment_access>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_ARM_shader_core_builtins> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_ARM_shader_core_builtins;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_ARM_shader_core_builtins,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_ARM_shader_core_builtins,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_ARM_shader_core_builtins>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection,
			AkariVKExtensionFlags::eVK_FUCHSIA_external_memory,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection,
			AkariVKExtensionFlags::eVK_FUCHSIA_external_memory,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_get_memory_requirements2,
			AkariVKExtensionFlags::eVK_KHR_bind_memory2,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_maintenance1,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
			AkariVKExtensionFlags::eVK_KHR_sampler_ycbcr_conversion,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_FUCHSIA_buffer_collection>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_FUCHSIA_external_memory> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_FUCHSIA_external_memory;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_FUCHSIA_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_FUCHSIA_external_memory,
			AkariVKExtensionFlags::eVK_KHR_external_memory_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_external_memory,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_FUCHSIA_external_memory>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore_capabilities,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_external_semaphore,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_FUCHSIA_external_semaphore>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_FUCHSIA_imagepipe_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_GGP_frame_token> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_GGP_frame_token;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GGP_frame_token,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GGP_frame_token,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
			AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GGP_frame_token>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GGP_stream_descriptor_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_GOOGLE_decorate_string> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_GOOGLE_decorate_string;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_decorate_string,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_decorate_string,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_decorate_string>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_GOOGLE_display_timing> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_GOOGLE_display_timing;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_display_timing,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_display_timing,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_display_timing>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_hlsl_functionality1>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_surfaceless_query>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_GOOGLE_user_type> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_GOOGLE_user_type;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_user_type,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_GOOGLE_user_type,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_GOOGLE_user_type>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask,
			AkariVKExtensionFlags::eVK_KHR_ray_tracing_pipeline,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
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
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_HUAWEI_invocation_mask>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading,
			AkariVKExtensionFlags::eVK_KHR_create_renderpass2,
			AkariVKExtensionFlags::eVK_KHR_multiview,
			AkariVKExtensionFlags::eVK_KHR_maintenance2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_KHR_synchronization2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_HUAWEI_subpass_shading>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_IMG_filter_cubic> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_IMG_filter_cubic;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_IMG_filter_cubic,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_IMG_filter_cubic,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_IMG_filter_cubic>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_IMG_format_pvrtc> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_IMG_format_pvrtc;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_IMG_format_pvrtc,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_IMG_format_pvrtc,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_IMG_format_pvrtc>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_INTEL_performance_query> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_INTEL_performance_query;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_INTEL_performance_query,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_INTEL_performance_query,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_INTEL_performance_query>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_INTEL_shader_integer_functions2>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_MVK_ios_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_MVK_ios_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_MVK_ios_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_MVK_ios_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_MVK_ios_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_MVK_macos_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_MVK_macos_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_MVK_macos_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_MVK_macos_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_MVK_macos_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_NN_vi_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_NN_vi_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NN_vi_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_NN_vi_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_NN_vi_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
			AkariVKExtensionFlags::eVK_EXT_fragment_density_map,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_fragment_density_map_offset>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_QCOM_image_processing> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_QCOM_image_processing;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_image_processing,
			AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_image_processing,
			AkariVKExtensionFlags::eVK_KHR_format_feature_flags2,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_image_processing>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_render_pass_shader_resolve>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_render_pass_store_ops>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_QCOM_render_pass_transform> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_QCOM_render_pass_transform;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_render_pass_transform,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_render_pass_transform,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_render_pass_transform>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_copy_commands2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands,
			AkariVKExtensionFlags::eVK_KHR_swapchain,
			AkariVKExtensionFlags::eVK_KHR_copy_commands2,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_rotated_copy_commands>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_QCOM_tile_properties> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_QCOM_tile_properties;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_tile_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QCOM_tile_properties,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QCOM_tile_properties>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_QNX_screen_surface> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eInstance;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_QNX_screen_surface;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QNX_screen_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_QNX_screen_surface,
			AkariVKExtensionFlags::eVK_KHR_surface,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_QNX_screen_surface>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_SEC_amigo_profiling> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_SEC_amigo_profiling;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_SEC_amigo_profiling,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_SEC_amigo_profiling,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_SEC_amigo_profiling>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_VALVE_descriptor_set_host_mapping>::type;
	};
	template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type> {
		static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::eDevice;
		static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;
		static inline constexpr uint32_t promoted_core_version = UINT32_MAX;
		static inline bool is_partially_promoted = false;
		static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type;
		static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {
			AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
		};
		static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {
			AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type,
			AkariVKExtensionFlags::eVK_KHR_maintenance3,
			AkariVKExtensionFlags::eVK_KHR_get_physical_device_properties2,
		};
		using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::eVK_VALVE_mutable_descriptor_type>::type;
	};

}
AKARI_GRAPHICS_VULKAN_CORE_NAMESPACE_END
#endif