#pragma once
#include "Core/Logger.h"
#include "Core/Application.h"

int main(int argc, char** argv)
{
	Crisp::Logger::InitializeCoreLogger();
	auto test_app = Crisp::CreateApplication();
	Crisp::WindowCreateProps my_window_props = {"CrispTest Window!", 1280, 720};
	test_app->InitializeApp(my_window_props);
	test_app->Run();
	test_app->ShutdownApp();
	return 0;
}