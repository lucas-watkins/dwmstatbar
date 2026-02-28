//
// Created by lucas on 1/24/26.
//

#include "time.hpp"
#include <sstream>
#include <vector>
#include <cstring>

std::string time::get_time(const std::string& time_fmt) {
   const std::chrono::time_point tp{std::chrono::system_clock::now()};
   const std::time_t tp_c{std::chrono::system_clock::to_time_t(tp)};

   std::stringstream ss{};
   ss << std::put_time(std::localtime(&tp_c), time_fmt.c_str());

   return ss.str();
}
