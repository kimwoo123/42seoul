#include "Zombie.hpp"

int main()
{
	Zombie* A;
	Zombie* B;
	Zombie C("who");
	
	A = newZombie("Sarah");
	A->announce();
	B = newZombie("Jim");
	randomChump("Kim");
	C.announce();
	delete A;
	delete B;
	return (0);
}
