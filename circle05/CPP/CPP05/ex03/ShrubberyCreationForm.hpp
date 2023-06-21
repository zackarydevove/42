#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(std::string const & target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

        virtual void execute(Bureaucrat const & executor) const;
        std::string const & getTarget() const;
};

#endif