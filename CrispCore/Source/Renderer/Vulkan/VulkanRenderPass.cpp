#include "Renderer/Vulkan/VulkanBackendIncludes.h"
#include "Renderer/Vulkan/VulkanRenderPass.h"
#include "Core/Logger.h"

namespace Crisp
{
	bool VulkanRenderPass::InitializeRenderPass(VkDevice logical_device, uint32_t image_format, uint32_t depth_format)
	{
		// TODO Make all of this configurable

		// Main subpass
		VkSubpassDescription subpass = {};
		subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

		// Attachments
		uint32_t attachment_description_count = 2; // hardcoded
		VkAttachmentDescription attachment_descriptions[attachment_description_count];

		// ______________________________________________________
		// Color attachment
		VkAttachmentDescription color_attachment = {};
		color_attachment.format = image_format;
		color_attachment.samples = VK_SAMPLE_COUNT_1_BIT;
		color_attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
		color_attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
		color_attachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
		color_attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		color_attachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		color_attachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
		color_attachment.flags = 0;

		attachment_descriptions[0] = color_attachment;

		VkAttachmentReference color_attachment_reference = {};
		color_attachment_reference.attachment = 0; // Description array index
		color_attachment_reference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

		subpass.colorAttachmentCount = 1;
		subpass.pColorAttachments = &color_attachment_reference;

		// ______________________________________________________
		// Depth attachment

		VkAttachmentDescription depth_attachment = {};
		depth_attachment.format = depth_format;
		depth_attachment.samples = VK_SAMPLE_COUNT_1_BIT;
		depth_attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
		depth_attachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		depth_attachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
		depth_attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		depth_attachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		depth_attachment.finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

		attachment_descriptions[1] = depth_attachment;

		VkAttachmentReference depth_attachment_reference = {};
		depth_attachment_reference.attachment = 1; // Description array index
		depth_attachment_reference.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

		subpass.pDepthStencilAttachment = &depth_attachment_reference;
		// TODO configure other attachment types

		// Render pass dependencies
		VkSubpassDependency dependency;
		dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
		dependency.dstSubpass = 0;
		dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		dependency.srcAccessMask = 0;
		dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
		dependency.dependencyFlags = 0;

		VkRenderPassCreateInfo render_pass_create_info = {};
		render_pass_create_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
		render_pass_create_info.attachmentCount = attachment_description_count;
		render_pass_create_info.pAttachments = attachment_descriptions;
		render_pass_create_info.subpassCount = 1;
		render_pass_create_info.pSubpasses = &subpass;
		render_pass_create_info.dependencyCount = 1;
		render_pass_create_info.pDependencies = &dependency;
		render_pass_create_info.pNext = 0;
		render_pass_create_info.flags = 0;

		if (!vkCreateRenderPass(logical_device, render_pass_create_info, nullptr, handle))
		{
			CRISP_LOG_CRITICAL("Failed to create renderpass!");
			return false;
		}

		return true;

	}

	void VulkanRenderPass::ShutdownRenderPass(VkDevice logical_device)
	{
		vkDestroyRenderPass(logical_device, handle, nullptr);

	}

	void VulkanRenderPass::BeginRenderPass(VulkanCommandBuffer& command_buffer, VkFramebuffer frame_buffer)
	{
		
	}

	void VulkanRenderPass::EndRenderPass(VulkanCommandBuffer& command_buffer)
	{
		
	}
}