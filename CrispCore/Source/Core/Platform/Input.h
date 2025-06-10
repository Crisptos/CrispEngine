#pragma once
#include "Core/Events/EventDispatcher.h"

namespace Crisp
{
	class Input : public EventDispatcher
	{
	public:
		void Process();

	};
}