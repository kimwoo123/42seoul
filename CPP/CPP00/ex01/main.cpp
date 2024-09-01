#include "main.hpp"

int	main(void)
{
	int			index;
	std::string	input;
	PhoneBook	phonebook;

	index = 0;
	while (true)
	{
		std::cout << "enter command: (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		else if (input == "ADD")
			phonebook.set_info();
		else if (input == "SEARCH")
			phonebook.search_info();
		else if (input == "EXIT")
			phonebook.exit_prompt();
		else
			std::cout << "command not found" << std::endl;
	}
	return 0;
}
