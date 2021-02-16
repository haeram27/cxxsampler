#pragma once

#include <iostream>
#include "spdlog/async.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h" // support for stdout logging
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging
#include "spdlog/sinks/daily_file_sink.h" // support for daily file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging

namespace util{
namespace logger{

void logger_init() {
    try {
        /*** console_logger ***/
        spdlog::logger logger("console_logger", std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        spdlog::set_default_logger(std::make_shared<spdlog::logger>(logger));

        /*** multi_sink_logger: print log into stdout and file ***/
        /*
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/multisink.txt", true);
        spdlog::sinks_init_list sink_list = { file_sink, console_sink };
        spdlog::logger logger("multi_sink_logger", sink_list.begin(), sink_list.end());
        spdlog::set_default_logger(std::make_shared<spdlog::logger>(logger));
        */

        /*** async_rotating_file_logger: 5MB size, 3 maxfile ***/
        /*
        auto logger = spdlog::rotating_logger_mt<spdlog::async_factory>("async_rotating_file_logger", "logs/async_rotating_log.txt", 1048576 * 5, 3);
        spdlog::set_default_logger(logger);
        */

        /*** async_daily_file_logger: 5 maxfile ***/
        /*
        auto logger = spdlog::daily_logger_mt<spdlog::async_factory>("async_daily_file_logger", "logs/async_daily_log.txt", 0, 0, false, 5);
        spdlog::set_default_logger(logger);
        */

        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e][%P-%t][%^%l%$] %v ");
    }
    catch (const spdlog::spdlog_ex& ex) {
        std::cout << "Logger initialization failed: " << ex.what() << std::endl;
    }

//    spdlog::debug("How to log.. {} ,{}", 1, 3.23);
//    SPDLOG_DEBUG("How to log.. {} ,{}", 1, 3.23);
//    SPDLOG_LOGGER_DEBUG(logger , "How to log.. {} ,{}", 1, 3.23);
}

}
}