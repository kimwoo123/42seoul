#include "Zombie.hpp"

void	Zombie::announce(void) const
{
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name): name_(name)
{
	std::cout << this->name_ << ": alive\n";
}

Zombie::~Zombie(void)
{
	std::cout << this->name_ << ": is dead\n";
}
