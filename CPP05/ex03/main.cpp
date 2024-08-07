#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void testInternAndBureaucrat() {
    std::cout << "\033[1;33mIntern vs Bureaucrat Test:\033[0m" << std::endl;
    

    Intern intern;
    Bureaucrat bossMan("Boss", 1);
    Bureaucrat middleMan("MiddleMan", 75);
    Bureaucrat newMan("Newbie", 150);

    AForm *form;

    // Test Presidential Pardon Form
    std::cout << "\033[1;33m" << "Presidential Pardon Form" << "\033[0m" << std::endl;
    try {
        form = intern.makeForm("presidential pardon", "Jonny");
        std::cout << "Intern created form: " << *form << std::endl;
        bossMan.signForm(*form);
        bossMan.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    // Test Robotomy Request Form
    std::cout << "\033[1;33m" << "Robotomy Request Form" << "\033[0m" << std::endl;
    try {
        form = intern.makeForm("robotomy request", "Mark");
        std::cout << "Intern created form: " << *form << std::endl;
        bossMan.signForm(*form);
        bossMan.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    // Test Shrubbery Creation Form
    std::cout << "\033[1;33m" << "Shrubbery Creation Form" << "\033[0m" << std::endl;
    try {
        form = intern.makeForm("shrubbery creation", "Maria");
        std::cout << "Intern created form: " << *form << std::endl;
        middleMan.signForm(*form);
        middleMan.executeForm(*form);
        delete form;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    // Test unknown form
    std::cout << "\033[1;33m" << "Unknown Form" << "\033[0m" << std::endl;
    try {
        form = intern.makeForm("unknown form", "Billy");
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
}

int main() {
    testInternAndBureaucrat();
    return 0;
}