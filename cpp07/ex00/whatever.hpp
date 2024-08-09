#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <ostream>
#include <iostream>
#include <string.h>

#define YELLOW "\033[33m"
#define RESET "\033[0m"


template <typename T>
void swap(T& a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T>
T max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

#endif