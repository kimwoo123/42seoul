#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat w("Wooseok", 1);

	std::cout << w;
	std::cout << "decrement test\n";
	try {
		w.decrementGrade();
	}
	catch (Bureaucrat::Exception &e) {
		std::cout << e.what();
	}
	std::cout << w;
	std::cout << "increment test\n";
	try {
		w.incrementGrade();
	}
	catch (Bureaucrat::Exception &e) {
		std::cout << e.what();
	}

	std::cout << w;

	// Increment 1 exception
	std::cout << "increment grade 1\n";
	try {
		w.incrementGrade();
	}
	catch (Bureaucrat::Exception &e) {
		std::cout << e.what();
	}
	std::cout << "decrement grade 150\n";
	w.setGrade(150);
	try {
		w.decrementGrade();
	}
	catch (Bureaucrat::Exception &e) {
		std::cout << e.what();
	}

	return (0);
}
