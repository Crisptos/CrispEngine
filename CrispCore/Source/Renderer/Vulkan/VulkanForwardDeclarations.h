#pragma once

/*
	Used on headers that are exposed to the agnostic API
*/

namespace Crisp
{
	// Forward Declarations
	//		Vulkan specific types
	typedef struct VkInstance_T* VkInstance;
	typedef struct VkDebugUtilsMessengerEXT_T* VkDebugUtilsMessengerEXT;
	typedef struct VkSurfaceKHR_T* VkSurfaceKHR;
	typedef struct VkDevice_T* VkDevice;
	typedef struct VkPhysicalDevice_T* VkPhysicalDevice;
	typedef struct VkSwapchainKHR_T* VkSwapchainKHR;
	typedef struct VkImage_T* VkImage;
	typedef struct VkImageView_T* VkImageView;
	typedef struct VkRenderPass_T* VkRenderPass;
	typedef struct VkFramebuffer_T* VkFramebuffer;


}