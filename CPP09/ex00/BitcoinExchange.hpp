
#pragma once

#include <string>
#include <map>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define END "\033[0m"


class BitcoinExchange {
	private:
		std::map<std::string, double> _exchangeRates;
		void loadDataBase(const std::string &dataBaseFile);
		double getRates(const std::string &date) const;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void printConversions(const std::string pathToFile) const;
		void readFile(std::ifstream &file, std::string &line) const;
		
};