#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

void testFormCreation() {
    std::cout << "\033[1;33mForm Creation Tests:\033[0m" << std::endl;

    try {
        Form form("Valid Form", 100, 23);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form form("Invalid Form High", 151, 23);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }

    try {
        Form form("Invalid Form Low", 0, 23);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }

    try {
        Form form("Invalid Execution High", 25, 151);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }

    try {
        Form form("Invalid Execution Low", 25, 0);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
}

void testFormSigning() {
    std::cout << "\033[1;33mForm Signing Test:\033[0m" << std::endl;

    Form form("Draft Form", 98, 23);
    Form form2(form);
    std::cout << "Form 1: " << form << std::endl;
    std::cout << "Form 2 (copy): " << form2 << std::endl;

    Bureaucrat tim("Tim", 98);
    Bureaucrat billy("Billy", 99);

    tim.signForm(form);
    std::cout << "After Tim signs Form 1: " << form << std::endl;

    try {
        billy.signForm(form2);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
    std::cout << "Billy signs Form 2 again:" << form2 << std::endl;

    tim.signForm(form);
    std::cout << "Tim signs Form 1 again: " << form << std::endl;
}


int main() {
    testFormCreation();
    testFormSigning();
    return 0;
}