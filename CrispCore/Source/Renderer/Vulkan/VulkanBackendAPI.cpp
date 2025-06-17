#include "Renderer/Vulkan/VulkanIncludes.h"
#include "Renderer/Vulkan/VulkanBackendAPI.h"

namespace Crisp
{
	void VulkanBackend::InitializeRendererBackendAPI()
	{
		VkApplicationInfo app_info = {};
		app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		app_info.apiVersion = VK_API_VERSION_1_4;
		app_info.pApplicationName = "Test";
		app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		app_info.pEngineName = "Crisp Engine";
		app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);

		VkInstanceCreateInfo create_info = {};
		create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		create_info.pApplicationInfo = &app_info;
	}

	void VulkanBackend::ShutdownRendererBackendAPI()
	{

	}
}