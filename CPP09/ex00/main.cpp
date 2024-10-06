#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc == 2) {
		try {
			BitcoinExchange exchange;
			exchange.printConversions(argv[1]);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	} else {
		std::cerr << "Usage: ./btc [file]" << std::endl;
	}
	return 0;
}