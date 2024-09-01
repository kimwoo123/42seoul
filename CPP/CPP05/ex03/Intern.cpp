#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& i) {
	*this = i;
}

Intern& Intern::operator=(const Intern& i) {
	(void)i;
	return *this;
}

Intern::~Intern(void) {}

int getIndex(std::string formName) {
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int index = 0;

	while (index < 3 && forms[index] != formName)
		++index;
	return index;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	switch (getIndex(formName)) {
			case 0:
				std::cout << "Intern creates PresidentialPardonForm.\n";
				return new PresidentialPardon(target);
			case 1:
				std::cout << "Intern creates RobotomyRequestForm.\n";
				return new RobotomyRequest(target);
			case 2:
				std::cout << "Intern creates ShrubberyCreationForm.\n";
				return new ShrubberyCreation(target);
			default:
				throw Intern::FormDoesntExistException();
	}
	return NULL;
}

const char* Intern::FormDoesntExistException::what() const throw() {
	return "There is no Form matches the name.\n";
}
