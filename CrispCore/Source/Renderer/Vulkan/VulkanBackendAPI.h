#pragma once
#include "Renderer/RendererBackend.h"

namespace Crisp
{
	// Forward Declarations
	//		Vulkan specific types
	typedef struct VkInstance_T* VkInstance;
	typedef struct VkDebugUtilsMessengerEXT_T* VkDebugUtilsMessengerEXT;
	typedef struct VkSurfaceKHR_T* VkSurfaceKHR;

	//		Crisp Engine types
	struct RendererSettings;
	struct FrameData;

	class VulkanBackend : public RendererBackend
	{
	public:
		bool InitializeRendererBackendAPI(const RendererSettings& renderer_init_settings) override;
		void ShutdownRendererBackendAPI() override;

		void BeginFrame() override;
		void Submit(const FrameData& frame_data) override;
		void EndFrame() override;

	protected:
		VkInstance m_Instance = nullptr;
		VkDebugUtilsMessengerEXT m_DebugMessenger = nullptr;
		VkSurfaceKHR m_Surface = nullptr;

	};
}