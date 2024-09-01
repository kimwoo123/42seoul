#include "Form.hpp"

int main(void) {
	Bureaucrat w("Wooseok");
	Bureaucrat m("Mygo", 1);

	Form test("Test", 10, 10);
	std::cout << "Check status\n";
	std::cout << test;
	try {
		test.beSigned(w);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << "Check status\n";
	std::cout << test;
	try {
		test.beSigned(m);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << "Check status\n";
	std::cout << test;


	Form book("Book");
	std::cout << "\n";
	std::cout << "Check status\n";
	std::cout << book;

	w.signForm(book);
	std::cout << "Check status\n";
	std::cout << book;

	m.signForm(book);
	std::cout << "Check status\n";
	std::cout << book;

	return 0;
}
