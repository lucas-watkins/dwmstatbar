#include "icon.hpp"
#include <array>

icon::icon_t icon::corresponding_battery_icon(const int battery_percentage, const bool is_charging) {
    if (battery_percentage < 0 || battery_percentage > 100) {
        return battery_unknown;
    }

    constexpr std::array icon_charging_table {
        battery_charging_10,
        battery_charging_10,
        battery_charging_20,
        battery_charging_30,
        battery_charging_40,
        battery_charging_50,
        battery_charging_60,
        battery_charging_70,
        battery_charging_80,
        battery_charging_90,
        battery_charging_100
    };

    constexpr std::array icon_table {
        battery_warning, // Warning that your laptop's battery is about to die
        battery_10,
        battery_20,
        battery_30,
        battery_40,
        battery_50,
        battery_60,
        battery_70,
        battery_80,
        battery_90,
        battery_100
    };

    const int idx{battery_percentage / 10};

    if (is_charging) {
        return icon_charging_table[idx];
    }

    return icon_table[idx];
}
