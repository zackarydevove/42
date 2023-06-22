#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, float> _bitcoinPrices;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

public:
    BitcoinExchange(const std::string& databaseFile);
    ~BitcoinExchange();

    float getBitcoinValueOnDate(const std::string& date) const;
};

#endif