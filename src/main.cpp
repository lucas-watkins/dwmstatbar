// Platform check for linux only
#if !(defined(unix) || defined(__unix) || defined(__unix__))
#error You must be on Linux or some BSD for dwmstatbar to function
#endif

#include <locale>
#include <X11/Xlib.h>
#include <iostream>
#include <sstream>
#include <csignal>
#include <unistd.h>
#include <numeric>
#include <sstream>
#include "icon.hpp"
#include "config.hpp"

int main() {
    Display *display{XOpenDisplay(nullptr)};

    if (!display) {
        std::cerr << "dwmstatbar: Could not open display\n";
        return 1;
    }

    static bool dwmstatbar_run{true};
    auto signal_handler{[](int /* ignored */) {dwmstatbar_run = false;}};

    // We'll still close the display if we get killed
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);

    const int screen{DefaultScreen(display)};
    const Window root_window{RootWindow(display, screen)};

    std::stringstream ss{};

    while (dwmstatbar_run) {
        cfg::get_status_string(ss);

        // Get a guaranteed null terminated string
        ss << '\0';

        XStoreName(display, root_window, &ss.view()[0]);

        // Syncs our changes to the X server without closing the display.
        XSync(display, false);

        // Clear stream
        ss.str(std::string{});

        sleep(cfg::update_time_period_sec);
    }

    XCloseDisplay(display);
    return 0;
}
