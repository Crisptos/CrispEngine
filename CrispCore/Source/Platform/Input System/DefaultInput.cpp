#include "Platform/Input System/DefaultInput.h"

namespace Crisp
{
	DefaultInput::DefaultInput()
	{
		std::memset(m_DefaultInput.current_keys, 0, sizeof(m_DefaultInput.current_keys));
		std::memset(m_DefaultInput.prev_keys, 0, sizeof(m_DefaultInput.prev_keys));
		std::memset(m_DefaultInput.current_mouse_btn, 0, sizeof(m_DefaultInput.current_mouse_btn));
		std::memset(m_DefaultInput.prev_mouse_btn, 0, sizeof(m_DefaultInput.prev_mouse_btn));
	}

	void DefaultInput::UpdateStateImpl()
	{
		std::memcpy(m_DefaultInput.prev_keys, m_DefaultInput.current_keys, sizeof(m_DefaultInput.current_keys));
		std::memcpy(m_DefaultInput.prev_mouse_btn, m_DefaultInput.current_mouse_btn, sizeof(m_DefaultInput.current_mouse_btn));
	}

	void DefaultInput::ReportKeyStateImpl(uint16_t key, bool is_pressed)
	{
		if (key < 0 || key >= 256)
			return;

		if (m_DefaultInput.current_keys[key] != is_pressed)
			m_DefaultInput.current_keys[key] = is_pressed;
	}

	void DefaultInput::ReportMouseButtonStateImpl(uint16_t mouse_btn, bool is_pressed)
	{
		if (mouse_btn < 0 || mouse_btn >= 16)
			return;

		if (m_DefaultInput.current_mouse_btn[mouse_btn] != is_pressed)
			m_DefaultInput.current_mouse_btn[mouse_btn] = is_pressed;
	}

	bool DefaultInput::IsKeyPressedImpl(KeyCode key) const
	{
		return m_DefaultInput.current_keys[key] && !m_DefaultInput.prev_keys[key];
	}

	bool DefaultInput::IsKeyHeldImpl(KeyCode key) const
	{
		return m_DefaultInput.current_keys[key] && m_DefaultInput.prev_keys[key];
	}

	bool DefaultInput::IsKeyJustReleasedImpl(KeyCode key) const
	{
		return !m_DefaultInput.current_keys[key] && m_DefaultInput.prev_keys[key];
	}

	bool DefaultInput::IsMouseButtonPressedImpl(uint8_t mouse_btn) const
	{
		return m_DefaultInput.current_mouse_btn[mouse_btn] && !m_DefaultInput.prev_mouse_btn[mouse_btn];
	}

	bool DefaultInput::IsMouseButtonHeldImpl(uint8_t mouse_btn) const
	{
		return m_DefaultInput.current_mouse_btn[mouse_btn] && m_DefaultInput.prev_mouse_btn[mouse_btn];
	}

	bool DefaultInput::IsMouseButtonJustReleasedImpl(uint8_t mouse_btn) const
	{
		return !m_DefaultInput.current_mouse_btn[mouse_btn] && m_DefaultInput.prev_mouse_btn[mouse_btn];
	}
}