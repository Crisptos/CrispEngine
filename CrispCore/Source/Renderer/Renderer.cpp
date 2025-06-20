#include "Renderer/Renderer.h"
#include "Core/Logger.h"

// Include backend API headers here so it doesn't leak into the engine API
#include "Renderer/Vulkan/VulkanBackendAPI.h"

namespace Crisp
{
	bool Renderer::InitializeRenderer(const RendererSettings& renderer_init_settings)
	{
		// Create API specific backend
		switch (renderer_init_settings.context.api)
		{

			case BackendAPI::VULKAN:
			{
				CRISP_LOG_INFO("Initializing renderer with detected backend: Vulkan");
				renderer_backend = new VulkanBackend;
				break;
			}

			default:
			{
				// TODO Error Here
				break;
			}
		}

		return renderer_backend->InitializeRendererBackendAPI(renderer_init_settings);
	}

	void Renderer::ShutdownRenderer()
	{
		renderer_backend->ShutdownRendererBackendAPI();
	}

	void Renderer::BeginFrame()
	{

	}

	void Renderer::Submit(const FrameData& frame_data)
	{

	}

	void Renderer::EndFrame()
	{

	}

}