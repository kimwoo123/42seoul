#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &d);
		~DiamondTrap(void);
		DiamondTrap &operator=(const DiamondTrap &d);

		void attack(const std::string &target);
		void whoAmI(void);

		void checkRelate() const;
	
	private:
		std::string name_;
};

#endif
