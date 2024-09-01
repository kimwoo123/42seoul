#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	const Brain* a = new Brain();
	const Brain b;
	// called copy constructor
	Brain d = b;
	// called default constructor
	Brain c;

	// called assignment
	c = b;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << i->getType();
	i->makeSound();
	std::cout << j->getType();
	j->makeSound();

	delete j;
	delete i;
	delete a;
	
	Cat x;
	Dog y;

	return 0;
}
