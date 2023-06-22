#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    std::ifstream inFile(filename.c_str());
    if(!inFile)
        throw std::runtime_error("Unable to open bitcoin database file");
    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string date;
        float value;
        if (std::getline(ss, date, ',') && ss >> value)
            _bitcoinPrices[date] = value;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
    : _bitcoinPrices(other._bitcoinPrices) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _bitcoinPrices = other._bitcoinPrices;
    return *this;
}

BitcoinExchange::~BitcoinExchange() { }

float BitcoinExchange::getBitcoinValueOnDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _bitcoinPrices.upper_bound(date);
    if (it == _bitcoinPrices.begin())
        throw std::runtime_error("Date is too early, no data available");
    --it;
    return it->second;
}