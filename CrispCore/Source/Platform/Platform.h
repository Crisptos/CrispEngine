#pragma once
#include "Platform/Window.h"
#include "Core/Events/EventDispatcher.h"

namespace Crisp
{
	class Platform
	{
	public:
		bool InitializePlatform(WindowCreateProps& window_create_props);
		void UpdatePlatform(EventDispatcher& dispatcher);
		void ShutdownPlatform();

		Window& GetWindow();

	private:
		Window m_Window;
	};
}