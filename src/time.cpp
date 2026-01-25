//
// Created by lucas on 1/24/26.
//

#include "time.hpp"
#include <sstream>
#include <vector>
#include <cstring>

std::string time::get_time(std::string_view time_fmt) {
   const std::chrono::time_point tp{std::chrono::system_clock::now()};
   const std::time_t tp_c{std::chrono::system_clock::to_time_t(tp)};

   static std::vector time_fmt_cstr(time_fmt.size() + 1, '\0');
   std::memcpy(&time_fmt_cstr[0], &time_fmt[0], time_fmt.size());

   std::stringstream ss{};
   ss << std::put_time(std::localtime(&tp_c), &time_fmt_cstr[0]);

   return ss.str();
}
