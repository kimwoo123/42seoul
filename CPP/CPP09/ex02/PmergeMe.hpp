#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>

class PmergeMe {
	public:
		PmergeMe(void);
		~PmergeMe(void);
		void	execute(int argc, char** argv);

	private:
		PmergeMe(const PmergeMe& p);
		PmergeMe& operator=(const PmergeMe& p);

		std::vector<int>	charToVector(int argc, char **argv);
		void	split(const std::string& str, std::vector<int>* result);
		void	isDuplicated(const std::vector<int>& v);
		void	isSorted(const std::vector<int>& v);
		void	isValidArg(const std::vector<int>& v);
		void	fordJohnson(std::vector<int>& v);
		void	fordJohnson(std::deque<int>& v);
		void	executeDeque(const std::vector<int>& origin);
		void	executeVector(const std::vector<int>& origin);

		template <typename T>
		void	show(const T& container) {
			typename T::const_iterator	it;

			for (it = container.begin(); it != container.end(); ++it) {
				std::cout << *it;
				if (it != container.end())
					std::cout << " ";
			}
			std::cout << std::endl;
		}
};


#endif
