#include "Harl.hpp"

void Harl::complain( std::string level ) {
    void (Harl::*complaints[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i = -1;
    while (++i < 4)
        if (level == levels[i])
            break;

    switch (i) {
        case 0:
            (this->*complaints[0])();
            break ;
        case 1:
            (this->*complaints[1])();
            break ;
        case 2:
            (this->*complaints[2])();
            break ;
        case 3:
            (this->*complaints[3])();
            break ;
        default:
            std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
    };

}

void Harl::debug( void ) {
    std::cout << "[ DEBUG ]";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "[ INFO ]";
    std::cout << "I cannot believe adding extra bacon costs more money.";
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[ WARNING ]";
    std::cout << "I think I deserve to have some extra bacon for free.";
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ ERROR ]";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}