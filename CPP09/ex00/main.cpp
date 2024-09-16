
#include "BitcoinExchange.hpp"



int checkFile(const std::string &filename) {
    std::ifstream file(filename.c_str()); 
    if (!file.is_open()) {
        std::cerr << RED << "Error: Cannot open file " <<  filename << RESET << std::endl;
        return 1;
    }
    file.close();
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << YELLOW << "Usage: ./bnt <file>" << RESET << std::endl;
        return 1;
    }
    if (checkFile(argv[1]))
        return 1;
    try {
        BitcoinExchange exchange;
        exchange.printData(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}