#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class scalarConverter
{
    private:
        static void convert(std::string const &input);
        std::string _str;
    public:
        ScalarConverter();
        ScalaraConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &src);
        ~ScalarConverter();
        void   _toInt();
        void   _toFloat();
        void   _toDouble();
        void   _toChar()    
   
};

#endif