// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#ifndef HXZ_LOGGER_H
#define HXZ_LOGGER_H

#ifdef HXZ_LOGGER_BUILD_STATIC
#define HXZ_LOGGER_API
#else 
#ifdef HXZ_LOGGER_BUILD_DLL
#define HXZ_LOGGER_API __declspec(dllexport)
#else
#define HXZ_LOGGER_API __declspec(dllimport)
#endif
#endif

#define HXZ_LOGGER_TIME 0
#define HXZ_LOGGER_DATE 1
#define HXZ_LOGGER_DATETIME 2

#include "Colour.h"
#include "Time.h"
#include "FileOutput.h"

#include <string>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

namespace hxz {
    class HXZ_LOGGER_API Logger {
        public:
        // timeMode will either be HXZ_LOGGER_TIME, HXZ_LOGGER_DATE or HXZ_LOGGER_DATETIME
        Logger(int timeMode, bool logToFile = false, std::string logDir = ".\\log");
        virtual ~Logger() {};
        void Info(std::string text);
        void Warn(std::string text);
        void Debug(std::string text);
        void Success(std::string text);
        void Error(std::string text);

        private:
        std::string GetTime();
        int _timeMode;
        bool _logToFile;
        std::string _logDir;
    };
}

#ifdef __cplusplus
}
#endif

#endif