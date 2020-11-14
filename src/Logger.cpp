// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#include "Logger.h"

namespace hxz {
    Logger::Logger(int timeMode, bool logToFile, std::string logDir) {
        Logger::_timeMode = timeMode;
        Logger::_logToFile = logToFile;
        Logger::_logDir = logDir;
    }

    std::string Logger::GetTime() {
        switch(Logger::_timeMode) {
            case HXZ_LOGGER_TIME:
                return Time::GetTime();
            case HXZ_LOGGER_DATE:
                return Time::GetDate();
            case HXZ_LOGGER_DATETIME:
                return Time::Now();
            default:
                return Time::Now();
        }
    }

    void Logger::Info(std::string text) {
        if (Logger::_logToFile) FileOutput::LogToFile(Logger::_logDir, "[ " + Logger::GetTime() + " ] " + "[ Info ] " + text);
        
        std::string time = Colour::Cyan("[ ") + Logger::GetTime() + Colour::Cyan(" ]");
        std::string title = Colour::Cyan("[ Info ]");

        std::cout << time + ' ' + title + ' ' + text + '\n';
    }

    void Logger::Warn(std::string text) {
        if (Logger::_logToFile) FileOutput::LogToFile(Logger::_logDir, "[ " + Logger::GetTime() + " ] " + "[ Warning ] " + text);

        std::string time = Colour::Yellow("[ ") + Logger::GetTime() + Colour::Yellow(" ]");
        std::string title = Colour::Yellow("[ Warning ]");

        std::cout << time + ' ' + title + ' ' + text + '\n';
    }

    void Logger::Debug(std::string text) {
        if (Logger::_logToFile) FileOutput::LogToFile(Logger::_logDir, "[ " + Logger::GetTime() + " ] " + "[ Debug ] " + text);

        std::string time = Colour::Blue("[ ") + Logger::GetTime() + Colour::Blue(" ]");
        std::string title = Colour::Blue("[ Debug ]");

        std::cout << time + ' ' + title + ' ' + text + '\n';
    }

    void Logger::Success(std::string text) {
        if (Logger::_logToFile) FileOutput::LogToFile(Logger::_logDir, "[ " + Logger::GetTime() + " ] " + "[ Success ] " + text);

        std::string time = Colour::Green("[ ") + Logger::GetTime() + Colour::Green(" ]");
        std::string title = Colour::Green("[ Success ]");

        std::cout << time + ' ' + title + ' ' + text + '\n';
    }

    void Logger::Error(std::string text) {
        if (Logger::_logToFile) FileOutput::LogToFile(Logger::_logDir, "[ " + Logger::GetTime() + " ] " + "[ Error ] " + text);

        std::string time = Colour::Red("[ ") + Logger::GetTime() + Colour::Red(" ]");
        std::string title = Colour::Red("[ Error ]");

        std::cout << time + ' ' + title + ' ' + text + '\n';
    }
}