#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
#include <string>
#include <iomanip>

#include <stdio.h>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    return(*this);
}
ScalarConverter::~ScalarConverter() {}

void displayChar(int integerNumber) {
    if (integerNumber < 0 || integerNumber > 127) {
        std::cout << RED << "char: impossible" << RESET << std::endl;
    } else if ((integerNumber >= 0 && integerNumber <= 31) || integerNumber == 127) {
         std::cout << YELLOW << "char: " << RESET <<  "non displayable" << std::endl;
    } else {
        std::cout << YELLOW << "char: " << RESET << "'" << static_cast<char>(integerNumber) << "'" << std::endl;
    }
}

void displayInt(bool isIntPossible, int integerNumber) {
    if (isIntPossible)
        std::cout << BLUE << "int: " << RESET << integerNumber << std::endl;
    else
        std::cout << RED << "int: impossible" << RESET << std::endl;
}

void displayFloat(float floatNumber) {
    std::cout << MAGENTA << "float: " << RESET << std::fixed << std::setprecision(1) << floatNumber << "f" << std::endl;
}

void displayDouble(double doubleNumber) {
    std::cout << GREEN << "double: " << RESET << std::fixed << std::setprecision(1) << doubleNumber << std::endl;
}

void printConverted(bool isIntPossible, int integerNumber, float floatNumber, double doubleNumber) 
{
    displayChar(integerNumber);
    displayInt(isIntPossible, integerNumber);
    displayFloat(floatNumber);
    displayDouble(doubleNumber);
}

void    handleDouble(double doubleVal)
{
    float floatVal = static_cast<float>(doubleVal);
    int intVal = static_cast<int>(doubleVal);
    printConverted( 1, intVal, floatVal, doubleVal);
}

void    handleFloat(float floatVal)
{
    double doubleVal = static_cast<double>(floatVal);
    int intVal = static_cast<int>(floatVal);
    printConverted(1, intVal, floatVal, doubleVal);
}

void    handleInt(int intVal)
{
    float floatVal = static_cast<float>(intVal);
    double doubleVal = static_cast<double>(intVal);
    printConverted(1, intVal, floatVal, doubleVal);

}

void    handlePseudo(std::string input)
{
    float floatVal = static_cast<float>(atof(input.c_str()));
    double doubleVal = static_cast<double>(floatVal);
    int intVal = static_cast<int>(floatVal);
    printConverted(0, intVal, floatVal, doubleVal);
}

void    handleChar(char charVal)
{
    int intVal = static_cast<int>(charVal);
    float floatVal = static_cast<float>(charVal);
    double doubleVal = static_cast<double>(charVal);
    printConverted(1, intVal, floatVal, doubleVal);
}


bool isChar(const std::string &input) {
    if (input.length() == 1 && !isdigit(input.at(0)))
        return true;
    return false;
}

bool isPseudoLiteral(const std::string &input) {
    if (input == "-inf" || input == "+inf" || input == "inf" || input == "inf" || input == "nan" || 
           input == "-inff" || input == "+inff" || input == "nanf" || input == "inff")  
        return true;
    return false;
}

bool containsInvalidCharacters(const std::string &input) {
      for(size_t i = 0; i < input.length(); i++)
    {
        if (!isdigit(input.at(i)) && input.at(i) != '.' && input.at(i) != 'f' && input.at(i) != '-' && input.at(i) != '+')
                return true;
        else if (i != 0 && (input[i] == '+' || input[i] == '-'))
                return true;
    }
    return false;
}
void    ScalarConverter::convert(std::string const &input)
{
    if (isChar(input)) {
        handleChar(input.at(0));
        return;
    }
    if (isPseudoLiteral(input)) {
        handlePseudo(input);
        return;
    }
    if (containsInvalidCharacters(input)) {
        std::cerr << RED << "Error: Invalid Input" << RESET << std::endl;
        return;
    }
    if (input.find('.') != std::string::npos)
    {
        if (input.find_first_of('.') != input.find_last_of('.') || input.find_first_of('f') != input.find_last_of('f'))
            {
                std::cerr << RED << "Error: Invalid Input" << RESET << std::endl;
                return;
           }
        if (input.find('f') == input.length() - 1)
            {
                handleFloat(atof(input.c_str()));
                return;
            }
        if (input.find('f') != std::string::npos)
           {
                std::cerr << RED << "Error: Invalid Input" << RESET << std::endl;
                return;
           }
        handleDouble(atof(input.c_str()));
        return;
    }
    if (input.find('f') != std::string::npos)
        {
                std::cerr << RED << "Error: Invalid Input" << RESET << std::endl;
                return;
        }
    long tmp = atol(input.c_str());
    if (tmp > std::numeric_limits<int>::max() ||  tmp < std::numeric_limits<int>::min())
       {
            handleDouble(atof(input.c_str()));
            return;
       }
   handleInt(atoi(input.c_str()));
    
}
