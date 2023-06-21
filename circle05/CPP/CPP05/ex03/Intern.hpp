#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
public:
    Intern();
    ~Intern();
    Intern(Intern const & src);
    Intern & operator=(Intern const & rhs);

    AForm * makeForm(std::string const & formName, std::string const & target);
};

#endif