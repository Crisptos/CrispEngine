#pragma once
#include "Renderer/Vulkan/VulkanForwardDeclarations.h"

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

		void InitializeRenderPass(VkDevice logical_device, uint32_t image_format, uint32_t depth_format);
		void ShutdownRenderPass();

		void BeginRenderPass();
		void EndRenderPass();
	};


}