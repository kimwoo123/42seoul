#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name_("default"), grade_(150) {
	std::cout << "Bureaucrat default constructor is called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade): name_(name) {
	std::cout << "Bureaucrat constructor is called\n";
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else {
		this->grade_ = grade;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const& b): name_(b.name_) {
	std::cout << "Bureaucrat copy constructor is called\n";
	std::cout << "name " << name_ << "grade " << grade_ << "\n";
	this->grade_ = b.grade_;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor is called\n";
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& b) {
	this->grade_ = b.grade_;
	return *this;
}

void	Bureaucrat::incrementGrade(void) {
	if (this->grade_ - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else {
		this->grade_--;
	}
}

void	Bureaucrat::decrementGrade(void) {
	if (this->grade_ + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else {
		this->grade_++;
	}
}

const std::string	Bureaucrat::getName(void) const {
	return this->name_;
}

int	Bureaucrat::getGrade(void) const {
	return this->grade_;
}

void	Bureaucrat::setGrade(const int grade) {
	this->grade_ = grade;
}


std::ostream& operator<<(std::ostream& o, Bureaucrat const& b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return o;
}

const char* Bureaucrat::Exception::what() const throw() {
	return "BureaucratException\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Can't under 1 grade\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Can't over 150 grade\n";
}
