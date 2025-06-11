#include "Core/Logger.h"
#include "Core/Application.h"

// test
#include "Core/Platform/Input System/Input.h"

namespace Crisp
{
	void Application::InitializeApp(WindowCreateProps& window_create_props)
	{
		CRISP_LOG_INFO("Initializing Crisp Engine Client App...");
		m_Platform.InitializePlatform(window_create_props);
		m_AppDispatcher.AddHandler(this);
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			while (!m_IsSuspended && m_IsRunning)
			{
				m_Platform.UpdatePlatform(m_AppDispatcher);
				// TODO just for testing the input class
				if (Input::IsKeyPressed(0x16)) CRISP_LOG_DEBUG("Key {0} was pressed!", 0x16);
				if (Input::IsKeyJustReleased(0x16)) CRISP_LOG_DEBUG("Key {0} was released!", 0x16);
			}
		}
	}

	void Application::ShutdownApp()
	{
		CRISP_LOG_INFO("Shutting down Crisp Engine Client App...");
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