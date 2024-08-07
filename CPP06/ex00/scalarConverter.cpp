
void ScalarConverter::toFloat()
{
    std::cout << "float: ";
    try
    {
        float f = std::stof(_str);
        std::cout << f;
        if (f - static_cast<int>(f) == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "impossible" << std::endl;
    }
}

void ScalarConverter::toInt()
{
    std::cout << "int: ";
    try
    {
        int i = std::stoi(_str);
        std::cout << i << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "impossible" << std::endl;
    }
}

void ScalarConverter::toDouble()
{
    std::cout << "double: ";
    try
    {
        double d = std::stod(_str);
        std::cout << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "impossible" << std::endl;
    }
}

void ScalarConverter::toChar()
{
    std::cout << "char: ";
    try
    {
        char c = static_cast<char>(std::stoi(_str));
        if (c < 32 || c > 126)
            throw std::exception();
        std::cout << "'" << c << "'" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Non displayable" << std::endl;
    }
}

void ScalarConverter::convert(std::string str)
{
    ScalarConverter string(str);

    string.toChar();
    string.toInt();
    string.toFloat();
    string.toDouble();
}