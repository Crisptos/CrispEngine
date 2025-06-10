#include "EventDispatcher.h"

namespace Crisp
{
	void EventDispatcher::AddHandler(EventHandler* event_handler)
	{
		m_Handlers.push_front(event_handler);
	}

	void EventDispatcher::RemoveHandler(EventHandler* event_handler)
	{
		m_Handlers.remove(event_handler);
	}

	void EventDispatcher::NotifyAll(Event& crisp_event)
	{
		for (EventHandler* handler : m_Handlers)
		{
			if (crisp_event.is_handled) break;
			handler->OnEventHandle(crisp_event);
		}
	}
}