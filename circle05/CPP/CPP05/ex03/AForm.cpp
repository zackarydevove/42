#include "AForm.hpp"
#include <iostream>

AForm::AForm(std::string const & name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(AForm const & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    *this = src;
}

AForm & AForm::operator=(AForm const & rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

std::string const & AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    else
        this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade too low.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed.";
}

std::ostream & operator<<(std::ostream & o, AForm const & i)
{
    o << i.getName() << ", Aform grade to sign " << i.getGradeToSign() << ", grade to execute " << i.getGradeToExecute() << ", is signed " << (i.getIsSigned() ? "Yes" : "No");
    return o;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
}
