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
	this->brain_ = new Brain(*(d.brain_));
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& d)
{
	if (this != &d)
	{
		Brain *temp = new Brain(*(d.brain_));

		delete this->brain_;
		this->brain_ = temp;
		this->type_ = d.type_;
	}
	std::cout << "Dog assign operator called\n";

	return *this;
}

Dog::~Dog(void)
{
	delete this->brain_;
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark~\n";
}
