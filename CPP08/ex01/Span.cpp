#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int size) : _N(size) {
    _numbers.reserve(size);
}

Span::~Span() {}

Span::Span(const Span &obj) : _N(obj._N), _numbers(obj._numbers) {}

Span &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        _N = rhs._N;
        _numbers = rhs._numbers;
    }
    return *this;
}

int Span::operator[](unsigned int pos) const {
    return _numbers.at(pos);
}

const char* Span::ContainerFull::what() const throw() {
    return "Container is full";
}

const char* Span::TooLittleNumbers::what() const throw() {
    return "Zero or one number inside the container";
}

void Span::addNumber(int number) {
    if (_numbers.size() < _N) {
        _numbers.push_back(number);
    } else {
        throw ContainerFull();
    }
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) + _numbers.size() > _N) {
        throw ContainerFull();
    }
    _numbers.insert(_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw TooLittleNumbers();
    }
    std::vector<int> sorted_numbers(_numbers);
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    unsigned int shortest_span = std::numeric_limits<unsigned int>::max();
    for (size_t i = 0; i < sorted_numbers.size() - 1; ++i) {
        unsigned int span = sorted_numbers[i + 1] - sorted_numbers[i];
        if (span < shortest_span) {
            shortest_span = span;
        }
    }
    return shortest_span;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw TooLittleNumbers();
    }
    std::vector<int>::const_iterator lowest = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator highest = std::max_element(_numbers.begin(), _numbers.end());

    return *highest - *lowest;
}