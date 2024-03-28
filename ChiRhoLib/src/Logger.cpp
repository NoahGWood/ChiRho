#include "pch.h"
#include <Core/Logger.h>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace ChiRho
{
    Ref<spdlog::logger> Logger::__CoreLogger;
    Ref<spdlog::logger> Logger::__ClientLogger;    

    void Logger::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        __CoreLogger = spdlog::stdout_color_mt("ChiRho");
        __CoreLogger->set_level(spdlog::level::trace);
        __ClientLogger = spdlog::stdout_color_mt("App");
        __ClientLogger->set_level(spdlog::level::trace);
    }

} // namespace ChiRho
