//
// Created by lucas on 1/25/26.
//

#ifndef DWMSTATBAR_BATTERY_HPP
#define DWMSTATBAR_BATTERY_HPP

#include "icon.hpp"

class battery {
public:
    static icon::icon_t battery_icon(std::string_view /* Linux battery directory */);
    static int battery_percentage(std::string_view /* Linux battery directory */);
    static bool battery_charging(std::string_view /* Linux battery directory */);
    static std::string battery_percentage_and_icon(std::string_view /* Linux battery directory */);
};


#endif //DWMSTATBAR_BATTERY_HPP