#pragma once

// Forward Declaration
struct SDL_Window;

namespace Crisp
{
	struct WindowCreateProps
	{
		const char* window_name;
		unsigned int w;
		unsigned int h;
	};

	class Window
	{
	public:
		bool InitializeWindow(WindowCreateProps& window_create_props);
		void UpdateWindow();
		void ShutdownWindow();

		SDL_Window* GetHandle() const;

	private:
		SDL_Window* m_PlatformWindow;
	};
}