#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    std::ifstream dbFile(databaseFile.c_str());

    if (!dbFile.is_open())
        throw std::runtime_error("Could not open database file");

    std::string line, date;

    std::getline(dbFile, line); // get the header

	if (line.compare("date,exchange_rate") != 0)
        throw std::runtime_error("First line of data.csv is wrong"); // throw error

    while (std::getline(dbFile, date, ',')) {

        if (!isValidDate(date))
			throw std::runtime_error("Error: bad date => " + date);

        std::getline(dbFile, line);

        if (_bitcoinPrices.find(date) != _bitcoinPrices.end())
			throw std::runtime_error("Error: duplicate => " + date);

        if (!isValidPrice(line))
			throw std::runtime_error("Error: bad input => " + date);

        float price = strtof(line.c_str(), NULL);

        _bitcoinPrices[date] = price;
    }

    dbFile.close();
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(std::string date) {

    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2023)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidPrice(std::string price) {
	if (price.size() == 0 || price.find(".") != price.rfind("."))
		return false;
	for (size_t i = 0; i < price.size(); i++)
		if (!isdigit(price[i]) && price[i] != '.')
			return false;
	if (strtof(price.c_str(), NULL) > FLT_MAX)
		return false;
	return true;
}

void BitcoinExchange::processInputFile(const std::string& inputFile) {
    std::ifstream inFile(inputFile.c_str());

    if (!inFile.is_open())
        throw std::runtime_error("Could not open input file");

    std::string line;
    std::getline(inFile, line); // discard the header

	if (line.compare("date | value") != 0)
        throw std::runtime_error("First line of input.txt is wrong"); // throw error

    while (std::getline(inFile, line)) {
        try {
            std::string date = line.substr(0, 10);
            line = line.erase(0, 10);
            if (line.compare(0, 3, " | "))
                throw std::runtime_error("Error: bad format.");
            line.erase(0, 3);

            float nbToken = strtof(line.c_str(), NULL);
            if (!isValidDate(date))
                throw std::runtime_error("Error: bad date => " + date);
            else if (nbToken < 0)
                throw std::runtime_error("Error: not a positive number.");
            else if (nbToken > 1000)
                throw std::runtime_error("Error: too large a number.");

            if (_bitcoinPrices.find(date) == _bitcoinPrices.end()) {
                // Find the closest lower date if current date not found
                std::map<std::string, float>::iterator it = _bitcoinPrices.lower_bound(date);
                if (it == _bitcoinPrices.begin())
                    throw std::runtime_error("Error: Date not found and no closest date available => " + date);

                --it; // closest lower date
                date = it->first;
            }

            float ratio = _bitcoinPrices[date] * nbToken;
            std::cout << date << " => " << nbToken << " = " << ratio << std::endl;
        }
        catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
        }

    }

    inFile.close();
}