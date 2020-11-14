// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#include "Time.h"

namespace hxz {
    std::time_t Time::_t = std::time(nullptr);
    std::tm Time::_tm = *std::localtime(&Time::_t);

    std::string Time::FormatTime(const char* format, bool hasDivider, char divider, char normalDivider) {
        time_t tn = Time::GetEpochTime();
        Time::_t = std::time(&tn);
        Time::_tm = *std::localtime(&Time::_t);

        std::ostringstream oss;
        oss << std::put_time(&Time::_tm, format);
        auto str = oss.str();
        if (hasDivider && divider != '\n')
            std::replace(str.begin(), str.end(), normalDivider, divider);

        return str;
    }

    std::time_t Time::GetEpochTime() {
        std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        return t;
    }

    std::string Time::GetDate(char divider) {
        return FormatTime("%d-%m-%Y", true, divider, '-');
    }

    std::string Time::GetTime(char divider) {
        return FormatTime("%H:%M:%S", true, divider, ':');
    }

    std::string Time::Now(char date_divider, char time_divider, char datetime_divider) {
        return Time::GetDate(date_divider) + datetime_divider + Time::GetTime(time_divider);
    }

    std::string Time::GetDay() {
        return FormatTime("%d", false);
    }

    std::string Time::GetMonth() {
        return FormatTime("%m", false);
    }

    std::string Time::GetYear() {
        return FormatTime("%Y", false);
    }

    std::string Time::GetHour() {
        return FormatTime("%H", false);
    }

    std::string Time::GetMinute() {
        return FormatTime("%M", false);
    }

    std::string Time::GetSecond() {
        return FormatTime("%S", false);
    }
}