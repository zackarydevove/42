#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) 
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
    : AForm(src), _target(src._target) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string const & PresidentialPardonForm::getTarget() const
{
    return this->_target;
}