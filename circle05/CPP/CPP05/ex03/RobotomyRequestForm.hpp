#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

        virtual void execute(Bureaucrat const & executor) const;
        std::string const & getTarget() const;
};

#endif