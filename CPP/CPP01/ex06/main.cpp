#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl h;

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
	else
		h.filter(static_cast<std::string>(argv[1]));
}
