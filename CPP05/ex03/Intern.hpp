
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
        AForm *createPresidentialForm(std::string target);
		AForm *createShrubberyForm(std::string target);
		AForm *createRobotForm(std::string target);
        
	public:
		Intern(); // Default constructor
		Intern(const Intern &src); // Copy constructor
        Intern operator=(const Intern &src); // Copy assignment operator
		~Intern(); // Default destructor
	
		AForm *makeForm(const std::string &formName, const std::string &target);

		class FormNotFoundException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif