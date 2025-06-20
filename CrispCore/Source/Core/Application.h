#pragma once
#include "Platform/Platform.h"
#include "Renderer/Renderer.h"
#include "Core/Events/EventDispatcher.h"

namespace Crisp
{
	class Application : public EventHandler
	{
	public:
		bool InitializeApp(WindowCreateProps& window_create_props);
		void Run();
		void ShutdownApp();

	private:
		void Quit();
		void OnEventHandle(Event& crisp_event) override;

	private:

		// Engine components
		Platform m_Platform;
		Renderer m_Renderer;
		EventDispatcher m_AppDispatcher;

		// Application state
		bool m_IsRunning = true;
		bool m_IsSuspended = false;

	};

	Application* CreateApplication();
}