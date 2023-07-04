#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &) {
    return *this;
}

void ScalarConverter::convert(std::string const &input)
{
    char *endptr = NULL;

    // CHAR
    long int num = std::strtol(input.c_str(), &endptr, 10);
    char c = num;
    if (endptr == &input[0] + input.length() && num >= 0 && num <= 127 && std::isprint(c))
        std::cout << "char: " << '\'' << c << '\'' << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    // INT
    long int nb = std::strtol(input.c_str(), &endptr, 10);
    if (!input.empty() && endptr == &input[0] + input.length() && nb >= -2147483648 && nb <= 2147483647)
        std::cout << "int: " << nb << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // FLOAT
    float f = std::strtof(input.c_str(), &endptr);
    if(*endptr == '\0' && !input.empty())
    {
        std::cout << "float: ";
        if (std::isnan(f) || input == "nanf")
            std::cout << "nanf" << std::endl;
        else if (std::isinf(f))
            std::cout << (f < 0 ? "-inff" : "+inff") << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;

    // DOUBLE
    double d = std::strtod(input.c_str(), &endptr);
    if(*endptr == '\0' && !input.empty())
    {
        std::cout << "double: ";
        if (std::isnan(d))
            std::cout << "nan" << std::endl;
        else if (std::isinf(d))
            std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
        else
            std::cout << d << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
}