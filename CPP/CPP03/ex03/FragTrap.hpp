#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& f);
		FragTrap& operator=(const FragTrap& f);
		~FragTrap(void);
		void	highFivesGuys(void);
};
#endif
