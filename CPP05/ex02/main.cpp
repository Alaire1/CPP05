#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

void testPresidentialPardonForm() {
    std::cout << "\033[1;33mPresidential Pardon Form Test:\033[0m" << std::endl;

    PresidentialPardonForm pardon("Jonny");
    PresidentialPardonForm pardonUnsigned(pardon);

    Bureaucrat boss("Boss", 1);
    Bureaucrat middleMan("MddleMan", 75);


    boss.signForm(pardon);
    //double signing
    boss.signForm(pardon);
    try {
        middleMan.signForm(pardonUnsigned);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        middleMan.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
    std::cout << std::endl;
    //executing not signed form
    boss.executeForm(pardonUnsigned);
    boss.executeForm(pardon);
    std::cout << pardon << std::endl;
}

void testRobotomyRequestForm() {
    std::cout << "\033[1;33mRobotomy Form Test:\033[0m" << std::endl;
    RobotomyRequestForm robo("Mark");
    RobotomyRequestForm roboUnsigned(robo);

    Bureaucrat boss("Boss", 1);
    Bureaucrat middleMan("MddleMan", 75);

    boss.signForm(robo);
    //double signing
    boss.signForm(robo);
    try {
        middleMan.signForm(roboUnsigned);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        middleMan.executeForm(robo);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
    std::cout << std::endl;
    //executing unsigned
    boss.executeForm(roboUnsigned);
    boss.executeForm(robo);
    std::cout << robo << std::endl;
}

void testShrubberyCreationForm() {
    std::cout << "\033[1;33mShrubbery Form Test:\033[0m" << std::endl;

    ShrubberyCreationForm shrub("Maria");
    ShrubberyCreationForm shrubUnsigned(shrub);

    Bureaucrat middleMan("MddleMan", 75);
    Bureaucrat newMan("Newbie", 150);

    middleMan.signForm(shrub);
    //double signing form
    middleMan.signForm(shrub);
    try {
        newMan.signForm(shrubUnsigned);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        newMan.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
    }
    std::cout << std::endl;
    //executing not signed form
    middleMan.executeForm(shrubUnsigned);
    middleMan.executeForm(shrub);
    std::cout << shrub << std::endl;
}
// instantion of AForm not gonna be created because it's an abstract class
// void testAForm() {
//     std::cout << "\033[1;33m// AFORM TEST //\033[0m" << std::endl;

//     AForm testForm("test");
//     AForm testFormUnsigned(testForm);

//     Bureaucrat boss("Boss", 1);
//     Bureaucrat middleMan("Mid", 75);

//     boss.signForm(testForm);
//     boss.signForm(testForm);
//     try {
//         middleMan.signForm(testFormUnsigned);
//     } catch (std::exception &e) {
//         std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
//     }
//     std::cout << std::endl;
//     try {
//         middleMan.executeForm(testForm);
//     } catch (std::exception &e) {
//         std::cout << "\033[1;31mExpected error:\033[0m " << e.what() << std::endl;
//     }
//     std::cout << std::endl;

//     boss.executeForm(testFormUnsigned);
//     std::cout << std::endl;
//     boss.executeForm(testForm);
//     std::cout << testForm << std::endl;
// }

int main() {
    testPresidentialPardonForm();
    testRobotomyRequestForm();
    testShrubberyCreationForm();
    //testAForm();
    return 0;
}