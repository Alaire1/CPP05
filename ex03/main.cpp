#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

void testPresidentialPardonForm() {
    std::cout << "\033[1;33mPresidential Pardon Form Test:\033[0m" << std::endl;
    std::string partition(50, '-');
    std::cout << partition << std::endl;

    PresidentialPardonForm pardon("James Sunderland");
    PresidentialPardonForm pardonUnsigned(pardon);

    Bureaucrat bossMan("Boss", 1);
    Bureaucrat middleMan("MddleMan", 75);

    bossMan.signForm(pardon);
    bossMan.signForm(pardon);
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

    bossMan.executeForm(pardonUnsigned);
    std::cout << std::endl;
    bossMan.executeForm(pardon);
    std::cout << pardon << std::endl;
}

void testRobotomyRequestForm() {
    std::cout << "\033[1;33mRobotomy Form Test:\033[0m" << std::endl;
    std::string partition(50, '-');
    std::cout << partition << std::endl;

    RobotomyRequestForm robo("Mark");
    RobotomyRequestForm roboUnsigned(robo);

    Bureaucrat bossMan("Boss", 1);
    Bureaucrat middleMan("MddleMan", 75);

    bossMan.signForm(robo);
    bossMan.signForm(robo);
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

    bossMan.executeForm(roboUnsigned);
    std::cout << std::endl;
    bossMan.executeForm(robo);
    std::cout << robo << std::endl;
}

void testShrubberyCreationForm() {
    std::cout << "\033[1;33mShrubbery Form Test:\033[0m" << std::endl;
    std::string partition(50, '-');
    std::cout << partition << std::endl;

    ShrubberyCreationForm shrub("Maria");
    ShrubberyCreationForm shrubUnsigned(shrub);

    Bureaucrat middleMan("MddleMan", 75);
    Bureaucrat newMan("Newbie", 150);

    middleMan.signForm(shrub);
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

    middleMan.executeForm(shrubUnsigned);
    std::cout << std::endl;
    middleMan.executeForm(shrub);
    std::cout << shrub << std::endl;
}
// AForm test
// void testAForm() {
//     std::cout << "\033[1;33m// AFORM TEST //\033[0m" << std::endl;
//     std::string partition(50, '-');
//     std::cout << partition << std::endl;

//     AForm testForm("Test Form");
//     AForm testFormUnsigned(testForm);

//     Bureaucrat bossMan("Boss", 1);
//     Bureaucrat middleMan("Mid", 75);

//     bossMan.signForm(testForm);
//     bossMan.signForm(testForm);
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

//     bossMan.executeForm(testFormUnsigned);
//     std::cout << std::endl;
//     bossMan.executeForm(testForm);
//     std::cout << testForm << std::endl;
// }

int main() {
    testPresidentialPardonForm();
    testRobotomyRequestForm();
    testShrubberyCreationForm();
    //testAForm();
    return 0;
}