// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#ifndef HXZ_TIME_H
#define HXZ_TIME_H

#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace hxz {
    class Time {
        public:
        static std::time_t GetEpochTime();
        static std::string GetDate(char divider = '\n');
        static std::string GetTime(char divider = '\n');
        static std::string Now(char date_divider = '\n', char time_divider = '\n', char datetime_divider = ' ');
        static std::string FormatTime(const char* format, bool hasDivider, char divider = '\n', char normalDivider = '-');
        static std::string GetDay();
        static std::string GetMonth();
        static std::string GetYear();
        static std::string GetHour();
        static std::string GetMinute();
        static std::string GetSecond();

        private:
        static std::time_t _t;
        static std::tm _tm;
    };
}

#endif