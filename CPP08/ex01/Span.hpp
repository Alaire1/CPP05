#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <ostream>
#include <iostream>

class Span {
	private:
		unsigned int _N;
		unsigned int _size;
		std::vector<int> _vector;

	public:
		Span(); // default constructor
		Span(unsigned int N); // parameterized constructor
		Span(Span const &src); // copy constructor
		~Span(); // destructor
		Span &operator=(Span const &rhs); // assignation operator

		void addNumber(int n);
		void addRange(int start, unsigned int count);

		int shortestSpan(void);
		int longestSpan(void);

		
};
#endif
