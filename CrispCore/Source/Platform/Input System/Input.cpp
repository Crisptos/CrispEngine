#include "Platform/Input System/Input.h"
#include <SDL3/SDL.h>
#include <cassert>

Crisp::Input* Crisp::Input::s_InputInstance = nullptr;

namespace Crisp
{
	Input& Input::GetInst()
	{
		// TODO Crisp Engine Asserts
		assert(s_InputInstance && "Input::s_InputInstance is not set! SetInstance was never called to initialize impl!");
		return *s_InputInstance;
	}

	void Input::SetInst(Input* inst)
	{
		s_InputInstance = inst;
	}

	void Input::UpdateState()
	{
		return GetInst().UpdateStateImpl();
	}

	void Input::ReportKeyState(uint16_t key, bool is_pressed)
	{
		GetInst().ReportKeyStateImpl(key, is_pressed);
	}

	void Input::ReportMouseButtonState(uint16_t mouse_btn, bool is_pressed)
	{
		GetInst().ReportMouseButtonStateImpl(mouse_btn, is_pressed);
	}

	bool Input::IsKeyPressed(KeyCode key)
	{
		return GetInst().IsKeyPressedImpl(key);
	}

	bool Input::IsKeyHeld(KeyCode key)
	{
		return GetInst().IsKeyHeldImpl(key);
	}

	bool Input::IsKeyJustReleased(KeyCode key)
	{
		return GetInst().IsKeyJustReleasedImpl(key);
	}

	bool Input::IsMouseButtonPressed(uint8_t mouse_btn)
	{
		return GetInst().IsMouseButtonPressedImpl(mouse_btn);
	}

	bool Input::IsMouseButtonHeld(uint8_t mouse_btn)
	{
		return GetInst().IsMouseButtonHeldImpl(mouse_btn);
	}

	bool Input::IsMouseButtonJustReleased(uint8_t mouse_btn)
	{
		return GetInst().IsMouseButtonJustReleasedImpl(mouse_btn);
	}
}