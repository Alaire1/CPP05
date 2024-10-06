#include "PmergeMe.hpp"
#include <iomanip>
#include <iostream>


template <typename T>
void PmergeMe::merge(const T &container, typename T::iterator left, typename T::iterator middle, typename T::iterator right) {
(void )container;
    T leftContainer(left, middle);
    T rightContainer(middle, right);

    typename T::iterator leftIt = leftContainer.begin();
    typename T::iterator rightIt = rightContainer.begin();
    typename T::iterator it = left;

    while (leftIt != leftContainer.end() && rightIt != rightContainer.end()) {
        if (*leftIt <= *rightIt)
            *it++ = *leftIt++;
        else
            *it++ = *rightIt++;
    }
    while (leftIt != leftContainer.end())
        *it++ = *leftIt++;

    while (rightIt != rightContainer.end())
        *it++ = *rightIt++;
}


template <typename T>
void PmergeMe::insertionSort(T &container, typename T::iterator left, typename T::iterator right) {
    for (typename T::iterator i = left; i != right; ++i) {
        typename T::iterator next_i = i;
        ++next_i;
        if (next_i == right) break;
        typename T::value_type key = *next_i;
        typename T::iterator j = i;
        while (j != left && *j > key) {
            typename T::iterator next_j = j;
            ++next_j;
            *next_j = *j;
            --j;
        }
        typename T::iterator next_j = j;
        ++next_j;
        *next_j = key;
    }
}

template <typename T>
void PmergeMe::fordJohnsonSort(T &container, typename T::iterator left, typename T::iterator right) {
    if (std::distance(left, right) <= 1) {
        if (*left > *right)
            std::iter_swap(left, right);
        return;
    }

    typename T::iterator middle = left;
    std::advance(middle, std::distance(left, right) / 2);
    fordJohnsonSort(container, left, middle);
    typename T::iterator next_middle = middle;
    ++next_middle;
    fordJohnsonSort(container, next_middle, right);

    typename T::iterator next_middle_plus_one = next_middle;
    ++next_middle_plus_one;
    if (*middle <= *next_middle)
        return;

    merge(container, left, next_middle, next_middle_plus_one);
}

template <typename T>
void PmergeMe::fordJohnsonSort(T &container) {
    if (container.size() > 1) {
        typename T::iterator end = container.end();
        --end;
        fordJohnsonSort(container, container.begin(), end);
    }
}

template <typename T>
double PmergeMe::getTime(T &container) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    fordJohnsonSort(container);
    clock_gettime(CLOCK_MONOTONIC, &end);
    return (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e6;
}


template <typename T>
void PmergeMe::showTime(const T &container, double time, const std::string &type) {
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << container.size();
    std::cout << " elements with std::" << std::setw(5) << type << ": ";
    std::cout << GREEN << time << " us" << END << std::endl;
}


template <typename T>
void PmergeMe::printContainer(const T &container, const std::string &phase) {
    std::cout << phase;
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


