#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a("DIA");

	//a.checkRelate();
	a.whoAmI();
	a.attack("enemy");
	a.takeDamage(100);
	a.attack("enemy");
	a.whoAmI();
}
