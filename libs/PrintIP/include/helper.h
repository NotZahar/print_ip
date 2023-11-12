#ifndef HELPER_H
#define HELPER_H

#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <type_traits>

namespace print {
    template <class T>
    void print_ip_helper_rait(T&& container) {
        std::cout << +container[0];
        std::for_each(container.cbegin() + 1, container.cend(), [](const auto& elem) {
            std::cout << '.' << +elem; 
        });
    }

    template <class T>
    void print_ip_helper_biit(T&& container) {
        std::cout << container.front();
        auto second_it = container.begin();
        std::advance(second_it, 1);
        std::for_each(second_it, container.end(), [](auto& elem) {
            std::cout << '.' << elem; 
        });
    }


    template <class>
    struct is_string_helper : public std::false_type {};
    template <>
    struct is_string_helper<std::string> : public std::true_type {};

    template <class T>
    struct is_string : public is_string_helper<std::remove_cv_t<T>> {};

    template <class T>
    inline constexpr bool is_string_v = is_string<T>::value;

    
    template <class>
    struct is_vector_helper : public std::false_type {};
    template <class... Args>
    struct is_vector_helper<std::vector<Args...>> : public std::true_type {};

    template <class T>
    struct is_vector : public is_vector_helper<std::remove_cv_t<T>> {};
    
    template <class T>
    inline constexpr bool is_vector_v = is_vector<T>::value;


    template <class>
    struct is_list_helper : public std::false_type {};
    template <class... Args>
    struct is_list_helper<std::list<Args...>> : public std::true_type {};

    template <class T>
    struct is_list : public is_list_helper<std::remove_cv_t<T>> {};
    
    template <class T>
    inline constexpr bool is_list_v = is_list<T>::value;
}

#endif // HELPER_H