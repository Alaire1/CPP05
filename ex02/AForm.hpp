

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
    AForm();
    AForm(std::string const &name, int const requiredSignGrade, int const requiredExecuteGrade, std::string target);
    AForm(AForm const &src);
    AForm &operator=(AForm const &src);
    virtual ~AForm();

    std::string const   getName() const;
    bool                getIsSigned() const;
    int const           getRequiredSignGrade() const;
    int const           getRequiredExecuteGrade() const;
    std::string         getTarget() const;

    void                setIsSigned(bool boolean);
    void                setTarget(std::string target);

    void                beSigned(Bureaucrat const &bureaucrat);
    virtual void        beExecuted(Bureaucrat const &bureaucrat) = 0;

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