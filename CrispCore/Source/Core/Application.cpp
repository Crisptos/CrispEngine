#include "Core/Logger.h"
#include "Core/Application.h"

namespace Crisp
{
	void Application::InitializeApp()
	{
		CRISP_LOG_INFO("Initializing Crisp Engine Client App...");
		m_Platform.InitializePlatform();
	}

	void Application::ShutdownApp()
	{
		CRISP_LOG_INFO("Shutting down Crisp Engine Client App...");
		m_Platform.ShutdownPlatform();
	}
}