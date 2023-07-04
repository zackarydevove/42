#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        // Bureaucrat Dim("Dim", 151); // too low
        // Bureaucrat Kim("Kim", 0); // too high

        Bureaucrat jim("Jim", 150);
        std::cout << jim << std::endl; // 150

        jim.incrementGrade();
        std::cout << jim << std::endl;  // 150 - 1 = 148

        jim.decrementGrade();   // 149 + 1 = 150
        std::cout << jim << std::endl;

        Bureaucrat tim("Tim", 1);
        std::cout << tim << std::endl;  // 1

        tim.decrementGrade();   // 1 + 1 = 2
        std::cout << tim << std::endl;

        tim.incrementGrade();   // 1 - 1 = 1
        std::cout << tim << std::endl;

        tim.incrementGrade();   // 1 - 1 = 0 (too hight)
        std::cout << tim << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}