
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(); // Default constructor
    PresidentialPardonForm(std::string target); // Parametric constructor
    PresidentialPardonForm(PresidentialPardonForm const &src); // Copy constructor
    PresidentialPardonForm &operator=(PresidentialPardonForm const &src); // Copy assignment operator
    virtual ~PresidentialPardonForm(); // Default destructor (virtual)

    virtual void        beExecuted(Bureaucrat const &bureaucrat);
};


#endif