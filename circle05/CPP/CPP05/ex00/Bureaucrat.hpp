#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <exception>

class Bureaucrat
{
    private:
	    Bureaucrat();
        const std::string _name;
        int _grade;

    public:
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat();
        Bureaucrat & operator=(Bureaucrat const & rhs);

        std::string const & getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

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
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src);

#endif