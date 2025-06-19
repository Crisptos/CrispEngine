#pragma once

namespace Crisp
{
	// Forward Declarations
	struct RendererSettings;
	struct FrameData;

	class RendererBackend
	{
	public:
		virtual void InitializeRendererBackendAPI(const RendererSettings& renderer_init_settings) = 0;
		virtual void ShutdownRendererBackendAPI() = 0;

		virtual void BeginFrame() = 0;
		virtual void Submit(const FrameData& frame_data) = 0;
		virtual void EndFrame() = 0;

	};
}