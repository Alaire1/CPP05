#include "Array.hpp"

template<typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int size) : _arr(new T[size]()), _size(size) {}

template<typename T>
Array<T>::Array(const Array<T>& src) : _arr(NULL), _size(0) {
    *this = src;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& src) {
    if (this != &src) {
        delete[] _arr;
        _size = src._size;
        _arr = new T[_size]();
        for (unsigned int i = 0; i < _size; ++i) {
            _arr[i] = src._arr[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] _arr;
}

template<typename T>
T& Array<T>::operator[](size_t index) const {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _arr[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    static std::string errorMsg = std::string(RED) + "Error: Index out of bounds" + RESET;
    return errorMsg.c_str();
}