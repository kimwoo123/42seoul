#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& w);
		WrongCat& operator=(const WrongCat& w);
		~WrongCat();
		std::string getType(void) const;
		void	makeSound(void) const;
};
#endif
