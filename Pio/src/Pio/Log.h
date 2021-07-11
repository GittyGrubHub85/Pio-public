#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Pio{
	class PIO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define PIO_CORE_ERROR(...)		::Pio::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PIO_CORE_WARN(...)		::Pio::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PIO_CORE_INFO(...)		::Pio::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PIO_CORE_TRACE(...)		::Pio::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PIO_CORE_FATAL(...)		::Pio::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define PIO_ERROR(...)			::Pio::Log::GetClientLogger()->error(__VA_ARGS__)
#define PIO_WARN(...)			::Pio::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PIO_INFO(...)			::Pio::Log::GetClientLogger()->info(__VA_ARGS__)
#define PIO_TRACE(...)			::Pio::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PIO_FATAL(...)			::Pio::Log::GetClientLogger()->fatal(__VA_ARGS__)

