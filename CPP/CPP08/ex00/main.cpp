#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}

	std::cout << "try to find 10 in vector." << std::endl;
	try {
		easyfind(v, 9);
		std::cout << "found 9 in vector." << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "try to find 15 in deque." << std::endl;
	try {
		easyfind(d, 15);
		std::cout << "found 15 in deque." << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "try to find 0 in list." << std::endl;
	try {
		easyfind(l, 0);
		std::cout << "found 0 in list." << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
