#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	b("SCAV");
	ClapTrap	c("CLAP");

	b.guardGate();
	b.attack("Eric");
	c.attack("Eric");
	b.takeDamage(100);
	c.takeDamage(100);
	b.beRepaired(3);
	c.beRepaired(6);
	b.guardGate();
	b.attack("Eric");
}
