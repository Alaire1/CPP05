
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
        AForm::AForm("Shrubbery Creation Form", 145, 137, "undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
        AForm::AForm("Shrubbery Creation Form", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):
        AForm::AForm(src.getName(), src.getRequiredSignGrade(), src.getRequiredExecuteGrade(), src.getTarget())
{
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    setIsSigned(src.getIsSigned());
    setTarget(src.getTarget());
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) {
    if (!getIsSigned()) {
        std::cout << "This form is not signed" << std::endl;
        return;
    }
    if (executor.getGrade() <= getRequiredExecuteGrade()) {
        std::ofstream outfile((getTarget() + "_shrubbery").c_str());
        outfile <<
                "         ccee88oo\n"
                "  C8O8O8Q8PoOb o8oo\n"
                " dOB69QO8PdUOpugoO9bD\n"
                "CgggbU8OU qOp qOdoUOdcb\n"
                "    6OuU  /p u gcoUodpP\n"
                "      \\\\//  /douUP\n"
                "        \\\\////\n"
                "         |||/\\\n"
                "         |||\\/\n"
                "         |||||\n"
                "   .....//||||\\....\n"
                << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}
