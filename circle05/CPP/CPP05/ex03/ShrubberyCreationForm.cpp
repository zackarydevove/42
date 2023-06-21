#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);

    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
        throw std::runtime_error("Failed to open the file for writing");
    else {
        ofs << "ASCII trees" << std::endl;
        ofs.close();
    }
}

std::string const & ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}