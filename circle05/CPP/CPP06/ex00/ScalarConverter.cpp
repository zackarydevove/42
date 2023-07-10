#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &) {
    return *this;
}

void ScalarConverter::convert(const std::string& str) {
    std::stringstream ss(str);
    if (str == "nan" || str == "inf" || str == "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (str == "nan") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else {
            std::cout << "float: " << std::strtof(str.c_str(), NULL) << "f" << std::endl;
            std::cout << "double: " << std::strtod(str.c_str(), NULL) << std::endl;
        }
    }
    // CHAR
    else if (isChar(str)) {
        char c = str[0];
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
    }
    // INT
    else if (isInt(str)) {
        long i = std::atol(str.c_str());
        if (i < 0 || i > 126)
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(i))
            std::cout << "char: '" << i << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(i) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i) << std::endl;
    }
    // FLOAT
    else if (isFloat(str)) {
        float f = std::strtof(str.c_str(), NULL);
        if (f < 0 || f > 126 || std::isnan(f) || std::isinf(f))
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(static_cast<int>(f)))
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (f < INT_MIN || f > INT_MAX || std::isnan(f) || std::isinf(f))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
    }
    // DOUBLE
    else if (isDouble(str)) {
        double d = std::strtod(str.c_str(), NULL);
        if (d < 0 || d > 126 || std::isnan(d) || std::isinf(d))
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(static_cast<int>(d)))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (d < INT_MIN || d > INT_MAX || std::isnan(d) || std::isinf(d))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
    }
    else {
        std::cout << "Invalid input" << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& str) {
    return str.length() == 1 && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt(const std::string& str) {
    std::istringstream iss(str);
    int i;
    iss >> i;
    return iss.eof() && !iss.fail();
}

bool ScalarConverter::isFloat(const std::string& str) {
    std::size_t found = str.find("f");
    if (found != std::string::npos) {
        std::istringstream iss(str.substr(0, found));
        float f;
        iss >> f;
        return iss.eof() && !iss.fail();
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string& str) {
    std::istringstream iss(str);
    double d;
    iss >> d;
    return iss.eof() && !iss.fail();
}