#pragma once
#include "Core/Platform/Platform.h"

namespace Crisp
{
	class Application
	{
	public:
		void InitializeApp();
		void ShutdownApp();

	private:
		Platform m_Platform;

	};

	Application* CreateApplication();
}