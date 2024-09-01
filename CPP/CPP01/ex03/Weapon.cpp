#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	Weapon::setType(type);
}

const std::string&	Weapon::getType(void) const
{
	return this->type_;
}

void	Weapon::setType(std::string type)
{
	this->type_ = type;
}

