#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <algorithm>
#include <typeinfo>

// Swap function
template <typename Container>
void swap(Container& container, int i) {
    std::swap(container[i], container[i + 1]);
}

// Ford-Johnson Sort
template <typename Container>
void fordJohnsonSort(Container& container, int low, int high) {
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    for (int i = low; i < high; i += 2)
        if (container[i] > container[i + 1])
            swap(container, i);
    fordJohnsonSort(container, low, mid);
    for (int i = mid + 1; i <= high; i++) {
        int key = container[i];
        int j = i - 1;
        while (j >= low && container[j] > key) {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}

// Sort function
template <typename Container>
void sortContainer(Container& container, int size) {
    std::clock_t start = std::clock();
    std::cout << "before: ";
    for (int i = 0; i < size; i++)
        std::cout << container[i] << " ";
    std::cout << std::endl;

    fordJohnsonSort(container, 0, size - 1);

    std::cout << "after: ";
    for (int i = 0; i < size; i++)
        std::cout << container[i] << " ";
    std::cout << std::endl;

    std::clock_t end = std::clock();
    double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << size << " elements with "
              << (typeid(Container) == typeid(std::vector<int>) ? "std::vector" : "std::deque")
              << ": " << std::fixed << elapsed << " seconds" << std::endl;
}