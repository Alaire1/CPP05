#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span() : _N(0), _size(0) {}

Span::Span(unsigned int N) : _N(N), _size(0) {
	_vector.reserve(N);
}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		_N = rhs._N;
		_size = rhs._size;
		_vector = rhs._vector;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_size >= _N)
		throw std::out_of_range("\033[1;31mSpan has no room\033[0m");
	_vector.push_back(n);
	_size++;
}

void Span::addRange(int start, unsigned int count) {
    if (_size + count > _N)
        throw std::range_error("\033[1;31mRange exceeds the limit\033[0m");
    for (unsigned int i = 0; i < count; i++)
		_vector.push_back(start + i);
    _size += count;
}

int Span::shortestSpan(void) {
    if (_size < 1)
        throw std::range_error("\033[1;31mSpan is empty\033[0m");
	else if (_size == 1)
		throw std::range_error("\033[1;31mSpan has only one element\033[0m");
    std::vector<int> sortedVector = _vector;
    std::sort(sortedVector.begin(), sortedVector.end());

    int shortest = sortedVector[1] - sortedVector[0];
    for (unsigned int i = 1; i < _size - 1; ++i) {
        int diff = sortedVector[i + 1] - sortedVector[i];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

int Span::longestSpan(void) {
	if (_size < 1)
		throw std::range_error("\033[1;31mSpan is empty or has only one element\033[0m");
	else if (_size == 1)
		throw std::range_error("\033[1;31mSpan has only one element\033[0m");
	std::sort(_vector.begin(), _vector.end());
	return _vector[_size - 1] - _vector[0];
}
