
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
        AForm::AForm("Robotomy Request Form", 72, 45, "undefined") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
        AForm::AForm("Robotomy Request Form", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):
        AForm::AForm(src.getName(), src.getRequiredSignGrade(), src.getRequiredExecuteGrade(), src.getTarget())
{
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    setIsSigned(src.getIsSigned());
    setTarget(src.getTarget());
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExecuted(Bureaucrat const &bureaucrat) {
    if (!getIsSigned()) {
        std::cout << "This form is not signed" << std::endl;
        return;
    }
    if (bureaucrat.getGrade() <= getRequiredExecuteGrade()) {
        std::time_t timeStamp = std::time(NULL);
        std::cout << "Robotomy procedure on " << getTarget() << " has been started" << std::endl;
        srand(time(NULL));
        std::cout << "Outcome:" <<(timeStamp % 2 ? "Success" : "Failure.") << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}
