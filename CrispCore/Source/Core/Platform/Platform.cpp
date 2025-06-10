#include "Core/Platform/Platform.h"
#include "Core/Logger.h"
#include <SDL3/SDL.h>

namespace Crisp
{
	void Platform::InitializePlatform()
	{
		CRISP_LOG_INFO("Initializing platform layer...");
		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			CRISP_LOG_CRITICAL("SDL3 failed to initialize!");
			std::abort();
		}
	}

	void Platform::ShutdownPlatform()
	{
		CRISP_LOG_INFO("Shutting down platform layer...");
		SDL_Quit();
	}
}