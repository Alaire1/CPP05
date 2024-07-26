
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Name"), _grade(LOW_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
    setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name) {
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
    _grade = src._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}


std::string Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

void Bureaucrat::incrementGrade() {
    setGrade(--_grade);
}

void Bureaucrat::decrementGrade() {
    setGrade(++_grade);
}

void Bureaucrat::setGrade(int grade) {
    if (grade > LOW_GRADE)
        throw GradeTooLowException();
    if (grade < HIGH_GRADE)
        throw GradeTooHighException();
    _grade = grade;
}

void Bureaucrat::signForm(AForm &form) {
    if (form.getIsSigned()) {
        std::cout << "This form has been signed" << std::endl;
        return;
    }
    if (_grade <= form.getRequiredSignGrade()) {
        std::cout << _name << " has signed " << form.getName() << std::endl;
    } else {
        std::cout << _name << " couldn't sign " << form.getName() <<
        ". Level is not high enough." << std::endl;
    }
    form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm &form) {
    if (!form.getIsSigned()) {
        std::cout << "This form is not signed" << std::endl;
        return;
    }
    if (_grade <= form.getRequiredExecuteGrade()) {
        std::cout << _name << " executed form: " << form.getName() << std::endl;
    } else {
        std::cout << _name << " could not execute form: " << form.getName() <<
                  ". Level is not high enough." << std::endl;
    }
    form.beExecuted(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Exception: The set grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Exception: The set grade is too low.");
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &input)
{
    output << input.getName() << ", bureaucrat grade is " << input.getGrade() << ".";
    return (output);
}
