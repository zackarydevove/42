#ifndef AFORM_H
#define AFORM_H

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        AForm();
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm(std::string const & name, int gradeToSign, int gradeToExecute);
        AForm(AForm const & src);
        virtual ~AForm();
        AForm & operator=(AForm const & rhs);

        std::string const & getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat const & bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & out, AForm const & src);

#endif