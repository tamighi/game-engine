#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace engine 
{    
    class Log
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

#define HZ_CORE_TRACE(...)  ::engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)   ::engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)   ::engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)  ::engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)  ::engine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define HZ_TRACE(...)       ::engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)        ::engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)        ::engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)       ::engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)       ::engine::Log::GetClientLogger()->fatal(__VA_ARGS__)