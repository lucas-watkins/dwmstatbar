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
#include "icons.hpp"
#include "config.hpp"

// This variable has to be mutable for the signal handler to work
/* NOSONAR */ static Display *display{XOpenDisplay(nullptr)};

[[noreturn]] void signal_handler(int /* ignored */) {
    XCloseDisplay(display);
    std::exit(0);
}

int main() {

    if (!display) {
        std::cerr << "dwmstatbar: Could not open display\n";
        return 1;
    }

    // We'll still close the display if we get killed
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);

    const int screen{DefaultScreen(display)};
    const Window root_window{RootWindow(display, screen)};

    std::stringstream ss{};

    while (true) {
        cfg::get_status_string(ss);

        // Get a guaranteed null terminated string
        ss << static_cast<char>(0);

        XStoreName(display, root_window, ss.view().data());

        // Syncs our changes to the X server without closing the display.
        XSync(display, false);

        // Clear stream
        ss.ignore(std::numeric_limits<std::streamsize>::max());

        sleep(cfg::update_time_period_sec);
    }

    // Unreached
    XCloseDisplay(display);
    return 0;
}
