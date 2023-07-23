#include "BitcoinExchange.hpp"

int main(int ac, char** av) 
{
    if (ac != 2) {
        std::cout << "Error: Missing argument.\nUsage: ./btc input.txt" << std::endl;
        return 1;
    }

    std::string inputFile = av[1];

    try {
        BitcoinExchange bitcoinExchange("data.csv");
        bitcoinExchange.processInputFile(inputFile);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}