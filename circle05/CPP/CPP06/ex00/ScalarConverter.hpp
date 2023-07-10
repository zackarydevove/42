#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <limits>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <climits>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &);
    ~ScalarConverter();
    ScalarConverter &operator=(ScalarConverter const &);

    static void convert(std::string const &input);

    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);

};

#endif