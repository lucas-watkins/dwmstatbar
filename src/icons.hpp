#ifndef DWMBAR_WIDGETS_HPP
#define DWMBAR_WIDGETS_HPP

#include <string_view>

class icon {
public:
    using icon_t = std::string_view;

    static constexpr icon_t battery_100{"󰁹"};
    static constexpr icon_t battery_90{"󰂂"};
    static constexpr icon_t battery_80{"󰂁"};
    static constexpr icon_t battery_70{"󰂀"};
    static constexpr icon_t battery_60{"󰁿"};
    static constexpr icon_t battery_50{"󰁾"};
    static constexpr icon_t battery_40{"󰁽"};
    static constexpr icon_t battery_30{"󰁼"};
    static constexpr icon_t battery_20{"󰁻"};
    static constexpr icon_t battery_10{"󰁺"};

    // Note: No icons exist for 70%, 50%, nor 10% in my font.
    // They have been replaced with 60%, 40%, and 20% respectively.
    static constexpr icon_t battery_charging_100{"󰂅"};
    static constexpr icon_t battery_charging_90{"󰂋"};
    static constexpr icon_t battery_charging_80{"󰂊"};
    static constexpr icon_t battery_charging_70{"󰂉"};
    static constexpr icon_t battery_charging_60{"󰂉"};
    static constexpr icon_t battery_charging_50{"󰂈"};
    static constexpr icon_t battery_charging_40{"󰂈"};
    static constexpr icon_t battery_charging_30{"󰂇"};
    static constexpr icon_t battery_charging_20{"󰂇"};
    static constexpr icon_t battery_charging_10{"󰂇"};

    static constexpr icon_t battery_warning{"󰂃"};
    static constexpr icon_t battery_unknown{"󰂑"};

    static constexpr icon_t coressponding_battery_icon(int /* Bat % */, bool /* Charging? */);
};

#endif //DWMBAR_WIDGETS_HPP