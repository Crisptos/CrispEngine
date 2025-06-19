#pragma once
#include "Renderer/RendererBackend.h"

namespace Crisp
{
	// Forward Declarations
	typedef struct VkInstance_T* VkInstance;
	typedef struct VkDebugUtilsMessengerEXT_T* VkDebugUtilsMessengerEXT;

	class VulkanBackend : public RendererBackend
	{
	public:
		void InitializeRendererBackendAPI(const RendererSettings& renderer_init_settings) override;
		void ShutdownRendererBackendAPI() override;

		void BeginFrame() override;
		void Submit(const FrameData& frame_data) override;
		void EndFrame() override;

	protected:
		VkInstance m_Instance = nullptr;
		VkDebugUtilsMessengerEXT m_DebugMessenger = nullptr;

	};
}