#include "Logger.h"

namespace Crisp
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;


	void Logger::InitializeCoreLogger()
	{
		// Pattern: start color, [Time], level, name:, message, end color
		spdlog::set_pattern("%^[%T] %n (%L): %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("CRISP ENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Logger::GetCoreLogger()
	{
		return s_CoreLogger;
	}
}