#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name)
{
    *this = src;
}

Bureaucrat::~Bureaucrat() {}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade;
    return *this;
}

std::string const & Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low.";
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return out;
}