#include "Core/Platform/Input System/DefaultInput.h"

namespace Crisp
{
	void DefaultInput::UpdateStateImpl()
	{
		std::memcpy(m_DefaultInput.prev_keys, m_DefaultInput.current_keys, sizeof(m_DefaultInput.current_keys));
		std::memcpy(m_DefaultInput.prev_mouse_btn, m_DefaultInput.current_mouse_btn, sizeof(m_DefaultInput.current_mouse_btn));
	}

	bool DefaultInput::IsKeyPressedImpl(uint32_t key) const
	{
		return m_DefaultInput.current_keys[key] && !m_DefaultInput.prev_keys[key];
	}

	bool DefaultInput::IsKeyHeldImpl(uint32_t key) const
	{
		return m_DefaultInput.current_keys[key] && m_DefaultInput.prev_keys[key];
	}

	bool DefaultInput::IsKeyJustReleasedImpl(uint32_t key) const
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