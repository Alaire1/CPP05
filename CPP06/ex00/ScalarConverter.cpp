#include "ScalarConverter.hpp"

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
void ScalarConverter::toChar(std::string str) {
	try {
		double d = std::strtod(str.c_str(), NULL);

		if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
			throw std::invalid_argument("conversion impossible");
		if (std::isnan(d) || std::isinf(d))
			throw std::invalid_argument("conversion impossible");
		if (!std::isprint(static_cast<char>(d)))
			throw std::invalid_argument("Non displayable");
		std::cout << "\033[35mchar: " << static_cast<char>(d) << "\033[0m" << std::endl;
	} catch (std::exception &e) {
		std::cout << "\033[31mchar: " << e.what() << "\033[0m" << std::endl;
	}
}

void ScalarConverter::toInt(std::string str) {
	try {
		double num = std::strtod(str.c_str(), NULL);

		if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
			throw std::invalid_argument("conversion impossible");
		if (std::isnan(num) || std::isinf(num))
			throw std::invalid_argument("conversion impossible");
		std::cout << "\033[32mint: " << static_cast<int>(num) << "\033[0m" << std::endl;
	} catch (std::exception &e) {
		std::cout << "\033[31mint: " << e.what() << "\033[0m" << std::endl;
	}
}

int getPrecision(const std::string& str) {
    size_t dotPos = str.find('.');
    if (dotPos == std::string::npos) {
        return 0;
    }
    size_t endPos = str.size();
    if (str[endPos - 1] == 'f') {
        endPos--;
    }
    int precision = endPos - dotPos - 1;
    return precision;
}

void ScalarConverter::toFloat(std::string str) {
    try {
		int precision = getPrecision(str);
        float f = std::strtof(str.c_str(), NULL);

        if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
            throw std::invalid_argument("conversion impossible");
        if (std::isnan(f) || std::isinf(f))
            throw std::invalid_argument("nanf");

        std::cout << "\033[33mfloat: ";
        std::cout << std::fixed << std::setprecision(precision);
		std::cout << static_cast<float>(f) << "f\033[0m" << std::endl;
    } catch (std::exception &e) {
        std::cout << "\033[31mfloat: " << e.what() << "\033[0m" << std::endl;
    }
}

void ScalarConverter::toDouble(std::string str) {
	try {
		int precision = getPrecision(str);
		double d = std::strtod(str.c_str(), NULL);
		if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max())
			throw std::invalid_argument("conversion impossible");
		if (std::isnan(d) || std::isinf(d))
			throw std::invalid_argument("nan");

		std::cout << "\033[34mdouble: ";
		std::cout << std::fixed << std::setprecision(precision);
		std::cout << static_cast<double>(d) << "\033[0m" <<  std::endl;
	} catch (std::exception &e) {
		std::cout << "\033[31mdouble: " << e.what() << "\033[0m" << std::endl;
	}
}

void ScalarConverter::convert(std::string str)
{
    ScalarConverter converter;

    converter.toChar(str);
    converter.toInt(str);
    converter.toFloat(str);
    converter.toDouble(str);
}