#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <algorithm>

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
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "before: ";
    for (int i = 0; i < size; i++)
        std::cout << container[i] << " ";
    std::cout << std::endl;

    fordJohnsonSort(container, 0, size - 1);

    std::cout << "after: ";
    for (int i = 0; i < size; i++)
        std::cout << container[i] << " ";
    std::cout << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time to process a range of " << size << " elements with "
              << (std::is_same<Container, std::vector<int>>::value ? "std::vector" : "std::deque")
              << ": " << std::fixed << elapsed.count() << " seconds" << std::endl;
}

// void fordJohnsonSortvect(std::vector<int>& container, int low, int high){
//     if (low >= high)
//         return;
//     int mid = (low + high) / 2;
//     for (int i = low; i < high; i += 2)
//         if (container[i] > container[i + 1])
//             swap(container, i);
//     fordJohnsonSortvect(container, low, mid);
//     for (int i = mid + 1; i <= high; i++){
//         int key = container[i];
//         int j = i - 1;
//         while (j >= low && container[j] > key){
//             container[j + 1] = container[j];
//             j--;
//         }
//         container[j + 1] = key;
//     }
// }

// void	sortvect(std::vector<int>& Container, int size){
// 	clock_t start = clock();
// 	std::cout << "before: ";
// 	for(int i = 0; i < size; i++)
// 		std::cout << Container[i] << " ";
// 	std::cout << std::endl;
// 	fordJohnsonSortvect(Container, 0, size - 1);
// 	std::cout << "after: ";
// 	for(int i = 0;  i < size; i++)
// 		std::cout << Container[i] << " ";
// 	std::cout << std::endl;
// 	std::cout << "Time to process a range of " << size << " elements with std::vector: "
//         << std::fixed << (clock() - start) / (double)CLOCKS_PER_SEC << " us" << std::endl;
// }

// void fordJohnsonSortdeq(std::deque<int>& container, int low, int high){
//     if (low >= high)
//         return;
//     int mid = (low + high) / 2;
//     for (int i = low; i < high; i += 2)
//         if (container[i] > container[i + 1])
//             swap(container, i);
//     fordJohnsonSortdeq(container, low, mid);
//     for (int i = mid + 1; i <= high; i++){
//         int key = container[i];
//         int j = i - 1;
//         while (j >= low && container[j] > key){
//             container[j + 1] = container[j];
//             j--;
//         }
//         container[j + 1] = key;
//     }
// }

// void	sortdeq(std::deque<int>& Container, int size){
// 	clock_t start = clock();
// 	// std::cout << "before: ";
// 	// for(int i = 0; i < size; i++)
// 	// 	std::cout << Container[i] << " ";
// 	// std::cout << std::endl;
// 	fordJohnsonSortdeq(Container, 0, size - 1);
// 	// std::cout << "after: ";
// 	// for(int i = 0; i < size; i++)
// 	// 	std::cout << Container[i] << " ";
// 	// std::cout << std::endl;
// 	std::cout << "Time to process a range of " << size << " elements with std::deque: "
//         << std::fixed << (clock() - start) / (double)CLOCKS_PER_SEC << " us" << std::endl;
// }