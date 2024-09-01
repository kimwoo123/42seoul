#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	std::srand(std::time(0));
	int	r = std::rand() % 3;

	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "This Pointer is type A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "This Pointer is type B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "This Pointer is type C" << std::endl;
	else
		std::cout << "This Pointer is type Unknown" << std::endl;
}

void identify(Base& p) {
	Base temp;

	try {
		temp = dynamic_cast<A&>(p);
		std::cout << "This Reference is type A" << std::endl;
	}
	catch (std::exception& e) {}

	try {
		temp = dynamic_cast<B&>(p);
		std::cout << "This Reference is type B" << std::endl;
	}
	catch (std::exception& e) {}

	try {
		temp = dynamic_cast<C&>(p);
		std::cout << "This Reference is type C" << std::endl;
	}
	catch (std::exception& e) {}
}

int main() {
	Base* p = generate();
	Base& r = *p;

	identify(p);
	identify(r);

	delete p;
	return 0;
}
