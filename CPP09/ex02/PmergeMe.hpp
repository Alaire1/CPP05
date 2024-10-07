#pragma once
#include <iomanip>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

template <typename T>
void swap(T& container, int i){
    int temp = container[i];
    container[i] = container[i + 1];
    container[i + 1] = temp;
}

void	sortvect(std::vector<int>& Container, int size);
void	sortdeq(std::deque<int>& Container, int size);