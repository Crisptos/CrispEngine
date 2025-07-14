#pragma once

namespace Crisp
{
	// Forward Declarations
	struct RendererSettings;
	struct FrameData;

	class RendererBackend
	{
	public:
		virtual bool InitializeRendererBackendAPI(const RendererSettings& renderer_init_settings) = 0;
		virtual void ShutdownRendererBackendAPI() = 0;

		/*
			Begin Frame -
				Grab the next swapchain image
				Clear command buffers
				Track frame and or swap chain image index


		*/
		virtual void BeginFrame() = 0;
		virtual void Submit(const FrameData& frame_data) = 0;
		virtual void EndFrame() = 0;

	};
}