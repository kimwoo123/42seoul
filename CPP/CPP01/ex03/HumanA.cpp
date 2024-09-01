#include "HumanA.hpp"

void	HumanA::attack(void) const
{
	std::cout << this->name_ << " attacks with thier " << this->weapon_.getType() << "\n";
}
