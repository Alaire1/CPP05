#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter &operator=(ScalarConverter const &copy);
        ~ScalarConverter();
        void   toInt(std::string str);
        void   toFloat(std::string str);
        void   toDouble(std::string str);
        void   toChar(std::string str);
    public:
        static void convert(std::string str);
   
};

#endif
