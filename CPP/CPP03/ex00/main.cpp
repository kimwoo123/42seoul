#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("A");
	a.takeDamage(10);
	a.takeDamage(1000);
	a.beRepaired(10);
	a.attack("b");
	return (0);
}
