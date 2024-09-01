#include "Form.hpp"

Form::Form(void): name_("Untitled"), signed_(false), signGrade_(1), execGrade_(1) {}

Form::Form(std::string name): name_(name), signed_(false), signGrade_(1), execGrade_(1) {}

Form::Form(std::string name, int signGrade, int execGrade): name_(name), signed_(false), signGrade_(signGrade), execGrade_(execGrade) {
	if (this->signGrade_ < 1 || this->execGrade_ < 1)
		throw GradeTooHighException();
	if (this->signGrade_ > 150 || this->execGrade_ > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& f): name_(f.name_), signed_(f.signed_), signGrade_(f.signGrade_), execGrade_(f.execGrade_) {}

Form& Form::operator=(const Form& f) {
	(void)f;
	return *this;
}

Form::~Form() {}

const std::string& Form::getName(void) const {
	return this->name_;
}

const bool&	Form::getSigned(void) const {
	return this->signed_;
}

const int&	Form::getSignGrade(void) const {
	return this->signGrade_;
}

const int&	Form::getExecGrade(void) const {
	return this->execGrade_;
}

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->signed_ = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade can't under 1\n";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade can't over 150\n";
}

std::ostream& operator<<(std::ostream& o, const Form& f) {
	return o << f.getName() << ", signed: " << f.getSigned() << ", grade required to sign: " << f.getSignGrade() << ", grade required to execute: " << f.getExecGrade() << "\n";
}
