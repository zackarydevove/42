#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm();
        std::string _target;

    public:
        PresidentialPardonForm(std::string const & target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

        virtual void execute(Bureaucrat const & executor) const;
        std::string const & getTarget() const;
};

#endif