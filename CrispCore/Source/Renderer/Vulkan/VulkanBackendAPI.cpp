#include "Renderer/Vulkan/VulkanBackendIncludes.h"
#include "Renderer/Vulkan/VulkanBackendAPI.h"
#include "Renderer/RenderTypes.h"
#include "Core/Logger.h"

namespace Crisp
{
	bool VulkanBackend::InitializeRendererBackendAPI(const RendererSettings& renderer_init_settings)
	{
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



		return true;
	}

	void VulkanBackend::ShutdownRendererBackendAPI()
	{
		CRISP_LOG_INFO("Shutting down Vulkan Backend");
		vkDestroySurfaceKHR(m_Instance, m_Surface, nullptr);
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