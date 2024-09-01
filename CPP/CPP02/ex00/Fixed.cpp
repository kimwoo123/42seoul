#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";

	this->number_ = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";

	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	this->number_ = fixed.getRawBits();

	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";

	return (this->number_);
}

void	Fixed::setRawBits(int const raw)
{
	this->number_ = raw;
}
