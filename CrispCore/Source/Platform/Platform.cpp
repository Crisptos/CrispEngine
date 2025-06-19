#include "Platform/Platform.h"
#include "Core/Logger.h"
#include "Platform/Input System/DefaultInput.h"
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


		m_Renderer.InitializeRenderer({ {BackendAPI::VULKAN}, window_create_props.w, window_create_props.h, false });
		Input::SetInst(new DefaultInput);
	}

	void Platform::UpdatePlatform(EventDispatcher& dispatcher)
	{
		Input::UpdateState();
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

				case SDL_EVENT_KEY_DOWN:
				{
					Input::ReportKeyState(sdl_event.key.scancode, true);
					break;
				}

				case SDL_EVENT_KEY_UP:
				{
					Input::ReportKeyState(sdl_event.key.scancode, false);
					break;
				}

				case SDL_EVENT_MOUSE_BUTTON_DOWN:
				{
					Input::ReportMouseButtonState(sdl_event.button.button, true);
					break;
				}

				case SDL_EVENT_MOUSE_BUTTON_UP:
				{
					Input::ReportMouseButtonState(sdl_event.button.button, false);
					break;
				}
			}
		}
	}

	void Platform::ShutdownPlatform()
	{
		CRISP_LOG_INFO("Shutting down platform layer...");
		m_Renderer.ShutdownRenderer();
		m_Window.ShutdownWindow();
		SDL_Quit();
	}
}