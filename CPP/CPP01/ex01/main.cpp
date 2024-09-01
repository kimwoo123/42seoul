#include "Zombie.hpp"

int main()
{
	Zombie* horde;

	horde = zombieHorde(5, "Sarah");
	if (horde == NULL)
		return 0;
	horde[0].announce();
	horde[1].announce();
	horde[2].announce();
	delete[] horde;
	horde = zombieHorde(1, "Jim");
	if (horde == NULL)
		return 0;
	horde[0].announce();
	delete[] horde;
}
