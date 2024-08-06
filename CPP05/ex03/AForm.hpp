
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    std::string const   _name;
    bool                _isSigned;
    int const           _requiredSignGrade;
    int const           _requiredExecuteGrade;
    std::string         _target;

    void                _checkFormGrades();

public:
    AForm(); // Default constructor
    AForm(std::string const &name, int const requiredSignGrade, int const requiredExecuteGrade, std::string target); // Parametric constructor
    AForm(AForm const &src); // Copy constructor
    AForm &operator=(AForm const &src); // Copy assignment operator
    virtual ~AForm(); // Default destructor (virtual)

    std::string const   getName() const;
    bool                getIsSigned() const;
    int                 getRequiredSignGrade() const;
    int                 getRequiredExecuteGrade() const;
    std::string         getTarget() const;

    void                beSigned(Bureaucrat const &bureaucrat);
    virtual void        execute(Bureaucrat const &executor) = 0;

    void                setIsSigned(bool boolean);
    void                setTarget(std::string target);


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

std::ostream &operator<<(std::ostream &output, AForm const &input);

# endif