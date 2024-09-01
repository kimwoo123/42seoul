#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &c);
		~ClapTrap(void);
		ClapTrap& operator=(const ClapTrap& c);
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	protected:
		std::string	name_;
		unsigned int	hit_;
		unsigned int	damage_;
		unsigned int	energy_;
};
#endif
