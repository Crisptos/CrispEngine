#include "Core/Logger.h"
#include "Core/Application.h"

namespace Crisp
{
	void Application::InitializeApplication()
	{
		CRISP_LOG_INFO("Initializing Crisp Engine Client App...");
	}

	void Application::DestroyApplication()
	{
		CRISP_LOG_INFO("Destroying Crisp Engine Client App...");
	}
}