//
// Created by lucas on 1/24/26.
//

#ifndef DWMSTATBAR_TIME_HPP
#define DWMSTATBAR_TIME_HPP

#include <chrono>

class time {
public:
    static std::string get_time(std::string_view /* time format */);
};


#endif //DWMSTATBAR_TIME_HPP