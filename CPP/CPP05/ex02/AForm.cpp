#include "AForm.hpp"

AForm::AForm(void): name_("Untitled"), signed_(false), signGrade_(1), execGrade_(1) {}

AForm::AForm(std::string name): name_(name), signed_(false), signGrade_(1), execGrade_(1) {}

AForm::AForm(std::string name, int signGrade, int execGrade): name_(name), signed_(false), signGrade_(signGrade), execGrade_(execGrade) {
	if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw GradeTooHighException();
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& a): name_(a.name_), signed_(a.signed_), signGrade_(a.signGrade_), execGrade_(a.execGrade_) {}

AForm& AForm::operator=(const AForm& a) {
	(void)a;
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName(void) const {
	return this->name_;
}

const bool&	AForm::getSigned(void) const {
	return this->signed_;
}

const int&	AForm::getSignGrade(void) const {
	return this->signGrade_;
}

const int&	AForm::getExecGrade(void) const {
	return this->execGrade_;
}

void	AForm::setSigned(const bool& s) {
	this->signed_ = s;
}

void	AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->signed_ = true;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Grade can't under 1\n";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Grade can't over 150\n";
}

const char*	AForm::NoSignException::what() const throw() {
	return "There is no sign.\n";
}

std::ostream& operator<<(std::ostream& o, const AForm& a) {
	return o << a.getName() << ", signed: " << a.getSigned() << ", grade required to sign: " << a.getSignGrade() << ", grade required to execute: " << a.getExecGrade();
}
