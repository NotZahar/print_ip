#ifndef PRINT_IP_H
#define PRINT_IP_H

#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include <type_traits>

#include "helper.h"

namespace print {
    // for numeric
    template <class T, std::enable_if_t<cond, bool> = true>
    auto print_ip(T&& ip) -> void {
        constexpr size_t numberOfBytes = sizeof(T);
        std::array<uint8_t, numberOfBytes> bytes{};
        
        std::for_each(bytes.rbegin(), bytes.rend(), [&ip](auto& byte) {
            byte = (ip & 0xff);
            ip >>= 8;
        });

        std::cout << +bytes[0];
        std::for_each(bytes.cbegin() + 1, bytes.cend(), [](auto& byte) {
            std::cout << '.' << +byte; 
        });
        std::cout 
        
        << '\n';
    }

    // for string
    template <class T, std::enable_if_t<cond, bool> = true>
    void print_ip(T&& ip) -> decltype(T.c_str()) {
        // TODO: 
        std::cout << '\n';
    }

    // for string
    template <class T, std::enable_if_t<true, T> = true>
    void print_ip(T&& ip) {
        // TODO: 
        std::cout << '\n';
    }
}

#endif // PRINT_IP_H