
#include "Intern.hpp"
Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern& Intern::operator=(const Intern &src) {
	(void)src;
	return *this;
}

Intern::~Intern() {}


AForm *Intern::createPresidentialForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotForm(std::string target) {
	return new RobotomyRequestForm(target);
}


AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	std::string name[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	AForm *(Intern::*forms[3])(std::string) = {
		&Intern::createRobotForm,
		&Intern::createPresidentialForm,
		&Intern::createShrubberyForm
	};

	int i;
	for (i = 0; i < 3; i++) {
		if (name[i] == formName) {
			std::cout << "Intern creates " << formName << " Form" << std::endl;
			return (this->*forms[i])(target);
		}
	}
	std::cerr << "\033[1;31mError: Form name \"" << formName << "\" does not exist.\033[0m" << std::endl;
	throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found" ;
}