#pragma once
#include "Renderer/RendererBackend.h"

namespace Crisp
{

	class VulkanBackend : public RendererBackend
	{
	public:
		void InitializeRendererBackendAPI() override;
		void ShutdownRendererBackendAPI() override;

	};
}