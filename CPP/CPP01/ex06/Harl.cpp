#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "debug: " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "info: " << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "warning: " << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "error: " << "This is unacceptable! I want to speak to the manager now\n";
}

void	Harl::filter(std::string level)
{
	HarlMemFn table = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index;

	index = 0;
	for (; index < 4; ++index)
	{
		if (complains[index] == level)
			break ;
	}
	switch(index)
	{
		case(LEVEL_DEBUG):
			(this->*table[LEVEL_DEBUG])();
		case(LEVEL_INFO):
			(this->*table[LEVEL_INFO])();
		case(LEVEL_WARNING):
			(this->*table[LEVEL_WARNING])();
		case(LEVEL_ERROR):
			(this->*table[LEVEL_ERROR])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}
