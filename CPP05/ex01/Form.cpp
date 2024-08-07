
#include "Form.hpp"

Form::Form():
    _name("Untitled Form"),
    _isSigned(false),
    _requiredSignGrade(HIGH_GRADE),
    _requiredExecuteGrade(HIGH_GRADE) 
    {}

Form::Form(std::string const &name, int const requiredSignGrade, int const requiredExecuteGrade) :
    _name(name),
    _isSigned(false),
    _requiredSignGrade(requiredSignGrade),
    _requiredExecuteGrade(requiredExecuteGrade)
{
    _checkFormGrades();
}

Form::Form(Form const &src):
    _name(src._name),
    _isSigned(src._isSigned),
    _requiredSignGrade(src._requiredSignGrade),
    _requiredExecuteGrade(src._requiredExecuteGrade)
{
    *this = src;
}

void Form::_checkFormGrades() {
    if (_requiredSignGrade < HIGH_GRADE || _requiredExecuteGrade < HIGH_GRADE)
        throw Form::GradeTooHighException();
    if (_requiredSignGrade > LOW_GRADE || _requiredExecuteGrade > LOW_GRADE)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(Form const &src) {
    _isSigned = src._isSigned;
    return (*this);
}

Form::~Form() {}


void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (_isSigned) {
        std::cout << "This form has been signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() <= _requiredSignGrade)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Exception Form: Grade too high.");
}


const char *Form::GradeTooLowException::what() const throw() {
    return ("Exception Form: Grade too low.");
}

std::string const   Form::getName() const {return (_name);}
bool                Form::getIsSigned() const {return(_isSigned);}
int                 Form::getRequiredExecuteGrade() const {return(_requiredExecuteGrade);}
int                 Form::getRequiredSignGrade() const {return(_requiredSignGrade);}

std::ostream &operator<<(std::ostream &output, Form const &input)
{
    std::string signatureState = input.getIsSigned() ? "Present" : "Absent";

    output << "Name: " << input.getName() << "\n"
           << "Signature: " << signatureState << "\n"
           << "Required Sign Grade: " << input.getRequiredSignGrade() << "\n"
           << "Required Execute Grade: " << input.getRequiredExecuteGrade() << std::endl;

    return output;
}
