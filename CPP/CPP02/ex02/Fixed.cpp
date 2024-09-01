#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return (os << fixed.toFloat());
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->number_ = 0;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called\n";
	this->number_ = number << this->fraction_;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called\n";
	this->number_ = roundf(number * (1 << this->fraction_));
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	return this->number_;
}

void	Fixed::setRawBits(const int raw)
{
	this->number_ = raw;
}

float Fixed::toFloat(void) const
{
	return (this->number_ / static_cast<float>(1 << this->fraction_));
}

int	Fixed::toInt(void) const
{
	return (this->number_ >> this->fraction_);
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	this->number_ = fixed.number_;
	return *this;
}

// * + - /
Fixed Fixed::operator*(const Fixed& fixed)
{
	Fixed ret(this->toFloat() * fixed.toFloat());
	return ret;
}

Fixed Fixed::operator+(const Fixed& fixed)
{
	Fixed ret(this->toFloat() + fixed.toFloat());
	return ret;
}

Fixed Fixed::operator-(const Fixed& fixed)
{
	Fixed ret(this->toFloat() - fixed.toFloat());
	return ret;
}

Fixed Fixed::operator/(const Fixed& fixed)
{
	Fixed ret(this->toFloat() / fixed.toFloat());
	return ret;
}

// ++ --
Fixed& Fixed::operator++(void)
{
	this->number_ += 1;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->number_ -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp = *this;

	this->number_ += 1;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed	temp = *this;

	this->number_ -= 1;
	return temp;
}

// >, <, >=, <=, ==, !=
bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}
