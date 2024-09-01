#include "Dog.hpp"

Dog::Dog(void)
{
	this->type_ = "dog";
	this->brain_ = new Brain();
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& d)
{
	this->type_ = d.type_;
	this->brain_ = d.brain_;
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& d)
{
	this->type_ = d.type_;
	this->brain_ = d.brain_;
	std::cout << "Dog assign operator called\n";

	return *this;
}

Dog::~Dog(void)
{
	delete this->brain_;
	std::cout << "Dog deconstructor called\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark~\n";
}
