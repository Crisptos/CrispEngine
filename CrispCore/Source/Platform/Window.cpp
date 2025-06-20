#include "Window.h"
#include <SDL3/SDL.h>
#include "Core/Logger.h"

namespace Crisp
{
	bool Window::InitializeWindow(WindowCreateProps& window_create_props)
	{
		// Window creation flags will be more customizable based on sent props as development goes on

		// For now we assume these props
		SDL_WindowFlags creation_flags;
		creation_flags = SDL_WINDOW_VULKAN;

		m_PlatformWindow = SDL_CreateWindow(
			window_create_props.window_name,
			window_create_props.w,
			window_create_props.h,
			creation_flags
		);

		if (!m_PlatformWindow)
		{
			CRISP_LOG_CRITICAL("Failed to create window with inputted properties!");
			CRISP_LOG_CRITICAL("w: {0} | h: {1} | name: {2}", window_create_props.w, window_create_props.h, window_create_props.window_name);
			return false;
		}

		// Assume these props for now as well
		SDL_SetWindowPosition(m_PlatformWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
		SDL_SetWindowResizable(m_PlatformWindow, false);

		return true;
	}

	void Window::UpdateWindow()
	{

	}

	void Window::ShutdownWindow()
	{
		SDL_DestroyWindow(m_PlatformWindow);
	}

	SDL_Window* Window::GetHandle() const
	{
		return m_PlatformWindow;
	}
}