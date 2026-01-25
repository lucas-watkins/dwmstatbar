#ifndef DWMBAR_CONFIG_HPP
#define DWMBAR_CONFIG_HPP

#include "icon.hpp"
#include "time.hpp"
#include "battery.hpp"

class cfg {
public:

    // How often dwmstatbar updates your status. Once every `update_time_period_sec`
    static constexpr std::size_t update_time_period_sec{10};

    // How dwmstatbar should format the time and date
    static constexpr std::string_view date_time_format{"%I:%M %p %m/%d/%Y"};

    // What directory should dwmstatbar look to for getting battery information.
    // Delete or leave empty if you don't have a battery.
    static constexpr std::string_view battery_directory{"/sys/class/power_supply/BAT1"};

    // How dmwstatbar should display your status
    static void get_status_string(std::stringstream &stream) {
        stream << ' '
               << battery::battery_percentage_and_icon(battery_directory)
               << " | "
               << time::get_time(date_time_format)
               << ' ';
    }

};

#endif //DWMBAR_CONFIG_HPP