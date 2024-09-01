#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string name) : name_(name), weapon_(NULL){};
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);

	private:
		std::string	name_;
		Weapon		*weapon_;

};
#endif
