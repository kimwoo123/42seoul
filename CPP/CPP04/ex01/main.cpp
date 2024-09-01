#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	Brain* a = new Brain();
	Brain b;
	// called copy constructor
	Brain d = b;
	// called default constructor
	Brain c;

	// called assignment
	c = b;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();

	delete j;
	delete i;
	delete a;
	
	Cat x;
	Dog y;
	/*
	Dog a;
	Dog b;
	a = b;
	*/
	return 0;
}
