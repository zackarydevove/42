#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &);
    ~ScalarConverter();
    ScalarConverter &operator=(ScalarConverter const &);

    static void convert(std::string const &input);
};

#endif