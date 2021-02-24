// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#include "Logger.h"

namespace hxz {
    Logger::Logger(int timeMode, bool logToFile, std::string logDir) {
        Logger::_timeMode = timeMode;
        Logger::_logToFile = logToFile;
        Logger::_logDir = logDir;

        Logger::_colours = {
            {"Info", &Colour::Cyan},
            {"Warn", &Colour::Yellow},
            {"Debug", &Colour::Blue},
            {"Success", &Colour::Green},
            {"Error", &Colour::Red}
        };
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

    void Logger::Log(std::string type, std::string text) {
        std::string(*colour)(std::string) = _colours.find(type)->second;

        if (Logger::_logToFile) FileOutput::LogToFile(Logger::_logDir, "[ " + Logger::GetTime() + " ] " + "[ " + type + " ] " + text);
        
        std::string time = colour("[ ") + Logger::GetTime() + colour(" ]");
        std::string title = colour("[ " + type + " ]");

        std::cout << time + ' ' + title + ' ' + text + '\n';
    }

    void Logger::Info(std::string text) { Log("Info", text); }
    void Logger::Warn(std::string text) { Log("Warn", text); }
    void Logger::Debug(std::string text) { Log("Debug", text); }
    void Logger::Success(std::string text) { Log("Success", text); }
    void Logger::Error(std::string text) { Log("Error", text); }
}