#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void baseTest() {
    Span sp = Span(5);
    std::cout << "Adding 5" << std::endl;
    sp.addNumber(5);
    std::cout << "Adding 3" << std::endl;
    sp.addNumber(3);
    std::cout << "Adding 17" << std::endl;
    sp.addNumber(17);
    std::cout << "Adding 9" << std::endl;
    sp.addNumber(9);
    std::cout << "Adding 11" << std::endl;
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

// void (const Span &sp) {
//     const std::vector<int> &vec = sp.getVector();
//     for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }

void addRangeTest() {
    Span sp = Span(45);
    try {
        std::cout << "Adding range 0-10" << std::endl;
        sp.addRange(0, 10);
        std::cout << "Adding range 5-5" << std::endl;
        sp.addRange(5, 5);
        std::cout << "Adding range 5-44" << std::endl;
        sp.addRange(5, 44);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void test10000() {
    Span sp = Span(10000);
    srand(time(0));
    try {
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(rand() % 10000);
        }
        std::cout << "Added 10,000 random numbers." << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
void testLarge() {
    Span sp = Span(100000);
    srand(time(0));
    try {
        for (int i = 0; i < 100000; ++i) {
            sp.addNumber(rand() % 100000);
        }
        std::cout << "Added 100,000 random numbers." << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
void edgeCaseTest() {
    Span sp = Span(2);
    try {
        sp.addNumber(1);
        sp.addNumber(100);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Span sp2 = Span(1);
    try {
        sp2.addNumber(1);
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl; // Should throw an exception
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Base Test:" << std::endl;
    baseTest();
    std::cout << std::endl;

    std::cout << "Add Range Test:" << std::endl;
    addRangeTest();
    std::cout << std::endl;

    std::cout << "Large Test (10,000 numbers):" << std::endl;
    test10000();
    std::cout << std::endl;

    std::cout << "Large Test (100,000 numbers):" << std::endl;
    testLarge();
    std::cout << std::endl;

    std::cout << "Edge Case Test:" << std::endl;
    edgeCaseTest();
    std::cout << std::endl;

    return 0;
}