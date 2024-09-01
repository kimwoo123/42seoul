#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	printElem(const T& t) {
	std::cout << t << std::endl;
}

template <typename T, typename F>
void	iter(T* array, size_t size, F func) {
	for (size_t i = 0; i < size; ++i)
		func(array[i]);
}
#endif
