#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

void testFormCreation() {
    std::cout << "\033[1;33mForm Creation Tests:\033[0m" << std::endl;
    int signGrade = 100;
    int executeGrade = 23;

    try {
        Form form("Valid Form", signGrade, executeGrade);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        signGrade = 151;
        std::cout << "Form, sign grade: "  << signGrade << ", executeGrade: " << executeGrade << std::endl;
        Form form("Invalid Form High", signGrade, executeGrade);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }

    try {
        signGrade = 0;
        std::cout << "Form, sign grade: "  << signGrade << ", executeGrade: " << executeGrade << std::endl;
        Form form("Invalid Form Low", signGrade, executeGrade);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }

    try {
        signGrade = 26;
        executeGrade  = 152;
        std::cout << "Form, sign grade: "  << signGrade << ", executeGrade: " << executeGrade << std::endl;
        Form form("Invalid Execution High", signGrade, executeGrade);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }

    try {
        executeGrade  = 0;
        std::cout << "Form, sign grade: "  << signGrade << ", executeGrade: " << executeGrade << std::endl;
        Form form("Invalid Execution Low", signGrade, executeGrade);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
}

void testFormSigning() {
    std::cout << "\033[1;33mForm Signing Test:\033[0m" << std::endl;

    Form form1("Draft Form", 98, 23);
    Form form2(form1);
    std::cout << "Form 1: " << form1 << std::endl;
    std::cout << "Form 2 (copy): " << form2 << std::endl;

    Bureaucrat tim("Tim", 98);
    Bureaucrat billy("Billy", 99);

    tim.signForm(form1);
    std::cout << "After Tim signs Form 1: \n" << form1 << std::endl;

    std::cout << "Billy tries to sign form 2:"  << std::endl;
    try {
        billy.signForm(form2);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
    
    std::cout << "Tim signs Form 1 again: \n"<< std::endl;
    tim.signForm(form1);
}
    
  


int main() {
    testFormCreation();
    testFormSigning();
    return 0;
}