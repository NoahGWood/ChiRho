#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace ChiRho
{
    class Logger
    {
        public:
            static void Init();
            inline static Ref<spdlog::logger>& GetCoreLogger()  { return __CoreLogger; }
            inline static Ref<spdlog::logger>& GetClientLogger()  { return __ClientLogger; }

        private:
            static Ref<spdlog::logger> __CoreLogger;
            static Ref<spdlog::logger> __ClientLogger;
    };
  
} // namespace ChiRho

// Core logging macros
#define CR_CORE_TRACE(...) ::ChiRho::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define CR_CORE_INFO(...) ::ChiRho::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define CR_CORE_WARN(...) ::ChiRho::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define CR_CORE_ERROR(...) ::ChiRho::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define CR_CORE_CRITICAL(...) ::ChiRho::Logger::GetCoreLogger()->critical(__VA_ARGS__)

// Client logging macros

#define CR_TRACE(...) ::ChiRho::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define CR_INFO(...) ::ChiRho::Logger::GetClientLogger()->info(__VA_ARGS__)
#define CR_WARN(...) ::ChiRho::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define CR_ERROR(...) ::ChiRho::Logger::GetClientLogger()->error(__VA_ARGS__)
#define CR_CRITICAL(...) ::ChiRho::Logger::GetClientLogger()->critical(__VA_ARGS__)
