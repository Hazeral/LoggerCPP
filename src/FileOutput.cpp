// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#include "FileOutput.h"

namespace hxz {
    void FileOutput::LogToFile(std::string path, std::string text) {
        std::ofstream logFile;
        std::string fullPath = path + "\\" + Time::GetDate() + "_" + Time::GetHour() + "h.log";
        std::filesystem::create_directories(path);

        logFile.open(fullPath, std::ios::out | std::ios::app);
        logFile << text << std::endl;

        logFile.close();
    }
}