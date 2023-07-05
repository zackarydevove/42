#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const & src) {
    *this = src;
}

Intern & Intern::operator=(Intern const & rhs) {
    (void)rhs;
    return *this;
}

AForm * Intern::makeForm(std::string const & formName, std::string const & target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int i = 0;
    while (i < 3 && formNames[i] != formName)
        i++;

    switch (i)
    {
        case 0:
                return (new ShrubberyCreationForm(target));
        case 1:
                return (new RobotomyRequestForm(target));
        case 2:
                return (new PresidentialPardonForm(target));
        default:
            break ;
    }

    std::cout << "Invalid form request" << std::endl;
    return NULL;
}