#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void	set_name(std::string name);
		void	announce(void) const;

	private:
		std::string name_;
};

Zombie*	zombieHorde(int N, std::string name);
