
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(); // Default constructor
    RobotomyRequestForm(std::string target); // Parametric constructor
    RobotomyRequestForm(RobotomyRequestForm const &src); // Copy constructor
    RobotomyRequestForm &operator=(RobotomyRequestForm const &src); // Copy assignment operator
    virtual ~RobotomyRequestForm(); // Default destructor (virtual)

    virtual void        beExecuted(Bureaucrat const &bureaucrat);
};


#endif