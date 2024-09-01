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
	this->brain_ = new Brain(*(c.brain_));
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& c)
{
	if (this != &c)
	{
		Brain *temp = new Brain(*(c.brain_));

		delete this->brain_;
		this->brain_ = temp;
		this->type_ = c.type_;
	}
	std::cout << "Cat assign operator called\n";

	return *this;
}

Cat::~Cat(void)
{
	delete this->brain_;
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~\n";
}
