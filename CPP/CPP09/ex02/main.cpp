#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <number list>" << std::endl;
		return 1;
	}
	try {
		PmergeMe	p;

		p.execute(argc, argv);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
