#pragma once

namespace Crisp
{
	class Application
	{
	public:
		void InitializeApplication();
		void DestroyApplication();
	};

	Application* CreateApplication();
}