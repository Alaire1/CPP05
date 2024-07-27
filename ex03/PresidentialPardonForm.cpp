
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
    AForm::AForm("Presidential Pardon Form", 25, 5, "undefined") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
        AForm::AForm("Presidential Pardon Form", 25, 5, target) {}

 PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):
        AForm::AForm(src.getName(),src.getRequiredSignGrade(),src.getRequiredExecuteGrade(), src.getTarget())
{
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    setIsSigned(src.getIsSigned());
    setTarget(src.getTarget());
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beExecuted(Bureaucrat const &bureaucrat) {
    if (!getIsSigned()) {
        std::cout << "This form is not signed" << std::endl;
        return;
    }
    if (bureaucrat.getGrade() <= getRequiredExecuteGrade()) {
        std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}
