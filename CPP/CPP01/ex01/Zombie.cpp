#include "Zombie.hpp"


Zombie::Zombie()
{
	;
}


void	Zombie::announce(void) const
{
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string name)
{
	this->name_ = name;
}

Zombie::~Zombie(void)
{
	std::cout << this->name_ << ": is dead\n";
}
