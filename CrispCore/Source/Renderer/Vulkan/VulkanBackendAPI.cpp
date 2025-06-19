#include "Renderer/Vulkan/VulkanIncludes.h"
#include "Renderer/Vulkan/VulkanBackendAPI.h"

#include "Core/Logger.h"

namespace Crisp
{
	void VulkanBackend::InitializeRendererBackendAPI(const RendererSettings& renderer_init_settings)
	{
		vkb::InstanceBuilder inst_builder;

		auto built_inst = inst_builder.set_app_name("Crisp Engine")
			.request_validation_layers(true)
			.use_default_debug_messenger()
			.require_api_version(1, 4, 0)
			.build();

		vkb::Instance vkb_inst = built_inst.value();
		m_Instance = vkb_inst.instance;
		m_DebugMessenger = vkb_inst.debug_messenger;
		CRISP_LOG_INFO("Created VkInstance and DebugMessenger");

	}

	void VulkanBackend::ShutdownRendererBackendAPI()
	{
		CRISP_LOG_INFO("Shutting down VkInstance and DebugMessenger");
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