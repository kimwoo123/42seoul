#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog& d);
		Dog& operator=(const Dog& d);
		~Dog();
		void	makeSound(void) const;

	private:
		Brain* brain_;
};
#endif
