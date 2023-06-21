#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat jim("Jim", 150);
        std::cout << jim << std::endl;

        jim.incrementGrade();
        std::cout << jim << std::endl;

        jim.decrementGrade();
        std::cout << jim << std::endl;

        Bureaucrat tim("Tim", 1);
        std::cout << tim << std::endl;

        tim.decrementGrade();
        std::cout << tim << std::endl;

        tim.incrementGrade();
        std::cout << tim << std::endl;

        tim.incrementGrade();
        std::cout << tim << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}