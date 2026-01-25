//
// Created by lucas on 1/25/26.
//

#include "battery.hpp"
#include "icon.hpp"
#include <filesystem>
#include <fstream>

// Returns battery unknown icon if the user doesn't have a battery
icon::icon_t battery::battery_icon(std::string_view battery_directory) {
    return icon::corresponding_battery_icon(
        battery_percentage(battery_directory),
        battery_charging(battery_directory)
    );
}

int battery::battery_percentage(std::string_view battery_directory) {
    const std::filesystem::path battery_path{battery_directory};

    [[likely]] if (std::filesystem::exists(battery_path)) {

        const std::filesystem::path capacity_file {battery_path / "capacity"};

        [[unlikely]] if (!std::filesystem::exists(capacity_file)) {
            return -1;
        }

        std::ifstream fs{capacity_file};
        std::string percentage{};

        std::getline(fs, percentage);

        return std::stoi(percentage);

    } [[unlikely]] {
        return -1;
    }
}

bool battery::battery_charging(std::string_view battery_directory) {
    const std::filesystem::path battery_path{battery_directory};

    [[likely]] if (std::filesystem::exists(battery_path)) {

        const std::filesystem::path status_file {battery_path / "status"};

        [[unlikely]] if (!std::filesystem::exists(status_file)) {
            return false;
        }

        std::ifstream fs{status_file};
        std::string battery_status{};

        std::getline(fs, battery_status);

        return battery_status == "Charging";

    } [[unlikely]] {
        return false;
    }
}

std::string battery::battery_percentage_and_icon(std::string_view battery_directory) {
    const int charge{battery_percentage(battery_directory)};
    const bool charging{battery_charging(battery_directory)};

    std::stringstream ss{};
    ss << icon::corresponding_battery_icon(charge, charging) << ' ' << charge << '%';

    return ss.str();
}
