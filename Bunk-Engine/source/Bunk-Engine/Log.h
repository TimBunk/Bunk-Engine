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

// If it is not the distrubtion build then enable loggin
#ifndef BNK_DISTRIBUTION
	// Core log macros
	#define BNK_CORE_TRACE(...)		bnk::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define BNK_CORE_DEBUG(...)		bnk::Log::GetCoreLogger()->debug(__VA_ARGS__)
	#define BNK_CORE_INFO(...)		bnk::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define BNK_CORE_WARN(...)		bnk::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define BNK_CORE_ERROR(...)		bnk::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define BNK_CORE_CRITICAL(...)	bnk::Log::GetCoreLogger()->critical(__VA_ARGS__)
	#define BNK_CORE_ASSERT(expression, ...) if (!expression) { BNK_CORE_CRITICAL(__VA_ARGS__);assert(0); }

	// Client log macros
	#define BNK_APP_TRACE(...)		bnk::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define BNK_APP_DEBUG(...)		bnk::Log::GetClientLogger()->debug(__VA_ARGS__)
	#define BNK_APP_INFO(...)		bnk::Log::GetClientLogger()->info(__VA_ARGS__)
	#define BNK_APP_WARN(...)		bnk::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define BNK_APP_ERROR(...)		bnk::Log::GetClientLogger()->error(__VA_ARGS__)
	#define BNK_APP_CRITICAL(...)	bnk::Log::GetClientLogger()->critical(__VA_ARGS__)
	#define BNK_APP_ASSERT(expression, ...) if (!expression) { BNK_APP_CRITICAL(__VA_ARGS__);assert(0); }
#else
	// Core log macros
	#define BNK_CORE_TRACE(...)
	#define BNK_CORE_DEBUG(...)
	#define BNK_CORE_INFO(...)
	#define BNK_CORE_WARN(...)
	#define BNK_CORE_ERROR(...)
	#define BNK_CORE_CRITICAL(...)
	#define BNK_CORE_ASSERT(expression, ...)

	// Client log macros
	#define BNK_APP_TRACE(...)
	#define BNK_APP_DEBUG(...)
	#define BNK_APP_INFO(...)
	#define BNK_APP_WARN(...)
	#define BNK_APP_ERROR(...)
	#define BNK_APP_CRITICAL(...)
	#define BNK_APP_ASSERT(expression, ...)
#endif

/* Example
int a = 2;
int b = 1;
BNK_CORE_TRACE("trace{1}{0}", a, b);
RESULT = 'trace12'
BNK_CORE_ASSERT(1==0, "Error {0} does not equal {1}", 1, 0);
*/