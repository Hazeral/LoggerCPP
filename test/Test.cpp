// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#include "../src/Logger.h"

// void timeTest() {
//     long long newT = hxz::Time::GetEpochTime() + 1;
//     std::cout << "Epoch time: " << hxz::Time::GetEpochTime() << '\n';
//     std::cout << "Date: " << hxz::Time::GetDate() << '\n';
//     std::cout << "Time: " << hxz::Time::GetTime() << '\n';
//     std::cout << "Now: " << hxz::Time::Now('/') << '\n';

//     std::cout << "Day: " << hxz::Time::GetDay() << '\n';
//     std::cout << "Month: " << hxz::Time::GetMonth() << '\n';
//     std::cout << "Year: " << hxz::Time::GetYear() << '\n';

//     std::cout << "Hour: " << hxz::Time::GetHour() << '\n';
//     std::cout << "Minute: " << hxz::Time::GetMinute() << '\n';
//     std::cout << "Second: " << hxz::Time::GetSecond() << '\n';

//     while(1) {
//         if (hxz::Time::GetEpochTime() == newT) {
//             std::cout << "Time update: " << hxz::Time::GetTime() << '\n';
//             break;
//         }
//     }
// }

// void colourTest() {
//     std::cout << hxz::Colour::Red("Red") << '\n';
//     std::cout << hxz::Colour::Green("Green") << '\n';
//     std::cout << hxz::Colour::Blue("Blue") << '\n';
//     std::cout << hxz::Colour::Yellow("Yellow") << '\n';
//     std::cout << hxz::Colour::Cyan("Cyan") << '\n';
// }

// void fileTest() {
//     hxz::Logger log = hxz::Logger(HXZ_LOGGER_DATETIME, true);
    
//     log.Debug("Testing file output");
// }

void loggerTest() {
    hxz::Logger log = hxz::Logger(HXZ_LOGGER_DATETIME, true);

    log.Info("Info text");
    log.Debug("Debug text");
    log.Warn("Warn text");
    log.Success("Success text");
    log.Error("Error text");
}

int main() {
    // std::cout << "Time class tests\n\n";
    // timeTest();

    // std::cout << "\nColour class tests\n\n";
    // colourTest();

    // std::cout << "\nFileOutput class tests\n\n";
    // fileTest();

    std::cout << "\nLogger class tests\n\n";
    loggerTest();

    return 0;
}