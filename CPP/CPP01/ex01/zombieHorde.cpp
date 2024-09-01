#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "horde parameter need pos int\n";
		return (NULL);
	}

	Zombie *horde = new Zombie[N];
	while (N > 0)
	{
		--N;
		horde[N].set_name(name);
	}
	return horde;
}
