#pragma once

namespace Crisp
{
	enum CommandBufferState
	{
		READY,
		RECORDING,
		IN_RENDER_PASS,
		SUBMITTED
	};

	struct CommandBuffer
	{
		CommandBufferState state;
	};

}