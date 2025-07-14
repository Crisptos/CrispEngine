#pragma once

namespace Crisp
{
	// Forward Declarations
		//		Vulkan specific types
	typedef struct VkCommandBuffer_T* VkCommandBuffer;

	enum VulkanCommandBufferState
	{
		READY,
		RECORDING,
		IN_RENDER_PASS,
		SUBMITTED
	};

	struct VulkanCommandBuffer
	{
		VkCommandBuffer handle;
		VulkanCommandBufferState state;
	};


}