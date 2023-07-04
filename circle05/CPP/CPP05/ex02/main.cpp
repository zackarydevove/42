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
        Bureaucrat zack("Zack", 72);

        ShrubberyCreationForm shrubForm("Shrub"); // sign 145 exec 137
        RobotomyRequestForm robotForm("Robot"); // sign 72 exec 45
        PresidentialPardonForm pardonForm("Criminal"); // sign 25 exec 5

        std::cout << john << std::endl;
        std::cout << mike << std::endl;

        john.executeForm(shrubForm); // 1 < 137     good but not signed
        john.signForm(shrubForm); // 1 < 145        good
        john.executeForm(shrubForm); // 1 < 137     good

        mike.signForm(robotForm); // 150 > 72       grade too low
        mike.executeForm(robotForm); // 150 > 45    grade too low

        john.signForm(pardonForm); // 1 < 25        good
        john.executeForm(pardonForm); // 1 < 5      good

        zack.signForm(robotForm); // 72 = 72        good
        zack.executeForm(robotForm); // 72 > 45     grade too low

        john.signForm(robotForm); // 1 < 145        good
        john.executeForm(robotForm); // 1 < 137     good
    } 
    catch (std::exception & e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}