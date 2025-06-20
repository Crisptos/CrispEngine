#include "Core/Logger.h"
#include "Core/Application.h"

namespace Crisp
{
	bool Application::InitializeApp(WindowCreateProps& window_create_props)
	{
		CRISP_LOG_INFO("Initializing Crisp Engine Client App...");
		if (!m_Platform.InitializePlatform(window_create_props))
		{
			CRISP_LOG_CRITICAL("Failed to initialize platform!");
			return false;
		}

		if (!m_Renderer.InitializeRenderer({ {BackendAPI::VULKAN}, m_Platform.GetWindow().GetHandle(), window_create_props.w, window_create_props.h, false}))
		{
			CRISP_LOG_CRITICAL("Failed to initialize renderer");
			return false;
		}
		m_AppDispatcher.AddHandler(this);

		return true;
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			while (!m_IsSuspended && m_IsRunning)
			{
				m_Platform.UpdatePlatform(m_AppDispatcher);
			}
		}
	}

	void Application::ShutdownApp()
	{
		CRISP_LOG_INFO("Shutting down Crisp Engine Client App...");
		m_Renderer.ShutdownRenderer();
		m_Platform.ShutdownPlatform();
	}

	void Application::Quit()
	{
		m_IsRunning = false;
	}

	void Application::OnEventHandle(Event& crisp_event)
	{
		switch (crisp_event.event_type)
		{
			case EventType::APP_QUIT:
			{
				Quit();
				break;
			}
		}
	}
}