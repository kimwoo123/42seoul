#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& s);
		ScavTrap& operator=(const ScavTrap& s);
		~ScavTrap(void);
		void guardGate(void);
		void attack(std::string const& target);
};
#endif
