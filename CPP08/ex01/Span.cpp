#include "Span.hpp"

void Span::addNumber(int number) {
	if (_numbers.size() < _size) {
		_numbers.push_back(number);
	} else {
		throw IsFullException();
	}
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}
	std::vector<int> sorted_numbers(_numbers);
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	unsigned int shortest_span = std::numeric_limits<int>::max();
	for (size_t i = 0; i < _numbers.size(); i++) {
		if (static_cast<unsigned int>(sorted_numbers[i + 1] - sorted_numbers[i]) < shortest_span) {
			shortest_span = sorted_numbers[i + 1] - sorted_numbers[i];
		}
	}
	return shortest_span;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}
	std::vector<int>::const_iterator lowest = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator highest = std::max_element(_numbers.begin(), _numbers.end());

	return (*highest - *lowest);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) + _numbers.size() > _size) {
		throw IsFullException();
	}
	_numbers.insert(_numbers.end(), begin, end);
}


Span::Span() :
		_size(0) {}

Span::Span(unsigned int size) :
		_size(size) {
	_numbers.reserve(size);
}

Span::~Span() {}


Span::Span(const Span &other) :
		_size(other._size),
		_numbers(other._numbers) {}



Span Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		_size = rhs._size;
		_numbers = rhs._numbers;
	}
	return *this;
}

int Span::operator[](unsigned int pos) {
	return (_numbers.at(pos));
}

const char *Span::IsFullException::what() const throw() {
	return "Container is full.";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
	return "Only one or zero values in container.";
}