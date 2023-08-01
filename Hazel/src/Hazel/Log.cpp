#include "Log.h"
namespace Hazel
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		s_CoreLogger = spdlog::default_logger();
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::default_logger();
		s_ClientLogger->set_level(spdlog::level::trace);
	}
	std::shared_ptr<spdlog::logger> Log::GetCoreLogger()
	{
		return s_CoreLogger;
	}
	std::shared_ptr<spdlog::logger> Log::GetClientLogger()
	{
		return s_ClientLogger;
	}
}