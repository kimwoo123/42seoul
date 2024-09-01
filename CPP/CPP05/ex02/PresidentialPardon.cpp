#include "PresidentialPardon.hpp"

PresidentialPardon::PresidentialPardon()
: AForm("Unknown", 25, 5) {}

PresidentialPardon::PresidentialPardon(const std::string& name)
: AForm(name, 25, 5) {}

PresidentialPardon::PresidentialPardon(const PresidentialPardon& p)
: AForm(p) {}

PresidentialPardon& PresidentialPardon::operator=(const PresidentialPardon& p) {
	(void)p;
	return *this;
}

PresidentialPardon::~PresidentialPardon(void) {}

void PresidentialPardon::execute(Bureaucrat const& executor) const {
	if (this->getSigned() == false)
		throw AForm::NoSignException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}
