#include "Animal.hpp"

Animal::Animal(void)
{
	this->type_ = "animal";
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& a)
{
	this->type_ = a.type_;
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& a)
{
	this->type_ = a.type_;
	std::cout << "Animal assign operator called\n";
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
}

std::string	Animal::getType(void) const
{
	return this->type_;
}

