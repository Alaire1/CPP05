#include "AForm.hpp"

AForm::AForm():
    _name("Untitled Form"),
    _isSigned(false),
    _requiredSignGrade(HIGH_GRADE),
    _requiredExecuteGrade(HIGH_GRADE),
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

void AForm::_checkFormGrades() {
    if (_requiredSignGrade < HIGH_GRADE || _requiredExecuteGrade < HIGH_GRADE)
        throw AForm::GradeTooHighException();
    if (_requiredSignGrade > LOW_GRADE || _requiredExecuteGrade > LOW_GRADE)
        throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(AForm const &src) {
    _isSigned = src._isSigned;
    _target = src._target;
    return (*this);
}

AForm::~AForm() {}

std::string const   AForm::getName() const {return (_name);}
std::string         AForm::getTarget() const {return (_target);}
bool                AForm::getIsSigned() const {return(_isSigned);}
int                 AForm::getRequiredSignGrade() const {return(_requiredSignGrade);}
int                 AForm::getRequiredExecuteGrade() const {return(_requiredExecuteGrade);}
void                AForm::setIsSigned(bool boolean) {_isSigned = boolean;}
void                AForm::setTarget(std::string target) {_target = target;}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (_isSigned) {
        std::cout << "This form has been signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() <= _requiredSignGrade)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Exception: Grade too high.");
}


const char *AForm::GradeTooLowException::what() const throw() {
    return ("Exception: Grade too low.");
}

std::ostream &operator<<(std::ostream &output, AForm const &input)
{
    std::string signatureState = input.getIsSigned() ? "Present" : "Absent";

    output << "Name: " << input.getName() << "\n"
           << "Signature: " << signatureState << "\n"
           << "Required Sign Grade: " << input.getRequiredSignGrade() << "\n"
           << "Required Execute Grade: " << input.getRequiredExecuteGrade() << std::endl;

    return output;
}