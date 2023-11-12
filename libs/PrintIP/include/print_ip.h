#ifndef PRINT_IP_H
#define PRINT_IP_H

#include <array>
#include <iterator>
#include <utility>

#include "helper.h"

/// @brief Основной namespace для PrintIP  
namespace print {
    
    /// @brief Реализация функции печати для разных типов
    namespace impl {
        
        /// @brief Функция печати для целочисленных типов, число печатается по байтно
        /// @tparam T Целочисленный тип
        /// @tparam enable_if... Параметр для SFINAE
        /// @param ip IP в виде числа
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

        /// @brief Функция печати для std::string, печатается "как есть"
        /// @tparam T std::string
        /// @tparam enable_if... Параметр для SFINAE
        /// @param ip IP в виде std::string
        template <class T, std::enable_if_t<is_string_v<T>, bool> = true>
        void print_ip(T&& ip) {
            std::cout << ip;
        }

        /// @brief Функция печати для std::vector, печатается по элементно
        /// @tparam T std::vector
        /// @tparam enable_if... Параметр для SFINAE
        /// @param ip IP в виде std::vector
        template <class T, std::enable_if_t<is_vector_v<T>, bool> = true>
        void print_ip(T&& ip) {
            print_ip_helper_rait(ip);
        }

        /// @brief Функция печати для std::list, печатается по элементно
        /// @tparam T std::list
        /// @tparam enable_if... Параметр для SFINAE
        /// @param ip IP в виде std::list
        template <class T, std::enable_if_t<is_list_v<T>, bool> = true>
        void print_ip(T&& ip) {
            print_ip_helper_biit(ip);
        }   
    }

    /// @brief Функция печати для различных типов, выбор функции для определенных
    /// типов осуществляется путем использования механизма SFINAE
    /// @tparam T Формат IP
    /// @param ip IP
    template <class T>
    void print_ip(T&& ip) {
        impl::print_ip(std::forward<T>(ip));
    }
}

#endif // PRINT_IP_H