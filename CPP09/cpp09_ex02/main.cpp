#define _POSIX_C_SOURCE 200809L
#include <sys/time.h>
#include "DequeSort.hpp"
#include "VectorSort.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip> 
#include <limits>  

long getCurrentTimeNs() {
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
        std::cerr << "Error: clock_gettime() failed." << std::endl;
        return 0;
    }
    return static_cast<long>(ts.tv_sec) * 1000000000L + static_cast<long>(ts.tv_nsec);
}

double measureSort(VectorSort& sorter, char* argv[]) {
    long startTime = getCurrentTimeNs();
    sorter.mergeInsert(argv);
    long endTime = getCurrentTimeNs();
    return static_cast<double>(endTime - startTime) / 1000.0; 
}

double measureSortDeque(DequeSort& sorter, char* argv[]) {
    long startTime = getCurrentTimeNs();
    sorter.mergeInsert(argv);
    long endTime = getCurrentTimeNs();
    return static_cast<double>(endTime - startTime) / 1000.0;
}


void printResults(int count, double vectorTime, double dequeTime) {
    std::cout << std::endl;
    std::cout << "Time to process a range of " << count << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << vectorTime << " \u00B5s" << std::endl;
    std::cout << "Time to process a range of " << count << " elements with std::deque : " 
              << std::fixed << std::setprecision(5) << dequeTime << " \u00B5s" << std::endl;
}


void printSequences(const VectorSort& sorter) {
    std::cout << "Before: " << std::endl;
    sorter.printBefore();
    std::cout << "After: " << std::endl;
    sorter.printAfter();
}

void start(VectorSort& vectorSorter, DequeSort& dequeSorter, char* argv[], int argc) {
        double vectorTime = measureSort(vectorSorter, argv);
        double dequeTime = measureSortDeque(dequeSorter, argv);
        printSequences(vectorSorter);
        printResults(argc - 1, vectorTime, dequeTime);
}
bool validateAndConvert(const std::string& str, int& number) {
    if (str.empty()) {
        std::cerr << "Error: Empty input detected." << std::endl;
        return false;
    }
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
            std::cerr << "Error: Non-integer character '" << str[i] 
                      << "' detected in \"" << str << "\"." << std::endl;
            return false;
        }
    }
    char* endptr = NULL;
    long temp = std::strtol(str.c_str(), &endptr, 10);
    if (*endptr != '\0') {
        std::cerr << "Error: Invalid number \"" << str << "\"." << std::endl;
        return false;
    }
    if (temp < 0) {
        std::cerr << "Error: Negative number \"" << str 
                  << "\" detected. Only positive numbers are allowed." << std::endl;
        return false;
    }
    if (temp > static_cast<long>(std::numeric_limits<int>::max())) {
        std::cerr << "Error: Number \"" << str 
                  << "\" exceeds the maximum allowed value (" 
                  << std::numeric_limits<int>::max() << ")." << std::endl;
        return false;
    }
    number = static_cast<int>(temp);
    return true;
}

bool isAlreadySorted(const std::vector<int>& numbers) {
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i - 1] > numbers[i]) {
            return false;
        }
    }
    return true;
}
bool processInputs(int argc, char* argv[], std::vector<int>& numbers) {
    bool isValid = true;
    if (argc == 2) {
        std::cerr << "Error: Too litte integers to sort" << std::endl;
        return false;
    }
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        int num;

        if (validateAndConvert(arg, num)) {
            numbers.push_back(num);
        } else {
            isValid = false;
        }
    }
    if (!isValid) {
        std::cerr << "Input validation failed. Please provide only positive integers." << std::endl;
        return false;
    }
    if (isAlreadySorted(numbers)) {
        std::cout << "The input sequence is already sorted. No sorting needed." << std::endl;
        return false;
    }
    return true; 
}
int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "Usage: ./PmergeMe ...numbers" << std::endl;
        return 1;
    }
    try {
        VectorSort vectorSorter;
        DequeSort dequeSorter;
        std::vector<int> validatedNumbers;
        if (processInputs(argc, argv, validatedNumbers) == false)
            return 1;
        start(vectorSorter, dequeSorter, argv, argc);
    }
    catch (const VectorSort::Exception& e) { 
        std::cerr << "VectorSort Exception: " << e.what() << std::endl;
        return 1;
    }
    catch (const DequeSort::Exception& e) { 
        std::cerr << "DequeSort Exception: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) { 
        std::cerr << "Standard Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}