
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(); // default constructor
    ShrubberyCreationForm(std::string target); // parameterized constructor
    ShrubberyCreationForm(ShrubberyCreationForm const &src); // copy constructor
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src); // assignation operator
    virtual ~ShrubberyCreationForm(); // destructor

    virtual void        beExecuted(Bureaucrat const &bureaucrat);
};

#endif
