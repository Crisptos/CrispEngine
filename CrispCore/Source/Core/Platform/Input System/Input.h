#pragma once
#include <stdint.h>
#include "Core/Events/EventDispatcher.h"

namespace Crisp
{
	class Input
	{
	// Usable via scripts
	public:
		static void SetInst(Input* inst);

		// Keyboard
		static bool IsKeyPressed(uint32_t key);
		static bool IsKeyHeld(uint32_t key);
		static bool IsKeyJustReleased(uint32_t key);

		// Mouse
		static bool IsMouseButtonPressed(uint8_t mouse_btn);
		static bool IsMouseButtonHeld(uint8_t mouse_btn);
		static bool IsMouseButtonJustReleased(uint8_t mouse_btn);

	// Usable only by Platform to modify the singleton
	private:
		static Input& GetInst();
		static void UpdateState();
		static void ReportKeyState(uint32_t key, bool is_pressed);
		static void ReportMouseButtonState(uint8_t mouse_btn, bool is_pressed);

		friend class Platform;

	// Interface implementation
	protected:
		virtual void UpdateStateImpl() = 0;
		virtual void ReportKeyStateImpl(uint32_t key, bool is_pressed) = 0;
		virtual void ReportMouseButtonStateImpl(uint8_t mouse_btn, bool is_pressed) = 0;

		virtual bool IsKeyPressedImpl(uint32_t key) const = 0;
		virtual bool IsKeyHeldImpl(uint32_t key) const = 0;
		virtual bool IsKeyJustReleasedImpl(uint32_t key) const = 0;

		virtual bool IsMouseButtonPressedImpl(uint8_t mouse_btn) const = 0;
		virtual bool IsMouseButtonHeldImpl(uint8_t mouse_btn) const = 0;
		virtual bool IsMouseButtonJustReleasedImpl(uint8_t mouse_btn) const = 0;

	private:
		static Input* s_InputInstance;
	};
}