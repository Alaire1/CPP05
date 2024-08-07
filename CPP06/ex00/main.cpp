#include "scalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return 1;
    }
    scalarConverter sc(av[1]);
    
    return 0;
}