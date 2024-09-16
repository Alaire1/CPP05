#pragma once

#include <string>
#include <map>
#include <ostream>
#include <iostream>
#include <fstream>

// Colors
# define BLACK "\033[30m"
# define GRAY "\033[90m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

class BitcoinExchange {
	private:
		std::map<std::string, double> _mapBitcoin;
		void getData(const std::string &dataBase);
		double getExchangeRates(const std::string &date) const;

	public:
		BitcoinExchange(); // Default constructor
		~BitcoinExchange(); // Destructor
		BitcoinExchange(const BitcoinExchange &other); // Copy constructor
		BitcoinExchange &operator=(const BitcoinExchange &other); // Assignation operator

		void printData(const std::string &pathInputFile) const;
		void processLine(const std::string &line) const;
};

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &exchange);

