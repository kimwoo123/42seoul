#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;

	private:
		std::string	name_;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
