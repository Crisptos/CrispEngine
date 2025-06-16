#pragma once
#include "Platform/Window.h"
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
		Window m_Window;
	};
}