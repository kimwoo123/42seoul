#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <vector>

class Span {
	public:
		Span(unsigned int size);
		Span(const Span& s);
		Span& operator = (const Span& s);
		~Span(void);

		void	addNumber(int number);
		void	addNumberIter(std::vector<int>::iterator first, std::vector<int>::iterator last);
		int	shortestSpan(void);
		int	longestSpan(void);

		class ContainerIsFull: public std::exception {
			virtual const char *what() const throw() {
				return ("Array is full");
			}
		};

		class ContainerIsSmall: public std::exception {
			virtual const char *what() const throw() {
				return ("Array is small");
			}
		};

	private:
		std::vector<int>	array_;
		unsigned int	size_;
		Span(void);
};
#endif
