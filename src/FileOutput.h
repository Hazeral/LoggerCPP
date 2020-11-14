// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#ifndef HXZ_FILE_H
#define HXZ_FILE_H

#include "Time.h"

#include <fstream>
#include <filesystem>
#include <string>

namespace hxz {
    class FileOutput {
        public:
        static void LogToFile(std::string path, std::string text);
    };
}

#endif