#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <iostream>

class	NotFoundException: public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Not found";
		}
};

template<typename T>
bool easyfind(T& t, int i) {
	if (std::find(t.begin(), t.end(), i) == t.end())
		throw NotFoundException();
	return(true);
}
#endif
