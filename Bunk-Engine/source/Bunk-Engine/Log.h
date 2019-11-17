#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace bnk {

	class BNK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}

// Core log macros
#define BNK_CORE_TRACE(...)		::bnk::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BNK_CORE_DEBUG(...)		::bnk::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define BNK_CORE_INFO(...)		::bnk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BNK_CORE_WARN(...)		::bnk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BNK_CORE_ERROR(...)		::bnk::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BNK_CORE_CRITICAL(...)	::bnk::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define BNK_TRACE(...)		::bnk::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BNK_DEBUG(...)		::bnk::Log::GetClientLogger()->debug(__VA_ARGS__)
#define BNK_INFO(...)		::bnk::Log::GetClientLogger()->info(__VA_ARGS__)
#define BNK_WARN(...)		::bnk::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BNK_ERROR(...)		::bnk::Log::GetClientLogger()->error(__VA_ARGS__)
#define BNK_CRITICAL(...)	::bnk::Log::GetClientLogger()->critical(__VA_ARGS__)

/* Example
int a = 2;
int b = 1;
BNK_CORE_TRACE("trace{1}{0}", a, b);
RESULT = 'trace12'
*/