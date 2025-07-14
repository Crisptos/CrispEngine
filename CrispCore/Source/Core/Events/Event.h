#pragma once
#include <stdint.h>

namespace Crisp
{
	enum class EventType : uint8_t
	{
		KEYBOARD_KEY_DOWN,
		KEYBOARD_KEY_UP,
		WINDOW_RESIZE,
		APP_QUIT,
		MAX_EVENT_TYPE
	};

	// Sub Events carried in the union
	struct WindowResizeEvent
	{
		int32_t new_w;
		int32_t new_h;
	};

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

	// Main Event struct that gets transported through the Event Bus
	struct Event
	{
		EventType event_type;
		bool is_handled = false;

		union
		{
			WindowResizeEvent window_resize;
			//	KeyboardEvent keyboard;
			//	MouseButtonEvent mouse_btn;
			//	MouseMovementEvent mouse_mvmnt;
		};
	};
}