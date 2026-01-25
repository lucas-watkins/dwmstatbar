#ifndef DWMBAR_CONFIG_HPP
#define DWMBAR_CONFIG_HPP

#include "icons.hpp"
#include "time.hpp"

class cfg {
public:

    // How often dwmstatbar updates your status. Once every `update_time_period_sec`
    static constexpr std::size_t update_time_period_sec{10};

    // How dwmstatbar should format the time and date
    static constexpr std::string_view date_time_format{"%I:%M %p %m/%d/%Y"};

    // How dmwstatbar should display your status
    static void get_status_string(std::stringstream &stream) {
        stream << time::get_time(date_time_format);
    }

};

#endif //DWMBAR_CONFIG_HPP