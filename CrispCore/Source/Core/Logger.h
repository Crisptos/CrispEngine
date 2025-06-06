#pragma once
#include <memory>
#include <string>
#include <cstdarg>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Crisp
{
	class Logger
	{
	public:
		static void InitializeCoreLogger();
		static std::shared_ptr<spdlog::logger>& GetCoreLogger();

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define CRISP_LOG_CRITICAL(...) Crisp::Logger::GetCoreLogger()->critical(__VA_ARGS__);
#define CRISP_LOG_ERROR(...) Crisp::Logger::GetCoreLogger()->error(__VA_ARGS__);
#define CRISP_LOG_WARN(...) Crisp::Logger::GetCoreLogger()->warn(__VA_ARGS__);
#define CRISP_LOG_INFO(...) Crisp::Logger::GetCoreLogger()->info(__VA_ARGS__);
#define CRISP_LOG_TRACE(...) Crisp::Logger::GetCoreLogger()->trace(__VA_ARGS__);
#define CRISP_LOG_DEBUG(...) Crisp::Logger::GetCoreLogger()->debug(__VA_ARGS__);