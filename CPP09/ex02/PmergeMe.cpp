
#include "PmergeMe.hpp"

#include <iostream>
#include <list>
#include <iterator>

std::list<int>::iterator get_iterator_at(std::list<int>& container, int index) {
    std::list<int>::iterator it = container.begin();
    std::advance(it, index);  // Advance to the correct position
    return it;                // Now correctly returns the iterator
}

void fordJohnsonSortlist(std::list<int>& container, int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    for (int i = low; i < high; i += 2) {
        std::list<int>::iterator it1 = get_iterator_at(container, i);
        std::list<int>::iterator it2 = get_iterator_at(container, i + 1);

        if (*it1 > *it2) {
            int temp = *it1;
            *it1 = *it2;
            *it2 = temp;
        }
    }
    fordJohnsonSortlist(container, low, mid);
    for (int i = mid + 1; i <= high; i++) {
        std::list<int>::iterator it_key = get_iterator_at(container, i);
        int key = *it_key;

        std::list<int>::iterator it_j = get_iterator_at(container, i - 1);

        while (std::distance(container.begin(), it_j) >= low && *it_j > key) {
            std::list<int>::iterator it_next = get_iterator_at(container, std::distance(container.begin(), it_j) + 1);
            *it_next = *it_j;

            if (it_j == container.begin()) {
                break;
            }

            --it_j;
        }
        std::list<int>::iterator it_next = get_iterator_at(container, std::distance(container.begin(), it_j) + 1);
        *it_next = key;
    }
}
void sortlist(std::list<int>& container, int size) {
    clock_t start = clock();
    std::cout << "before: ";
    for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    fordJohnsonSortlist(container, 0, size - 1);
    std::cout << "after: ";
    for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::list: "
              << std::fixed << (clock() - start) / (double)CLOCKS_PER_SEC << " seconds" << std::endl;
}

void fordJohnsonSortdeq(std::deque<int>& container, int low, int high){
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    for (int i = low; i < high; i += 2)
        if (container[i] > container[i + 1])
            swap(container, i);
    fordJohnsonSortdeq(container, low, mid);
    for (int i = mid + 1; i <= high; i++){
        int key = container[i];
        int j = i - 1;
        while (j >= low && container[j] > key){
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}

void	sortdeq(std::deque<int>& Container, int size){
	clock_t start = clock();
	std::cout << "before: ";
	for(int i = 0; i < size; i++)
		std::cout << Container[i] << " ";
	std::cout << std::endl;
	fordJohnsonSortdeq(Container, 0, size - 1);
	std::cout << "after: ";
	for(int i = 0; i < size; i++)
		std::cout << Container[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::deque: "
        << std::fixed << (clock() - start) / (double)CLOCKS_PER_SEC << " us" << std::endl;
}