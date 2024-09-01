#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& a);
		Animal& operator=(const Animal& a);
		virtual ~Animal();
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		
	protected:
		std::string type_;
};
#endif
