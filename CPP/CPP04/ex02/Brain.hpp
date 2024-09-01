#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& b);
		Brain& operator=(const Brain& b);
		~Brain();

	private:
		std::string* ideas_;
};
#endif
