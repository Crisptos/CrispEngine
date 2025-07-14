#include "Renderer/Vulkan/VulkanBackendIncludes.h"
#include "Renderer/Vulkan/VulkanRenderPass.h"

namespace Crisp
{
	void VulkanRenderPass::InitializeRenderPass(VkDevice logical_device, uint32_t image_format, uint32_t depth_format)
	{
		VkRenderPassCreateInfo render_pass_create_info = {};
		render_pass_create_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;

	}

	void VulkanRenderPass::ShutdownRenderPass()
	{

	}

	void VulkanRenderPass::BeginRenderPass()
	{
		
	}

	void VulkanRenderPass::EndRenderPass()
	{
		
	}
}