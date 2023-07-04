#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    try 
    {
        Bureaucrat john("John", 1);
        Intern mike;
        AForm *form;

        form = mike.makeForm("presidential pardon", "Tom");
        john.signForm(*form);
        john.executeForm(*form);
        delete form;

        form = mike.makeForm(" yes", "tom");
    } 
    catch (std::exception & e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}