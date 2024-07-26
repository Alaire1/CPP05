
#include "AForm.hpp"

void AForm::_checkFormGrades() {
    if (_requiredSignGrade < TOPGRADE || _requiredExecuteGrade < TOPGRADE)
        throw AForm::GradeTooHighException();
    if (_requiredSignGrade > BOTTOMGRADE || _requiredExecuteGrade > BOTTOMGRADE)
        throw AForm::GradeTooLowException();
}

AForm::AForm():
    _name("Untitled Form"),
    _isSigned(false),
    _requiredSignGrade(TOPGRADE),
    _requiredExecuteGrade(TOPGRADE),
    _target("undefined"){}

AForm::AForm(std::string const &name, int const requiredSignGrade, int const requiredExecuteGrade, std::string target) :
    _name(name),
    _isSigned(false),
    _requiredSignGrade(requiredSignGrade),
    _requiredExecuteGrade(requiredExecuteGrade),
    _target(target)
{
    _checkFormGrades();
}

AForm::AForm(AForm const &src):
    _name(src._name),
    _isSigned(src._isSigned),
    _requiredSignGrade(src._requiredSignGrade),
    _requiredExecuteGrade(src._requiredExecuteGrade),
    _target(src._target)
{
    *this = src;
}

AForm &AForm::operator=(AForm const &src) {
    _isSigned = src._isSigned;
    _target = src._target;
    return (*this);
}

AForm::~AForm() {}

std::string const   AForm::getName() const {return (_name);}

bool                AForm::getIsSigned() const {return(_isSigned);}

int const           AForm::getRequiredSignGrade() const {return(_requiredSignGrade);}

int const           AForm::getRequiredExecuteGrade() const {return(_requiredExecuteGrade);}

std::string         AForm::getTarget() const {return (_target);}

void                AForm::setIsSigned(bool boolean) {_isSigned = boolean;}

void                AForm::setTarget(std::string target) {_target = target;}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (_isSigned) {
        std::cout << "This form is already signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() <= _requiredSignGrade)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Exception: The grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Exception: The grade is too low.");
}

std::ostream &operator<<(std::ostream &output, AForm const &input)
{
    std::string signatureState;

    signatureState = input.getIsSigned() ? "Present" : "Absent";
    output << "Form name: " << input.getName() << "." << std::endl;
    output << "Signature: " << signatureState << "." << std::endl;
    output << "Required Sign Grade: " << input.getRequiredSignGrade() << "." << std::endl;
    output << "Required Execute Grade: " << input.getRequiredExecuteGrade() << ".";
    return (output);
}
