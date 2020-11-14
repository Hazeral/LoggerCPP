// Copyright(c) 2020-present, Muhammad Usman. (https://github.com/Hazeral)
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
#include "Colour.h"

struct ColourCodes {
    std::string _sp = "\u001b";
    std::string Reset = _sp + "[0m";
    std::string Red = _sp + "[31m";
    std::string Green = _sp + "[32m";
    std::string Blue = _sp + "[34m";
    std::string Yellow = _sp + "[33m";
    std::string Cyan = _sp + "[36m";
};

ColourCodes CC;

namespace hxz {
    std::string Colour::Red(std::string text) {
        return CC.Red + text + CC.Reset;
    }

    std::string Colour::Green(std::string text) {
        return CC.Green + text + CC.Reset;
    }

    std::string Colour::Blue(std::string text) {
        return CC.Blue + text + CC.Reset;
    }

    std::string Colour::Yellow(std::string text) {
        return CC.Yellow + text + CC.Reset;
    }

    std::string Colour::Cyan(std::string text) {
        return CC.Cyan + text + CC.Reset;
    }
}