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
    AForm *formFuncs[3] = {
		new ShrubberyCreationForm(target), 
		new RobotomyRequestForm(target), 
		new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (formFuncs[i]);
        }
        else
            delete formFuncs[i];
    }

    std::cout << "Invalid form request" << std::endl;
    return NULL;
}