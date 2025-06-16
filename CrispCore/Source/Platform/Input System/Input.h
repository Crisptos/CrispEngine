#pragma once
#include <stdint.h>
#include "Core/Events/EventDispatcher.h"

namespace Crisp
{
    enum MouseButton : uint16_t
    {
        ONE = 0x1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        ELEVEN,
        TWELVE,
        THIRTEEN,
        FOURTEEN,
        FIFTEEN,
        SIXTEEN,
    };

	enum KeyCode : uint16_t
	{
        UNKNOWN = 0x00,

        // English Letters
        A = 0x04, B, C, D, E, F, G, H, I, J,
        K, L, M, N, O, P, Q, R, S, T,
        U, V, W, X, Y, Z, // up to 0x1D

        // Numbers
        NUM_1 = 0x1E, NUM_2, NUM_3, NUM_4, NUM_5,
        NUM_6, NUM_7, NUM_8, NUM_9, NUM_0, // up to 0x27

        RETURN = 0x28,
        ESCAPE = 0x29,
        BACKSPACE = 0x2A,
        TAB = 0x2B,
        SPACE = 0x2C,

        MINUS = 0x2D,
        EQUALS = 0x2E,
        LEFT_BRACKET = 0x2F,
        RIGHT_BRACKET = 0x30,
        BACKSLASH = 0x31,
        NON_US_HASH = 0x32,
        SEMICOLON = 0x33,
        APOSTROPHE = 0x34,
        GRAVE = 0x35,
        COMMA = 0x36,
        PERIOD = 0x37,
        SLASH = 0x38,

        CAPS_LOCK = 0x39,

        F1 = 0x3A, F2, F3, F4, F5, F6,
        F7, F8, F9, F10, F11, F12,

        PRINT_SCREEN = 0x46,
        SCROLL_LOCK = 0x47,
        PAUSE = 0x48,
        INSERT = 0x49,
        HOME = 0x4A,
        PAGE_UP = 0x4B,
        DELETE = 0x4C,
        END = 0x4D,
        PAGE_DOWN = 0x4E,
        RIGHT = 0x4F,
        LEFT = 0x50,
        DOWN = 0x51,
        UP = 0x52,

        NUM_LOCK = 0x53,
        NUMPAD_DIVIDE = 0x54,
        NUMPAD_MULTIPLY = 0x55,
        NUMPAD_MINUS = 0x56,
        NUMPAD_PLUS = 0x57,
        NUMPAD_ENTER = 0x58,
        NUMPAD_1 = 0x59, NUMPAD_2, NUMPAD_3, NUMPAD_4,
        NUMPAD_5, NUMPAD_6, NUMPAD_7, NUMPAD_8, NUMPAD_9, NUMPAD_0, NUMPAD_PERIOD = 0x63,

        NON_US_BACKSLASH = 0x64,
        APPLICATION = 0x65,
        POWER = 0x66,
        NUMPAD_EQUALS = 0x67,

        F13 = 0x68, F14, F15, F16, F17, F18,
        F19, F20, F21, F22, F23, F24,

        // International
        INTERNATIONAL1 = 0x87, INTERNATIONAL2, INTERNATIONAL3,
        INTERNATIONAL4, INTERNATIONAL5, INTERNATIONAL6, INTERNATIONAL7,
        INTERNATIONAL8, INTERNATIONAL9,

        // Language keys
        LANG1 = 0x90, LANG2, LANG3, LANG4, LANG5,
        LANG6, LANG7, LANG8, LANG9,

        // Control
        LEFT_CTRL = 0xE0,
        LEFT_SHIFT = 0xE1,
        LEFT_ALT = 0xE2,
        LEFT_GUI = 0xE3,
        RIGHT_CTRL = 0xE4,
        RIGHT_SHIFT = 0xE5,
        RIGHT_ALT = 0xE6,
        RIGHT_GUI = 0xE7,

        // Media keys (optional)
        MUTE = 0x7F,
        VOLUME_UP = 0x80,
        VOLUME_DOWN = 0x81,
	};

	class Input
	{
	// Usable via scripts
	public:
		static void SetInst(Input* inst);

		// Keyboard
		static bool IsKeyPressed(KeyCode key);
		static bool IsKeyHeld(KeyCode key);
		static bool IsKeyJustReleased(KeyCode key);

		// Mouse
		static bool IsMouseButtonPressed(uint8_t mouse_btn);
		static bool IsMouseButtonHeld(uint8_t mouse_btn);
		static bool IsMouseButtonJustReleased(uint8_t mouse_btn);

	// Usable only by Platform to modify the singleton
	private:
		static Input& GetInst();
		static void UpdateState();
		static void ReportKeyState(uint16_t key, bool is_pressed);
		static void ReportMouseButtonState(uint16_t mouse_btn, bool is_pressed);

		friend class Platform;

	// Interface implementation
	protected:
		virtual void UpdateStateImpl() = 0;
		virtual void ReportKeyStateImpl(uint16_t key, bool is_pressed) = 0;
		virtual void ReportMouseButtonStateImpl(uint16_t mouse_btn, bool is_pressed) = 0;

		virtual bool IsKeyPressedImpl(KeyCode key) const = 0;
		virtual bool IsKeyHeldImpl(KeyCode key) const = 0;
		virtual bool IsKeyJustReleasedImpl(KeyCode key) const = 0;

		virtual bool IsMouseButtonPressedImpl(uint8_t mouse_btn) const = 0;
		virtual bool IsMouseButtonHeldImpl(uint8_t mouse_btn) const = 0;
		virtual bool IsMouseButtonJustReleasedImpl(uint8_t mouse_btn) const = 0;

	private:
		static Input* s_InputInstance;
	};
}