#pragma once
#include "Renderer/RendererBackend.h"

namespace Crisp
{
	// Forward Declarations
	//		Vulkan specific types
	typedef struct VkInstance_T* VkInstance;
	typedef struct VkDebugUtilsMessengerEXT_T* VkDebugUtilsMessengerEXT;
	//__
	typedef struct VkSurfaceKHR_T* VkSurfaceKHR;
	typedef struct VkDevice_T* VkDevice;
	typedef struct VkPhysicalDevice_T* VkPhysicalDevice;
	//__
	typedef struct VkSwapchainKHR_T* VkSwapchainKHR;
	typedef struct VkImage_T* VkImage;
	typedef struct VkImageView_T* VkImageView;
	

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
		//__
		VkSurfaceKHR m_Surface = nullptr;
		struct RendererDevice
		{
			VkDevice logical = nullptr;
			VkPhysicalDevice physical = nullptr;
		} m_Device;
		//__
		// TODO Rearrange this
		struct Swapchain
		{
			VkSwapchainKHR handle;
			VkImage images[3];
			VkImageView image_views[3];
			uint32_t ext_w;
			uint32_t ext_h;
			uint32_t image_format;
			uint32_t image_count = 0;
			uint8_t max_frames_in_flight;
		} m_Swapchain;
	};
}