#include "PmergeMe.hpp"

void fordJohnsonSortvect(std::vector<int>& container, int first, int last){
    if (first >= last)
        return;
    int mid = (first + last) / 2;
    for (int i = first; i < last; i += 2)
        if (container[i] > container[i + 1])
            swap(container, i);
    fordJohnsonSortvect(container, first, mid);
    for (int i = mid + 1; i <= last; i++){
        int key = container[i];
        int j = i - 1;
        while (j >= first && container[j] > key){
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}

template <typename Container>
void printBefore(const Container& container) {
    std::cout << "Before: ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void printAfter(const Container& container) {
    std::cout << "After: ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void	sortvect(std::vector<int>& Container, int size){
	clock_t start = clock();
    printBefore(Container);
	fordJohnsonSortvect(Container, 0, size - 1);
    printAfter(Container);
    double time = (clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << size << " elements with std::vector: " <<
        GREEN << std::fixed << time << " us" << RESET << std::endl;
}

void fordJohnsonSortdeq(std::deque<int>& container, int first, int last){
    if (first >= last)
        return;
    int mid = (first + last) / 2;
    for (int i = first; i < last; i += 2)
        if (container[i] > container[i + 1])
            swap(container, i);
    fordJohnsonSortdeq(container, first, mid);
    for (int i = mid + 1; i <= last; i++){
        int key = container[i];
        int j = i - 1;
        while (j >= first && container[j] > key){
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}


void	sortdeq(std::deque<int>& Container, int size){
	clock_t start = clock();
    //printBefore(Container);
	fordJohnsonSortdeq(Container, 0, size - 1);
    //printAfter(Container);
    double time = (clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << size << " elements with std::deque: " <<
        GREEN << std::fixed  << time << " us" << RESET << std::endl;
}