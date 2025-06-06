#pragma once
#include "Core/Logger.h"
#include "Core/Application.h"

int main(int argc, char** argv)
{
	Crisp::Logger::InitializeCoreLogger();
	auto test_app = Crisp::CreateApplication();
	test_app->InitializeApplication();
	test_app->DestroyApplication();
	return 0;
}