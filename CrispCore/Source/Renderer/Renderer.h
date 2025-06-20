#pragma once
#include <stdint.h>
#include "Renderer/RendererBackend.h"
#include "Renderer/RenderTypes.h"

namespace Crisp
{
	class Renderer
	{

	public:
		bool InitializeRenderer(const RendererSettings& renderer_init_settings);
		void ShutdownRenderer();

		void BeginFrame();
		void Submit(const FrameData& frame_data);
		void EndFrame();

	protected:
		RendererBackend* renderer_backend;

	};
}