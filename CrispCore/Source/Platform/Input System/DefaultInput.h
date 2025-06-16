#include "Platform/Input System/Input.h"

namespace Crisp
{
	class DefaultInput : public Input
	{
	public:
		DefaultInput();

	private:
		void UpdateStateImpl() override;
		void ReportKeyStateImpl(uint16_t key, bool is_pressed) override;
		void ReportMouseButtonStateImpl(uint16_t mouse_btn, bool is_pressed) override;

		bool IsKeyPressedImpl(KeyCode key) const override;
		bool IsKeyHeldImpl(KeyCode key) const override;
		bool IsKeyJustReleasedImpl(KeyCode key) const override;

		bool IsMouseButtonPressedImpl(uint8_t mouse_btn) const override;
		bool IsMouseButtonHeldImpl(uint8_t mouse_btn) const override;
		bool IsMouseButtonJustReleasedImpl(uint8_t mouse_btn) const override;
	
	private:
		struct DefaultInputState
		{
			bool current_keys[256];
			bool prev_keys[256];

			bool current_mouse_btn[16];
			bool prev_mouse_btn[16];
		} m_DefaultInput;
	};

}