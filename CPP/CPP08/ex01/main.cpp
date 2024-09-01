#include "Span.hpp"

int main() {
	Span sp = Span(5);
	
	sp.addNumber(6);
	try {
		sp.shortestSpan();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try {
		sp.addNumber(11);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span s = Span(4);

	std::vector<int> a;
	a.push_back(9);
	a.push_back(6);
	a.push_back(3);
	a.push_back(11);
	s.addNumberIter(a.begin(), a.end());

	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.longestSpan() << std::endl;

	return 0;
}
