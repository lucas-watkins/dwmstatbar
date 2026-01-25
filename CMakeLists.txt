cmake_minimum_required(VERSION 4.1)
project(dwmstatbar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# Delete the build directory with CMakeCache.txt in it to reapply options
option(DWMSTATBAR_LIBNM_SUPPORT "Support network information in dwmbar using networkmanager" ON)

find_package(PkgConfig REQUIRED)

if (DWMSTATBAR_LIBNM_SUPPORT)
    pkg_check_modules(LIBNM REQUIRED libnm)
    include_directories(${LIBNM_INCLUDE_DIRS})
    link_libraries(${LIBNM_LIBRARIES})
    add_compile_definitions(DWMSTATBAR_LIBNM_SUPPORT)
endif()

pkg_check_modules(X11 REQUIRED x11)
include_directories(${X11_INCLUDE_DIRS})
link_libraries(${X11_LIBRARIES})

add_executable(dwmstatbar src/main.cpp src/icons.cpp src/time.cpp)

add_compile_options("-Werror" "-Wall" "-Wpedantic")
