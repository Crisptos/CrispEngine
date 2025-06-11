#include "Core/Platform/Input System/Input.h"

namespace Crisp
{
	class DefaultInput : public Input
	{
	public:
		DefaultInput();

	private:
		void UpdateStateImpl() override;
		void ReportKeyStateImpl(uint32_t key, bool is_pressed) override;
		void ReportMouseButtonStateImpl(uint8_t mouse_btn, bool is_pressed) override;

		bool IsKeyPressedImpl(uint32_t key) const override;
		bool IsKeyHeldImpl(uint32_t key) const override;
		bool IsKeyJustReleasedImpl(uint32_t key) const override;

		bool IsMouseButtonPressedImpl(uint8_t mouse_btn) const override;
		bool IsMouseButtonHeldImpl(uint8_t mouse_btn) const override;
		bool IsMouseButtonJustReleasedImpl(uint8_t mouse_btn) const override;
	
	private:
		struct DefaultInputState
		{
			bool current_keys[128];
			bool prev_keys[128];

			bool current_mouse_btn[16];
			bool prev_mouse_btn[16];
		} m_DefaultInput;
	};

}