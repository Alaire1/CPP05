#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>


# define RED "\033[31m"
# define RESET "\033[0m"

template<typename T>
class Array {
private:
    T* _arr;
    unsigned int _size;

public:
    Array(); // Default constructor 
    Array(unsigned int size); // Constructor with size
    Array(const Array<T>& src); // Copy constructor
    Array& operator=(const Array<T>& src); // Assignment operator
    ~Array(); //Destructor

    T& operator[](size_t index) const;
    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#include "Array.tpp"

#endif