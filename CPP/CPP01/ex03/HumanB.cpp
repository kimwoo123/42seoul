#include "HumanB.hpp"

void	HumanB::attack(void) const
{
	if (this->weapon_ == NULL)
		std::cout << this->name_ << " attacks with their " << "punch\n";
	else
		std::cout << this->name_ << " attacks with thier " << this->weapon_->getType() << "\n";
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon_ = &weapon;
}
