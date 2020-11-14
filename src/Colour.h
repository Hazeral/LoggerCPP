// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#ifndef HXZ_COLOUR_H
#define HXZ_COLOUR_H

#include <string>

namespace hxz {
    class Colour {
        public:
        static std::string Red(std::string text);
        static std::string Green(std::string text);
        static std::string Blue(std::string text);
        static std::string Yellow(std::string text);
        static std::string Cyan(std::string text);
    };
}

#endif