#pragma once

namespace Crisp
{
	enum BackendAPI
	{
		VULKAN = 0x01
	};

	class RendererBackend
	{
	public:
		virtual void InitializeRendererBackendAPI() = 0;
		virtual void ShutdownRendererBackendAPI() = 0;

	};
}