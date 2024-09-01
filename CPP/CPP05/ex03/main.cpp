#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));

	Bureaucrat w("Wooseoki");
	Bureaucrat m("Mygo", 1);

	Intern someRandomIntern;

	AForm* p;
	AForm* r;
	AForm* s;

	std::cout << "Intern tries to create the form\n";

	try {
		p = someRandomIntern.makeForm("presidential pardon", "Bender");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	try {
		r = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	try {
		s = someRandomIntern.makeForm("shrubbery creation", "Bender");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	try {
		someRandomIntern.makeForm("somethings wrong", "Bender");
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << "Wooseok tries to execute the form\n";
	try {
		p->execute(w);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << "Wooseok tries to sign the form\n";
	try {
		p->beSigned(w);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << "Mygo tries to sign the form\n";
	try {
		p->beSigned(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << "Wooseok tries to execute the form\n";
	try {
		p->execute(w);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << "Mygo tries to execute the form\n";
	try {
		p->execute(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << "Mygo tries to sign all the form\n" ;
	try {
		r->beSigned(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	try {
		s->beSigned(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << "Mygo tries to execute all the form\n";
	try {
		p->execute(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	try {
		r->execute(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	try {
		s->execute(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	delete p;
	delete r;
	delete s;

	return 0;
}
