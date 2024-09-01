#include "Dog.hpp"

Dog::Dog(void)
{
	this->type_ = "dog";
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& a)
{
	this->type_ = a.type_;
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& a)
{
	this->type_ = a.type_;
	std::cout << "Dog assign operator called\n";

	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark~\n";
}
