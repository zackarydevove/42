#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) 
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
    : AForm(src), _target(src._target) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);

    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomization of " << _target << " has failed." << std::endl;
}

std::string const & RobotomyRequestForm::getTarget() const
{
    return this->_target;
}