#include "BitcoinExchange.hpp"
#include <limits>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>


BitcoinExchange::BitcoinExchange() {
	getData("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_mapBitcoin = other._mapBitcoin;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// void printMap(const std::map<std::string, double> &mapBitcoin)  {
//     for (std::map<std::string, double>::const_iterator it = mapBitcoin.begin(); it != mapBitcoin.end(); ++it) {
//         std::cout << it->first << " => " << GREEN  << it->second << RESET << std::endl;
//     }
// }

void BitcoinExchange::getData(const std::string &dataBase) {
	std::ifstream file(dataBase.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: file couldn't be opened");
	}

	std::string line;
	while (std::getline(file, line)) {
		double rate;
		std::string date;
		std::stringstream dataLine(line);
		
		if (std::isdigit(dataLine.peek()) && getline(dataLine, date, ',')) {
			dataLine >> rate;
			_mapBitcoin[date] = rate;
		}
	}
	file.close();
	//printMap(_mapBitcoin);
}

double BitcoinExchange::getExchangeRates(const std::string &date) const {
	std::map<std::string, double>::const_iterator it = _mapBitcoin.find(date);
	if (it != _mapBitcoin.end()) {
		return it->second;
	}

	it = _mapBitcoin.lower_bound(date);
	if (it == _mapBitcoin.begin()) {
		throw std::runtime_error("Date not found");
	}
	--it;
	return it->second;
}

bool isValidDate(const std::string &date) {
    const std::string errorPrefix = "wrong input => ";

    if (date == "date") {
        return false;
    }

    if (date.empty()) {
        throw std::runtime_error("empty date");
    }

    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        throw std::runtime_error(errorPrefix + date);
    }

    int year, month, day;
    char dash1, dash2;
    std::istringstream iss(date);
    iss >> year >> dash1 >> month >> dash2 >> day;

    if (iss.fail() || dash1 != '-' || dash2 != '-') {
        throw std::runtime_error(errorPrefix + date);
    }

    if (year < 1900 || year > 2024) {
        throw std::runtime_error(errorPrefix + date);
    }

    if (month < 1 || month > 12) {
        throw std::runtime_error(errorPrefix + date);
    }

    if (day < 1 || day > 31) {
        throw std::runtime_error(errorPrefix + date);
    }

    return true;
}
// bool isValidDate(const std::string &date) {
// 	std::string error = "wrong input => ";

// 	if (date == "date")
// 		return (false);
// 	if (date.empty())
// 		throw std::runtime_error("empty date");
// 	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
// 		throw std::runtime_error(error + date);
// 	if (date.substr(0, 4) < "1900" || date.substr(0, 4) > "2024")
// 		throw std::runtime_error(error + date);
// 	if (date.substr(5, 2) < "01" || date.substr(5, 2) > "12")
// 		throw std::runtime_error(error + date);
// 	if (date.substr(8, 2) < "01" || date.substr(8, 2) > "31")
// 		throw std::runtime_error(error + date);
// 	return true;
// }

bool isInvalidValue(double value) {
	if (value < 0)
		throw std::runtime_error("Number not positive");
	if (value > 1000)
		throw std::runtime_error("Number too large");
	return false;
}

void deleteSpaces(std::string &date) {
    date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
}

// void BitcoinExchange::printData(std::string pathInputFile) const {
// 	std::ifstream file(pathInputFile.c_str());
// 	if (!file.is_open())
// 		throw std::runtime_error("Error: could not open file ");

// 	std::string line;
// 	while (std::getline(file, line)) {
// 		std::string date;
// 		double value;
// 		std::stringstream dataLine(line);
		
// 		try {
// 			getline(dataLine, date, '|');
// 			deleteSpaces(date);
// 			if (isValidDate(date)) {
// 				if (!(dataLine >> value))
// 					throw std::runtime_error("bad input => " + line);
// 				if (isInvalidValue(value)) throw ;
// 				double rate = getExchangeRates(date);
// 				std::cout << date << " => " << rate * value << std::endl;
// 			}
// 		} catch (const std::exception &e) {
// 			std::cerr << "Error: " << RED << e.what() << RESET << std::endl;
// 		}
// 	}
// }


void BitcoinExchange::printData(const std::string &pathInputFile) const {
    std::ifstream file(pathInputFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file " + pathInputFile);
    }

    std::string line;
    while (std::getline(file, line)) {
        try {
            processLine(line);
        } catch (const std::exception &e) {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }
}

void BitcoinExchange::processLine(const std::string &line) const {
    std::string date;
    double value;
    std::stringstream dataLine(line);

    if (!std::getline(dataLine, date, '|')) {
        throw std::runtime_error("Invalid format: missing date in line => " + line);
    }

    deleteSpaces(date);

    if (!isValidDate(date)) {
        throw std::runtime_error("Invalid date format => " + date);
    }

    if (!(dataLine >> value)) {
        throw std::runtime_error("Invalid value format => " + line);
    }

    if (isInvalidValue(value)) {
        std::stringstream ss;
        ss << RED <<  "Invalid value => " << RESET << value;
        throw std::runtime_error(ss.str());
    }

    double rate = getExchangeRates(date);
    std::cout << date << GREEN << " => " << rate * value << RESET << std::endl;
}