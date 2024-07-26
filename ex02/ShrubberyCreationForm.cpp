
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
        AForm::AForm("Shrubbery Creation Form",
                     145,
                     137,
                     "undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
        AForm::AForm("Shrubbery Creation Form",
                     145,
                     137,
                     target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):
        AForm::AForm(src.getName(),
                     src.getRequiredSignGrade(),
                     src.getRequiredExecuteGrade(),
                     src.getTarget())
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

void ShrubberyCreationForm::beExecuted(Bureaucrat const &bureaucrat) {
    if (!getIsSigned()) {
        std::cout << "This form is not yet signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() <= getRequiredExecuteGrade()) {
        std::ofstream outfile(getTarget() + "_shrubbery");
        outfile <<
                "            # #### ####\n"
                "        ### \\/#|### |/####\n"
                "        ##\\/#/ \\||/##/_/##/_#\n"
                "       ###  \\/###|/ \\/ # ###\n"
                "    ##_\\_#\\_\\## | #/###_/_####\n"
                "    ## #### # \\ #| /  #### ##/##\n"
                "    __#_--###`  |{,###---###-~\n"
                "                \\ }{\n"
                "                }}{\n"
                "                }}{\n"
                "       		 {{}\n"
                "        , -=-~{ .-^- _\n"
                "                `}\n"
                "                 {"
                << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}
