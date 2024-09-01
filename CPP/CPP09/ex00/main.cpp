#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <txtfile>" << std::endl;
		return 1;
	}

	BitcoinExchange b;

	b.run(argv[1]);
}
