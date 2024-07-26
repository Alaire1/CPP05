#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

# define HIGH_GRADE 1
# define LOW_GRADE 150

class AForm;

class Bureaucrat {
private:
    std::string const   _name;
    int                 _grade;

public:
    Bureaucrat(); // Default constructor
    Bureaucrat(std::string name, int grade); // Parametric constructor
    Bureaucrat(Bureaucrat const &obj); // Copy constructor
    Bureaucrat &operator=(Bureaucrat const &src); // Copy assignment operator
    ~Bureaucrat(); // Default destructor
    
    std::string getName() const;
    int         getGrade() const;
    void        setGrade(int grade);

    void        incrementGrade();
    void        decrementGrade();

    void        signForm(Form &form);
    void        executeForm(Form const &form); //?

    class GradeTooHighException: public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException: public std::exception {
    public:
        const char* what() const throw();
    };
};


std::ostream &operator<<(std::ostream &output, Bureaucrat const &input);

#endif