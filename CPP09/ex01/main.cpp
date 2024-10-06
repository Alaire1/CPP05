#include "RPN.hpp"


int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./RPN <expression>" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		std::cout << rpn.calculateRPN(argv[1]) << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}