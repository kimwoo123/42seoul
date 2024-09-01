#include <ctime>
#include "Bureaucrat.hpp"
#include "PresidentialPardon.hpp"
#include "RobotomyRequest.hpp"
#include "ShrubberyCreation.hpp"

int main()
{
	std::srand(std::time(NULL));

	Bureaucrat w("Wooseok");
	Bureaucrat m("Mygo", 1);

	PresidentialPardon pardon("Pardon");
	RobotomyRequest robo("Robo");
	ShrubberyCreation shru("Shru");

	std::cout << "Wooseok tries to execute the form" << std::endl;
	try {
		pardon.execute(w);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << "Wooseok tries to sign the form" << std::endl;
	try {
		pardon.beSigned(w);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << "Mygo tries to sign the form" << std::endl;
	try {
		pardon.beSigned(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << "Wooseok tries to execute the form" << std::endl;
	try {
		pardon.execute(w);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << "Mygo tries to execute the form" << std::endl;
	try {
		pardon.execute(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << "Mygo tries to sign all the form" << std::endl;
	try {
		robo.beSigned(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	try {
		shru.beSigned(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << "Mygo tries to execute all the form" << std::endl;
	try {
		pardon.execute(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	try {
		robo.execute(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	try {
		shru.execute(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	return 0;
}
