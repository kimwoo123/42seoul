#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <iterator>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack(void);
		MutantStack(const MutantStack& m);
		MutantStack& operator=(const MutantStack& m);
		~MutantStack(void);

		typedef typename MutantStack<T>::container_type::iterator iterator;
		typedef typename MutantStack<T>::container_type::const_iterator const_iterator;

		iterator	begin();
		iterator	end();

		const_iterator	begin() const;
		const_iterator	end() const;
};

template <typename T>
MutantStack<T>::MutantStack(void) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& m) {
	*this = m;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack& m) {
	if (this != m)
		std::stack<T>::operator=(m);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

template<typename T>
typename MutantStack<T>::iterator 	MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator 	MutantStack<T>::end() {
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator 	MutantStack<T>::begin() const {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator 	MutantStack<T>::end() const {
	return this->c.end();
}

#endif
