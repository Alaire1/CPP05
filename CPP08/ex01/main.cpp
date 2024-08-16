#include "Span.hpp"


void baseTest() {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void addRangeTest() {
    Span sp = Span(10);
    try {
        sp.addRange(0, 10);
        sp.addRange(5, 5);
        sp.addRange(10, 5);
        sp.addRange(15, 5);
        sp.addRange(20, 5);
        sp.addRange(25, 5);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
   

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

int main() {
    baseTest();
    addRangeTest();
    return 0;
}