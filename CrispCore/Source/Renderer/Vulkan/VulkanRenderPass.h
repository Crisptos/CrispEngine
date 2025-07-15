#pragma once
#include "Renderer/Vulkan/VulkanForwardDeclarations.h"
#include "Renderer/Vulkan/VulkanCommandBuffer.h"

namespace Crisp
{
	enum VulkanRenderPassState
	{
		READY,
		RECORDING,
		IN_RENDER_PASS,
		SUBMITTED
	};

	struct VulkanRenderPass
	{
		VkRenderPass handle;
		VulkanRenderPassState state;

		// Clear Color
		float r, g, b, a;
		// Depth and Stencil Values
		float depth;
		uint32_t stencil;

		bool InitializeRenderPass(VkDevice logical_device, uint32_t image_format, uint32_t depth_format);
		void ShutdownRenderPass(VkDevice logical_device);

		void BeginRenderPass(VulkanCommandBuffer& command_buffer, VkFramebuffer frame_buffer);
		void EndRenderPass(VulkanCommandBuffer& command_buffer);
	};


}