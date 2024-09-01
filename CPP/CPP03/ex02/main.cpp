#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap	c("Clap");
	FragTrap	d("Frag");

	d.highFivesGuys();
	d.takeDamage(100);
	c.takeDamage(100);
	d.attack("ENEMY");
	c.attack("ENEMY");
	c.beRepaired(6);
	d.beRepaired(6);
}
