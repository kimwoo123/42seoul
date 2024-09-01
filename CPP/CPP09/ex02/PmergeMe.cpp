#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& p) {
	*this = p;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& p) {
	if (this != &p) {
		std::cout << "unused" << std::endl;
	}
	return *this;
}

PmergeMe::~PmergeMe(void) {}

void	PmergeMe::split(const	std::string& str, std::vector<int>* v) {
    std::istringstream iss(str);
    int num;
    
    while (iss >> num) {
        v->push_back(num);
    }
}

std::vector<int>	PmergeMe::charToVector(int argc, char **argv) {
	std::string	str;
	std::vector<int>	result;

	for (int i = 1; i < argc; ++i) {
		str = str + argv[i] + ' ';
	}
	split(str, &result);
	return result;
}

void	PmergeMe::isDuplicated(const std::vector<int>& v) {
	for(std::size_t i = 0; i < v.size(); ++i) {
		if (v[i] <= 0)
			throw std::runtime_error("ERror: only positive number");
		for (std::size_t j = i + 1; j < v.size(); ++j) {
			if (v[i] == v[j])
				throw std::runtime_error("Error: duplicated arg");
		}
	}
}

void	PmergeMe::isSorted(const std::vector<int>& v) {
	for(std::size_t i = 1; i < v.size(); ++i) {
		if (v[i] < v[i-1])
			return;
	}
	throw std::runtime_error("Error: already sorted.");
}

void	PmergeMe::isValidArg(const std::vector<int>& v) {
	if (v.size() < 2)
		throw std::runtime_error("Error: need number size more than 2");
	isDuplicated(v);
	isSorted(v);
}
void	PmergeMe::fordJohnson(std::deque<int>& d) {
	std::deque<int>	oddNumber;
	if (d.size() % 2) {
		oddNumber.push_back(d.back());
		d.pop_back();
	}

	std::deque<std::pair<int, int> > pairDeque;
	for (std::size_t i = 0; i < d.size(); i += 2)
		pairDeque.push_back(std::make_pair(d[i], d[i + 1]));

	for (std::size_t i = 0; i < pairDeque.size(); ++i) {
		if (pairDeque[i].first < pairDeque[i].second)
			std::swap(pairDeque[i].first, pairDeque[i].second);
	}

	std::pair<int, int>	key;
	std::size_t	j;
	for (std::size_t i = 1; i < pairDeque.size(); ++i) {
		key = pairDeque[i];
		j = i;
		while (j > 0 && pairDeque[j - 1] > key) {
			pairDeque[j] = pairDeque[j - 1];
			--j;
		}
		pairDeque[j] = key;
	}

	std::deque<int>	main;
	std::deque<int>	remain;
	for (std::size_t i = 0; i < pairDeque.size(); ++i) {
		main.push_back(pairDeque[i].first);
		remain.push_back(pairDeque[i].second);
	}
	
	main.insert(main.begin(), remain[0]);

	std::size_t	jacob;
	std::deque<std::size_t> jacobSeq;
	jacobSeq.push_back(1);
	jacobSeq.push_back(3);

	for (std::size_t i = 2; ; ++i) {
		jacob = jacobSeq[i - 1] + 2 * jacobSeq[i - 2];
		jacobSeq.push_back(jacob);
		if (jacob >= remain.size())
			break;
	}

	std::size_t	max;
	std::size_t	min;
	int	value;
	for (std::size_t i = 1; i < jacobSeq.size(); ++i) {
		max = std::min(jacobSeq[i], remain.size());
		min = jacobSeq[i - 1];
		for (std::size_t j = max - 1; j >= min; --j) {
			value = remain[j];
			main.insert(std::lower_bound(main.begin(), main.end(), value), value);
		}
	}

	if (oddNumber.size()) {
		int	odd = oddNumber.front();
		main.insert(std::lower_bound(main.begin(), main.end(), odd), odd);
	}
	d = main;
}

void	PmergeMe::fordJohnson(std::vector<int>& v) {
	std::vector<int>	oddNumber;
	if (v.size() % 2) {
		oddNumber.push_back(v.back());
		v.pop_back();
	}

	std::vector<std::pair<int, int> > pairVector;
	for (std::size_t i = 0; i < v.size(); i += 2)
		pairVector.push_back(std::make_pair(v[i], v[i + 1]));

	for (std::size_t i = 0; i < pairVector.size(); ++i) {
		if (pairVector[i].first < pairVector[i].second)
			std::swap(pairVector[i].first, pairVector[i].second);
	}

	std::pair<int, int>	key;
	std::size_t	j;
	for (std::size_t i = 1; i < pairVector.size(); ++i) {
		key = pairVector[i];
		j = i;
		while (j > 0 && pairVector[j - 1] > key) {
			pairVector[j] = pairVector[j - 1];
			--j;
		}
		pairVector[j] = key;
	}

	std::vector<int>	main;
	std::vector<int>	remain;

	for (std::size_t i = 0; i < pairVector.size(); ++i) {
		main.push_back(pairVector[i].first);
		remain.push_back(pairVector[i].second);
	}

	main.insert(main.begin(), remain[0]);

	std::size_t	jacob;
	std::vector<std::size_t> jacobSeq;
	jacobSeq.push_back(1);
	jacobSeq.push_back(3);
	for (std::size_t i = 2; ; ++i) {
		jacob = (jacobSeq[i - 1] + 2) * jacobSeq[i - 2];
		jacobSeq.push_back(jacob);
		if (jacob >= remain.size())
			break ;
	}

	std::size_t	max;
	std::size_t	min;
	int	value;
	for (std::size_t i = 1; i < jacobSeq.size(); ++i) {
		max = std::min((jacobSeq[i]), remain.size());
		min = jacobSeq[i - 1];
		for (std::size_t j = max - 1; j >= min; --j) {
			value = remain[j];
			main.insert(std::lower_bound(main.begin(), main.end(), value), value);
		}
	}

	if (oddNumber.size()) {
		int	odd = oddNumber.front();
		main.insert(std::lower_bound(main.begin(), main.end(), odd), odd);
	}
	v = main;
}

void	PmergeMe::execute(int argc, char** argv) {
	double	start_time = clock();
	std::vector<int>	arg = charToVector(argc, argv);
	double	v_time, d_time;

	isValidArg(arg);
	executeDeque(arg);
	v_time = static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC;
	start_time = clock();
	executeVector(arg);
	d_time = static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC;
	std::cout << "Time to precess a range of " << arg.size() << " elements with std::vector : " << v_time << " us" << std::endl;
	std::cout << "Time to precess a range of " << arg.size() << " elements with std::deque : " << d_time << " us" << std::endl;
}

void	PmergeMe::executeVector(const std::vector<int>& origin) {
	std::vector<int>	arg(origin.begin(), origin.end());

	std::cout << "Before: ";
	show(arg);
	fordJohnson(arg);
	std::cout << "After: ";
	show(arg);

}

void	PmergeMe::executeDeque(const std::vector<int>& origin) {
	std::deque<int>	arg(origin.begin(), origin.end());

	std::cout << "Before: ";
	show(arg);
	fordJohnson(arg);
	std::cout << "After: ";
	show(arg);
}

