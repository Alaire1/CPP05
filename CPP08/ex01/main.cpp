#include <iostream>
#include <vector>
#include <ctime> // Include ctime for std::srand and std::rand
#include "Span.hpp"


// Function to print the contents of the Span
void printSpan(const Span &span) {
    try {
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest  span: " << span.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "\033[1;31mError: " << e.what() << RESET << std::endl;
    }
}

// Function to print the numbers in a vector
void printVector(const std::vector<int> &vec) {
    std::cout << "Numbers in the vector: ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testEmptySpan() {
    std::cout << YELLOW "testEmptySpan" RESET << std::endl;

    Span sp(0);
    try {
        sp.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << "\033[1;31mExpected exception: " << e.what() << RESET << std::endl;
    }

    try {
        sp.longestSpan();
    } catch (const std::exception &e) {
        std::cout << "\033[1;31mExpected exception: " << e.what() << RESET << std::endl;
    }
}

void testContainerFullException() {
    std::cout << YELLOW "testContainerFullException" RESET << std::endl;

    Span sp(5);
    try {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);
        sp.addNumber(6); // This should throw the ContainerFull exception
    } catch (const Span::ContainerFull &e) {
        std::cout << "\033[1;31mExpected exception: " << e.what() << RESET << std::endl;
    }
}

void testSingleElement() {
    std::cout << YELLOW "testSingleElement" RESET << std::endl;

    Span sp(1);
    sp.addNumber(42);

    try {
        sp.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << "\033[1;31mExpected exception: " << e.what() << RESET << std::endl;
    }

    try {
        sp.longestSpan();
    } catch (const std::exception &e) {
        std::cout << "\033[1;31mExpected exception: " << e.what() << RESET << std::endl;
    }
}

void testTwoElements() {
    std::cout << YELLOW "testTwoElements" RESET << std::endl;

    Span sp(2);
    sp.addNumber(1);
    sp.addNumber(100);

    printSpan(sp);
}

void testMultipleElements() {
    std::cout << YELLOW "testMultipleElements" RESET << std::endl;

    Span sp(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    printSpan(sp);
}

void testLargeNumberOfElements() {
    std::cout << YELLOW "testLargeNumberOfElements" RESET << std::endl;

    Span sp(10000);
    std::vector<int> range;
    range.reserve(10000);

    std::srand(::time(NULL));

    for (int i = 0; i < 10000; ++i) {
        range.push_back(std::rand());
    }

    sp.addRange(range.begin(), range.end());
    //printVector(range);
    printSpan(sp);
}

void testSmallRangeOfElements() {
    std::cout << YELLOW "testSmallRangeOfElements" RESET << std::endl;

    Span sp(10);
    std::vector<int> range;
    range.reserve(10);

    std::srand(::time(NULL));

    for (int i = 0; i < 10; ++i) {
        range.push_back(std::rand() % 100); // Small range of integers (0-99)
    }

    printVector(range);

    sp.addRange(range.begin(), range.end());
    printSpan(sp);
}

void testDuplicateElements() {
    std::cout << YELLOW "testDuplicateElements" RESET << std::endl;

    Span sp(5);
    sp.addNumber(42);
    sp.addNumber(42);
    sp.addNumber(42);
    sp.addNumber(42);
    sp.addNumber(42);

    printSpan(sp);
}

int main() {

    testEmptySpan();
    testContainerFullException();
    testSingleElement();
    testTwoElements();
    testMultipleElements();
    testLargeNumberOfElements();
    testSmallRangeOfElements();
    testDuplicateElements();
    return 0;
}