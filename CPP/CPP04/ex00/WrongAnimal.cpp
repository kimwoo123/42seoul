#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type_ = "animal";
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
{
	this->type_ = a.type_;
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
	this->type_ = a.type_;
	std::cout << "WrongAnimal assign operator called\n";
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called\n";
}

std::string	WrongAnimal::getType(void) const
{
	return this->type_;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal~\n";
}

