#include "Cat.hpp"

Cat::Cat(void)
{
	this->type_ = "cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& a)
{
	this->type_ = a.type_;
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& a)
{
	this->type_ = a.type_;
	std::cout << "Cat assign operator called\n";

	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~\n";
}
