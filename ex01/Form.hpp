
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    std::string const   _name;
    bool                _isSigned;
    int const           _requiredSignGrade;
    int const           _requiredExecuteGrade;

    void                _checkFormGrades();

public:
    Form(); // Default constructor
    Form(std::string const &name, int const requiredSignGrade, int const requiredExecuteGrade); // Parametric constructor
    Form(Form const &src); // Copy constructor
    Form &operator=(Form const &src); // Copy assignment operator
    ~Form(); // Default destructor

    std::string const   getName() const;
    bool                getIsSigned() const;
    int                 getRequiredSignGrade() const;
    int                 getRequiredExecuteGrade() const;

    void                beSigned(Bureaucrat const &bureaucrat);

    class GradeTooHighException: public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
    public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &output, Form const &input);

# endif