#include "Bureaucrat.hpp"
#include <iostream>


void testGradeModification() {
    std::cout << "\033[1;33mTesting Grade Increment and Decrement:\033[0m" << std::endl;


    try {
        Bureaucrat bureaucrat("Bob", 75);
        std::cout << bureaucrat << std::endl;

    
        bureaucrat.incrementGrade();
        std::cout << "After increment: " << bureaucrat << std::endl;


        bureaucrat.decrementGrade();
        std::cout << "After decrement: " << bureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

void testGradeTooHigh() {
    std::cout << "\033[1;33mTesting Grade Too High Exception:\033[0m" << std::endl;

    try {
        Bureaucrat tooHigh("Name", 0); 
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}


void testGradeTooLow() {
    std::cout << "\033[1;33mTesting Grade Too Low Exception:\033[0m" << std::endl;

    try {
        Bureaucrat tooLow("Bill", 151); 
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}


void testCopyAndAssignment() {
    std::cout << "\033[1;33mTesting Copy Construction and Assignment:\033[0m" << std::endl;

    Bureaucrat original("Original", 50);
    Bureaucrat copyConstructed(original);
    Bureaucrat assigned;
    assigned = original;


    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy Constructed: " << copyConstructed << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;

    copyConstructed.decrementGrade();
    assigned.incrementGrade();

    std::cout << "\033[1;33mAfter modifying grades:\033[0m" << std::endl;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy Constructed: " << copyConstructed << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;
}

int main() {
    testGradeModification();
    testGradeTooHigh();
    testGradeTooLow();
    testCopyAndAssignment();

    return 0;
}