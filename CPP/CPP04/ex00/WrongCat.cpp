#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type_ = "wrong cat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& w)
{
	this->type_ = w.type_;
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& w)
{
	this->type_ = w.type_;
	std::cout << "WrongCat assign operator called\n";

	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called\n";
}

std::string		WrongCat::getType(void) const
{
	return this->type_;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Moew~\n";
}
