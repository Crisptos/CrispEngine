#pragma once
#include <stdint.h>

namespace Crisp
{
	enum class EventType : uint8_t
	{
		KEYBOARD_KEY_DOWN,
		KEYBOARD_KEY_UP,
		APP_QUIT,
		MAX_EVENT_TYPE
	};

	// Main Event struct that gets transported through the Event Bus
	struct Event
	{
		EventType event_type;
		bool is_handled = false;

		//union 
		//{
		//	KeyboardEvent keyboard;
		//	MouseButtonEvent mouse_btn;
		//	MouseMovementEvent mouse_mvmnt;
		//};
	};

	// Sub Events carried in the union
	struct KeyboardEvent
	{
		bool test;
	};

	struct MouseButtonEvent
	{
		bool test;
	};

	struct MouseMovementEvent
	{
		bool test;
	};
}