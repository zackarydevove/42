#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

int main(int ac, char **av) 
{
	if (ac == 3)
	{
        try {
            BitcoinExchange btc(av[1]);
            std::cout << "The value of bitcoin on " << av[2] << " was: ";
            std::cout << btc.getBitcoinValueOnDate(av[2]) << std::endl;
        }
        catch (const std::exception &e){
            std::cerr << e.what() << std::endl;
        }
    }
    else
		std::cout << "Usage: ./ex00 <input file> <date to check>" << std::endl;
	return 0;
}