#pragma  once

#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <deque>
#include <list>
#include <vector>
#include <ctime>
#include <deque>
#include <algorithm> // for std::inplace_merge
#include <iterator>  // for std::distance, std::advance
#include <cctype>    // for std::isdigit
#include <cstdlib>   // for std::atoi

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define END "\033[0m"

template <typename T>
void swap(T& container, int i){
    int temp = container[i];
    container[i] = container[i + 1];
    container[i + 1] = temp;
}

void sortlist(std::list<int> &Container, int size);
void	sortdeq(std::deque<int>& Container, int size);