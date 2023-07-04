#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : 
    _name("default"),
    _isSigned(false),
    _gradeToSign(150), 
    _gradeToExecute(150) {}

Form::Form(std::string const & name, int gradeToSign, int gradeToExecute) :
    _name(name),
    _isSigned(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(Form const & src) : 
    _name(src._name),
    _isSigned(src._isSigned),
    _gradeToSign(src._gradeToSign),
    _gradeToExecute(src._gradeToExecute) {}

Form & Form::operator=(Form const & rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

std::string const & Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    else
        this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low.";
}

std::ostream & operator<<(std::ostream & out, Form const & src)
{
    out << src.getName() << ", form grade to sign " << src.getGradeToSign() << ", grade to execute " << src.getGradeToExecute() << ", is signed " << (src.getIsSigned() ? "Yes" : "No");
    return out;
}