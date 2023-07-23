#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <float.h>

class BitcoinExchange {
    private:
        std::map<std::string, float> _bitcoinPrices;

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

    public:
        BitcoinExchange(const std::string& databaseFile);
        ~BitcoinExchange();

        bool isValidDate(std::string date);
        bool isValidPrice(std::string price);
        void processInputFile(const std::string& inputFile);
};

#endif