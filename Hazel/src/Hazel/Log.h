#pragma once
#include <memory>
#include <stdio.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hazel {
	class HAZEL_DLL_API Log
	{
	public:
		Log();
		~Log();
		static void Init();
		inline static std::shared_ptr<spdlog::logger> GetCoreLogger();
		inline static std::shared_ptr<spdlog::logger> GetClientLogger();
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define HZ_CORE_TRACE(...)	::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define HZ_CORE_INFO(...)	::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define HZ_CORE_WARN(...)	::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__) 
#define HZ_CORE_ERROR(...)	::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define HZ_CORE_FATAL(...)  ::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__) 

#define HZ_TRACE(...)		::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define HZ_INFO(...)		::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define HZ_WARN(...)		::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__) 
#define HZ_ERROR(...)		::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define HZ_FATAL(...)		::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__) 