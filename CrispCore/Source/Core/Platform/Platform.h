#pragma once
#include "Core/Platform/Input.h"
#include "Core/Platform/Window.h"
#include "Core/Events/EventDispatcher.h"

namespace Crisp
{
	class Platform
	{
	public:
		void InitializePlatform(WindowCreateProps& window_create_props);
		void UpdatePlatform(EventDispatcher& dispatcher);
		void ShutdownPlatform();

	private:
		Input m_Input;
		Window m_Window;
	};
}