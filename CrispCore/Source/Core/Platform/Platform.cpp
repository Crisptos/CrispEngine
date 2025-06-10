#include "Core/Platform/Platform.h"
#include "Core/Logger.h"
#include <SDL3/SDL.h>

namespace Crisp
{
	void Platform::InitializePlatform(WindowCreateProps& window_create_props)
	{
		CRISP_LOG_INFO("Initializing platform layer...");
		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			CRISP_LOG_CRITICAL("SDL3 failed to initialize!");
			std::abort();
		}

		m_Window.InitializeWindow(window_create_props);
	}

	void Platform::UpdatePlatform(EventDispatcher& dispatcher)
	{
		SDL_Event sdl_event;
		while (SDL_PollEvent(&sdl_event))
		{
			switch (sdl_event.type)
			{
				case SDL_EVENT_QUIT:
				{
					Event crisp_event = {EventType::APP_QUIT, false};
					dispatcher.NotifyAll(crisp_event);
					break;
				}
			}
		}
	}

	void Platform::ShutdownPlatform()
	{
		CRISP_LOG_INFO("Shutting down platform layer...");
		m_Window.ShutdownWindow();
		SDL_Quit();
	}
}