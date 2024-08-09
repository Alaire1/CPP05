#ifndef ITER_HPP
# define ITER_HPP

#include <ostream>
#include <iostream>
#include <string.h>
#include <limits>

template <typename T, typename Func>
void iter(T* address, size_t len, Func function) {
    for (size_t i = 0; i < len; ++i) {
        function(address[i], i == len - 1);
    }
}

template <typename T>
void printElement(const T& element, bool isLast) {
    std::cout << element;
    if (isLast) {
        std::cout << std::endl;
    } else {
        std::cout << " ";
    }
}


#endif