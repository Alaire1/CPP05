#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

class Span {
private:
    unsigned int _N;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int size);
    Span(const Span &obj);
    ~Span();

    Span &operator=(const Span &rhs);

    int operator[](unsigned int pos) const;

    void addNumber(int number);
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class ContainerFull : public std::exception {
    public:
        const char* what() const throw();
    };

    class TooLittleNumbers : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif

