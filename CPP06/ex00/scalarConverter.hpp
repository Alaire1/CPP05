#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class scalarConverter
{
    private:
        ScalarConverter();
        ScalaraConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &src);
        ~ScalarConverter();
        void   _toInt();
        void   _toFloat();
        void   _toDouble();
        void   _toChar();
    public:
        static void convert(std::string const &input);
};

#endif