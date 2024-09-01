#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon): name_(name), weapon_(weapon) {};
		void	attack(void) const;

	private:
		std::string	name_;
		Weapon		&weapon_;
};
#endif
