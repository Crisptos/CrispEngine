#pragma once
#include <stdint.h>
#include "Core/Events/EventDispatcher.h"

namespace Crisp
{
	class Input
	{
	public:
		static Input& GetInst();
		static void SetInst(Input* inst);

		// Update per frame, copy this state to prev frame state
		static void UpdateState();

		// Keyboard
		static bool IsKeyPressed(uint32_t key);
		static bool IsKeyHeld(uint32_t key);
		static bool IsKeyJustReleased(uint32_t key);

		// Mouse
		static bool IsMouseButtonPressed(uint8_t mouse_btn);
		static bool IsMouseButtonHeld(uint8_t mouse_btn);
		static bool IsMouseButtonJustReleased(uint8_t mouse_btn);

	// Interface implementation
	protected:
		virtual void UpdateStateImpl() = 0;

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