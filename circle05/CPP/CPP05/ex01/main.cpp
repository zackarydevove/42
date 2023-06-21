#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat jim("Jim", 150);
        std::cout << jim << std::endl;
        Form form1("Form1", 149, 149);
        std::cout << form1 << std::endl;
        jim.signForm(form1);
        std::cout << form1 << std::endl;

        Bureaucrat tim("Tim", 1);
        std::cout << tim << std::endl;
        Form form2("Form2", 1, 1);
        std::cout << form2 << std::endl;
        tim.signForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}