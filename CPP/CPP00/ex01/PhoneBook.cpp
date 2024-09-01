#include "PhoneBook.hpp"

void	PhoneBook::set_info(void)
{
	std::string input;

	this->contacts_[this->count_ % 8].set_contact();
	this->count_ = this->count_ + 1;
}

bool	PhoneBook::is_valid(std::string input, int max_index) const
{
	if (max_index > 8)
		max_index = 8;
	if (input.size() == 1)
	{
		if (input[0] >= 49 && input[0] <= 49 + max_index)
			return (true);
	}
	return (false);
}

void	PhoneBook::select_index(int max_index) const
{
	std::string	input;
	int			index;

	std::cout << "enter the index\n";
	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (is_valid(input, max_index) == true)
		{
			index = input[0] - 49;
			std::cout << "|-------------------------------------------|\n";		
			std::cout << "|" << std::setw(10) << index + 1 << "|";
			this->contacts_[index].print_info(FIRST_NAME_OUT);
			std::cout << "|";
		 	this->contacts_[index].print_info(LAST_NAME_OUT);
			std::cout << "|";
			this->contacts_[index].print_info(NICKNAME_OUT);
	        std::cout << "|\n";
			std::cout << "|-------------------------------------------|\n";
			break ;
		}
		else
			std::cout << "enter valid index(1 ~ 8)\n";
	}
}

void	PhoneBook::display_info(void) const
{
	int	index;

	index = 0;
	if (this->count_ == 0)
	{
		std::cout << "Phonebook is empty\n";
		return ;
	}
	std::cout << "|-------------------------------------------|\n";		
	std::cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|\n";		
	std::cout << "|-------------------------------------------|\n";
	while (index < 8)
	{
		if (this->count_ <= index)
			break ;
		std::cout << "|" << std::setw(10) << index + 1 << "|";
		this->contacts_[index].print_info(FIRST_NAME_OUT);
        std::cout << "|";
		this->contacts_[index].print_info(LAST_NAME_OUT);
        std::cout << "|";
		this->contacts_[index].print_info(NICKNAME_OUT);
        std::cout << "|\n";
        std::cout << "|-------------------------------------------|\n";
		++index;
	}
	PhoneBook::select_index(index - 1);
}

void	PhoneBook::exit_prompt(void) const
{
	std::cout << "close PhoneBook\n";
	exit(0);
}

void	PhoneBook::search_info(void) const
{
	PhoneBook::display_info();
}
