
#include "BitcoinExchange.hpp"
#include <limits>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>


BitcoinExchange::BitcoinExchange() {
	loadDataBase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

void BitcoinExchange::loadDataBase(const std::string &dataBaseFile) {
	std::ifstream file(dataBaseFile.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file ");
	}

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream lineStr(line);
		std::string date;
		double rate;

		if (std::isdigit(lineStr.peek()) && getline(lineStr, date, ',')) {
			lineStr >> rate;
			_exchangeRates[date] = rate;
		}
	}
	file.close();
}
double BitcoinExchange::getRates(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);
    
    if (it != _exchangeRates.end()) 
        return it->second;
    it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.begin()) 
        throw std::runtime_error("date not found");
    --it;
    return it->second;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int stringToInt(const std::string &str) {
    std::istringstream iss(str);
    int value;
    iss >> value;
    return value;
}

bool isValidDate(const std::string &date) {
    std::string error = "bad input => ";

    if (date == "date")
        return false;
    if (date.empty())
        throw std::runtime_error("empty date.");
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error(error + date);

    int year = stringToInt(date.substr(0, 4));
    int month = stringToInt(date.substr(5, 2));
    int day = stringToInt(date.substr(8, 2));

    if (year < 2009 || year > 2022)
        throw std::runtime_error(error + date);
    if (month < 1 || month > 12)
        throw std::runtime_error(error + date);

    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year)) {
        maxDay = 29;
    }

    if (day < 1 || day > maxDay)
        throw std::runtime_error(error + date);

    return true;
}

bool isInvalidValue(double value) {
	if (value < 0)
		throw std::runtime_error("not a positive number.");
	if (value > 1000)
		throw std::runtime_error("too large number.");
	return false;
}

void remove_spaces(std::string &date) {
	std::string::iterator end_pos;

	end_pos = std::remove(date.begin(), date.end(), ' ');
	date.erase(end_pos, date.end());
}
void BitcoinExchange::readFile(std::ifstream &file, std::string &line) const {
    while (std::getline(file, line)) {
        std::stringstream lineStr(line);
        std::string date;
        double value;

        try {
            getline(lineStr, date, '|');
            remove_spaces(date);
            if (isValidDate(date)) {
                if (!(lineStr >> value))
                    throw std::runtime_error("bad input => " + line);
                if (isInvalidValue(value)) throw ;
                double rate = getRates(date);
                std::cout << date << " => " << value << " = " << rate * value << std::endl;
            }
        } catch (const std::exception &e) {
            std::cerr << "Error: " << RED << e.what() << END << std::endl;
        }
    }
}
void BitcoinExchange::printConversions(std::string pathToFile) const {
	std::ifstream file(pathToFile.c_str());
	if (!file.is_open())
	{
		std::string errorMessage = RED "Error: could not open file " + pathToFile + END;
		throw std::runtime_error(errorMessage);
	}
	std::string line;
	readFile(file, line);	
}
