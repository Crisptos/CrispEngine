#pragma once
#include "Core/Events/Event.h"

namespace Crisp
{
	class EventHandler
	{
	public:
		virtual void OnEventHandle(Event& crisp_event) = 0;
		

	};
}