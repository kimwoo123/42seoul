#include "RobotomyRequest.hpp"

RobotomyRequest::RobotomyRequest(): AForm("Unknown", 72, 45) {}

RobotomyRequest::RobotomyRequest(const std::string& name): AForm(name, 72, 45) {}

RobotomyRequest::RobotomyRequest(const RobotomyRequest& r): AForm(r) {}

RobotomyRequest& RobotomyRequest::operator=(const RobotomyRequest& r) {
	(void)r;
	return *this;
}

RobotomyRequest::~RobotomyRequest(void) {}

void RobotomyRequest::execute(Bureaucrat const &executor) const {
	int random_value;

	if (this->getSigned() == false)
		throw AForm::NoSignException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	random_value = std::rand();
	if (random_value % 2)
		std::cout << executor.getName() << " has been robotomized successfully.\n";
	else
		std::cout << executor.getName() << " failed to be robotomized.\n";
}
