#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <list of integers>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        int num;
        std::istringstream iss(argv[i]);
        if (!(iss >> num)) {
            std::cerr << "Invalid number: " << argv[i] << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    try {
        std::cout << "Sorting std::vector:" << std::endl;
        printContainer(vec, "before");
        sortContainer(vec, vec.size());
        printContainer(vec, "after");

        std::cout << "Sorting std::deque:" << std::endl;
        sortContainer(deq, deq.size());
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}