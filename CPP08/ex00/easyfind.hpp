#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <string>

#include <iterator>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
    {
        std::string error = RED + std::string("Value not found") + RESET;
        throw std::out_of_range(error);
    }
	return (it);
}

#endif 
