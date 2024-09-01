#include "Cat.hpp"

Cat::Cat(void)
{
	this->type_ = "cat";
	this->brain_ = new Brain();
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& c)
{
	this->type_ = c.type_;
	this->brain_ = c.brain_;
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& c)
{
	this->type_ = c.type_;
	this->brain_ = c.brain_;
	std::cout << "Cat assign operator called\n";

	return *this;
}

Cat::~Cat(void)
{
	delete this->brain_;
	std::cout << "Cat deconstructor called\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~\n";
}
