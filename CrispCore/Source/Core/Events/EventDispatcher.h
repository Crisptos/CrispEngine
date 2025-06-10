#pragma once
#include <forward_list>
#include "Core/Events/Event.h"
#include "Core/Events/EventHandler.h"

namespace Crisp
{
	class EventDispatcher
	{
	public:
		void AddHandler(EventHandler* event_handler);
		void RemoveHandler(EventHandler* event_handler);
		void NotifyAll(Event& crisp_event);

	protected:
		std::forward_list<EventHandler*> m_Handlers;
	};
}