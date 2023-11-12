#ifndef PRINT_IP_H
#define PRINT_IP_H

#include <array>

#include "helper.h"

namespace print {
    // for numeric
    template <class T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
    void print_ip(T&& ip) {
        constexpr size_t number_of_bytes = sizeof(T);
        std::array<uint8_t, number_of_bytes> bytes{};
        
        std::for_each(bytes.rbegin(), bytes.rend(), [&ip](auto& byte) {
            byte = (ip & 0xff);
            ip >>= 8;
        });

        print_ip_helper_rait(bytes);
    }

    // for string
    template <class T, std::enable_if_t<is_string_v<T>, bool> = true>
    void print_ip(T&& ip) {
        std::cout << ip;
    }

    // for vector
    template <class T, std::enable_if_t<is_vector_v<T>, bool> = true>
    void print_ip(T&& ip) {
        print_ip_helper_rait(ip);
    }

    // for list
    template <class T, std::enable_if_t<is_list_v<T>, bool> = true>
    void print_ip(T&& ip) {
        print_ip_helper_biit(ip);
    }
}

#endif // PRINT_IP_H