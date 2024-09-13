#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>
#include <vector>

class Span {
public:
	Span(unsigned int size);
	Span(const Span &other);
	~Span();

	Span operator=(const Span &rhs);
	int operator[](unsigned int pos);

	void addNumber(int number);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	class IsFullException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class NotEnoughNumbersException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	unsigned int _size;
	std::vector<int> _numbers;

	Span();
};

#endif 