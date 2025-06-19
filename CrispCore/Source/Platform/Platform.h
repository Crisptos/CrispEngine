#pragma once
#include "Platform/Window.h"
#include "Core/Events/EventDispatcher.h"
#include "Renderer/Renderer.h"

namespace Crisp
{
	class Platform
	{
	public:
		void InitializePlatform(WindowCreateProps& window_create_props);
		void UpdatePlatform(EventDispatcher& dispatcher);
		void ShutdownPlatform();

	private:
		Renderer m_Renderer;
		Window m_Window;
	};
}