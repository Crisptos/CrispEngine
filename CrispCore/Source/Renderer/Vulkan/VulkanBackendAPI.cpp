#include "Renderer/Vulkan/VulkanBackendIncludes.h"
#include "Renderer/Vulkan/VulkanBackendAPI.h"
#include "Renderer/RenderTypes.h"
#include "Core/Logger.h"

// TODO - for testing
#include "Renderer/Vulkan/VulkanRenderPass.h"

namespace Crisp
{
	// Vulkan functions only in this module
	
	/*
		Vulkan Initialization Steps

		1. Create Instance and DebugMsger
		2. Query for Physical Device
		3. Create Logical Device from Physical Device
		4. Create Swapchain and Images
	
	*/

	bool VulkanBackend::InitializeRendererBackendAPI(const RendererSettings& renderer_init_settings)
	{

		// Step 1 ___
		vkb::InstanceBuilder inst_builder;

		auto built_inst = inst_builder.set_app_name("Test")
			.set_engine_name("Crisp Engine")
			.set_debug_callback([](
					VkDebugUtilsMessageSeverityFlagBitsEXT		messageSeverity,
					VkDebugUtilsMessageTypeFlagsEXT				messageType,
					const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
					void*										pUserData
				) -> VkBool32 {
					if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT)
					{
						const char* type = vkb::to_string_message_type(messageType);
						
						switch (messageSeverity)
						{
							case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
							{
								CRISP_LOG_TRACE("Vulkan Debug {0} {1}", type, pCallbackData->pMessage);
								break;
							}

							case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
							{
								CRISP_LOG_INFO("Vulkan Debug {0} {1}", type, pCallbackData->pMessage);
								break;
							}

							case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
							{
								CRISP_LOG_WARN("Vulkan Debug {0} {1}", type, pCallbackData->pMessage);
								break;
							}

							case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
							{
								CRISP_LOG_ERROR("Vulkan Debug {0} {1}", type, pCallbackData->pMessage);
								break;
							}
						}

						return VK_TRUE;
					}
				})
			.request_validation_layers(true)
			.require_api_version(1, 4, 0)
			.build();

		if (!built_inst)
		{
			CRISP_LOG_CRITICAL("Failed to create VkInstance and VkDebugMessenger");
			return false;
		}

		vkb::Instance vkb_inst = built_inst.value();
		m_Instance = vkb_inst.instance;
		m_DebugMessenger = vkb_inst.debug_messenger;
		CRISP_LOG_INFO("Created VkInstance and DebugMessenger");

		SDL_Vulkan_CreateSurface(renderer_init_settings.window_handle, m_Instance, nullptr, &m_Surface);

		if (!m_Surface)
		{
			CRISP_LOG_CRITICAL("Failed to create VkSurfaceKHR");
			return false;
		}

		CRISP_LOG_INFO("Created VkSurface");

		// Step 2 ___
		VkPhysicalDeviceVulkan13Features features13 = {};
		features13.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
		features13.dynamicRendering = true;
		features13.synchronization2 = true;

		VkPhysicalDeviceVulkan12Features features12 = {};
		features12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
		features12.bufferDeviceAddress = true;
		features12.descriptorIndexing = true;

		vkb::PhysicalDeviceSelector selector(vkb_inst);
		auto built_physical_device = selector
			.set_minimum_version(1, 4)
			.set_required_features_13(features13)
			.set_required_features_12(features12)
			.set_surface(m_Surface)
			.select();

		if(!built_physical_device)
		{
			CRISP_LOG_CRITICAL("Failed to select suitable physical device");
			return false;
		}

		vkb::PhysicalDevice physical_device = built_physical_device.value();
		const char* selected_gpu_name = physical_device.name.c_str();

		CRISP_LOG_INFO("Selected device: {0}", selected_gpu_name);

		// Step 3 ___
		vkb::DeviceBuilder logical_device_builder(physical_device);
		auto built_logical_device = logical_device_builder.build();

		if (!built_logical_device)
		{
			CRISP_LOG_CRITICAL("Failed to build logical device from selected: {0}", selected_gpu_name);
			return false;
		}

		vkb::Device logical_device = built_logical_device.value();

		CRISP_LOG_INFO("Created logical device");

		m_Device.logical = logical_device.device;
		m_Device.physical = physical_device.physical_device;

		// Step 4 ___
		vkb::SwapchainBuilder swapchain_builder(m_Device.physical, m_Device.logical, m_Surface);
		m_Swapchain.image_format = VK_FORMAT_B8G8R8A8_UNORM;

		VkSurfaceFormatKHR desired_format = {static_cast<VkFormat>(m_Swapchain.image_format), VK_COLOR_SPACE_SRGB_NONLINEAR_KHR};
		auto built_swapchain = swapchain_builder
			.set_desired_format(desired_format)
			.set_desired_present_mode(VK_PRESENT_MODE_FIFO_KHR) // TODO Hardcoded VSync present
			.set_desired_extent(renderer_init_settings.w, renderer_init_settings.h)
			.add_image_usage_flags(VK_IMAGE_USAGE_TRANSFER_DST_BIT)
			.build();

		if (!built_swapchain)
		{
			CRISP_LOG_CRITICAL("Failed to create swapchain with desired settings");
			return false;
		}
		vkb::Swapchain swapchain = built_swapchain.value();
		//		grab handle, extent dimensions and images
		m_Swapchain.ext_w = swapchain.extent.width;
		m_Swapchain.ext_h = swapchain.extent.height;

		m_Swapchain.handle = swapchain.swapchain;

		std::vector<VkImage> images = swapchain.get_images().value();
		std::vector<VkImageView> image_views = swapchain.get_image_views().value();

		for (int i = 0; i < images.size(); i++)
		{
			m_Swapchain.images[i] = images[i];
			m_Swapchain.image_views[i] = image_views[i];
			m_Swapchain.image_count++;
		}

		CRISP_LOG_INFO("Created Swapchain with desired formats, {0} images and {1}x{2}", m_Swapchain.image_count, m_Swapchain.ext_w, m_Swapchain.ext_h);

		return true;
	}

	void VulkanBackend::ShutdownRendererBackendAPI()
	{
		CRISP_LOG_INFO("Shutting down Vulkan Backend");
		vkDestroySwapchainKHR(m_Device.logical, m_Swapchain.handle, nullptr);
		for (int i = 0; i < m_Swapchain.image_count; i++)
		{
			vkDestroyImageView(m_Device.logical, m_Swapchain.image_views[i], nullptr);
		}
		m_Swapchain.image_count = 0;

		vkDestroySurfaceKHR(m_Instance, m_Surface, nullptr);
		vkDestroyDevice(m_Device.logical, nullptr);

		vkb::destroy_debug_utils_messenger(m_Instance, m_DebugMessenger);
		vkDestroyInstance(m_Instance, nullptr);
	}

	void VulkanBackend::BeginFrame()
	{

	}

	void VulkanBackend::Submit(const FrameData& frame_data)
	{

	}

	void VulkanBackend::EndFrame()
	{

	}
}