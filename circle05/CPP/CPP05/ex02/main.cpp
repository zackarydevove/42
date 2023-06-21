#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try 
    {
        Bureaucrat john("John", 1);
        Bureaucrat mike("Mike", 150);

        ShrubberyCreationForm shrubForm("Home");
        RobotomyRequestForm robotForm("Robot");
        PresidentialPardonForm pardonForm("Criminal");

        std::cout << john << std::endl;
        std::cout << mike << std::endl;

        john.signForm(shrubForm);
        john.executeForm(shrubForm);

        mike.signForm(robotForm);
        mike.executeForm(robotForm);

        john.signForm(pardonForm);
        john.executeForm(pardonForm);
    } 
    catch (std::exception & e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}