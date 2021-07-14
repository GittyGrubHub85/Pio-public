#include "Log.h"

namespace Pio {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("PIO");
		s_CoreLogger->set_level(spdlog::level::warn);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_CoreLogger->set_level(spdlog::level::info);

		//s_ClientLogger = spdlog::stdout_color_mt("TRACE");
		s_ClientLogger->set_level(spdlog::level::trace);

		
	}

	/*
	void Log::Log() {

	}
	void Log::~Log() {

	}*/
}