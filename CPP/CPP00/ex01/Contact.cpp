#include "Contact.hpp"

std::string	Contact::get_first_name(void) const
{
	std::string	input;

	std::cout << "enter the first_name" << std::endl;
	std::getline(std::cin, input);
	while (input.length() == 0)
	{
		if (std::cin.eof())
			exit(1);
		std::cout << "enter the valid first_name" << std::endl;
		std::getline(std::cin, input);
	}
	return (input);
}

std::string	Contact::get_last_name(void) const
{
	std::string	input;

	std::cout << "enter the last_name" << std::endl;
	std::getline(std::cin, input);
	while (input.length() == 0)
	{
		if (std::cin.eof())
			exit(1);
		std::cout << "enter the valid last_name" << std::endl;
		std::getline(std::cin, input);
	}
	return (input);
}

std::string	Contact::get_nickname(void) const
{
	std::string	input;

	std::cout << "enter the nickname" << std::endl;
	std::getline(std::cin, input);
	while (input.length() == 0)
	{
		if (std::cin.eof())
			exit(1);
		std::cout << "enter the valid nickname" << std::endl;
		std::getline(std::cin, input);
	}
	return (input);
}

std::string	Contact::get_phone_number(void) const
{
	std::string	input;

	std::cout << "enter the phone_number" << std::endl;
	std::getline(std::cin, input);
	while (input.length() == 0)
	{
		if (std::cin.eof())
			exit(1);
		std::cout << "enter the phone_number" << std::endl;
		std::getline(std::cin, input);
	}
	return (input);
}

std::string	Contact::get_darkest_secret(void) const
{
	std::string	input;

	std::cout << "enter the darkest_secret" << std::endl;
	std::getline(std::cin, input);
	while (input.length() == 0)
	{
		if (std::cin.eof())
			exit(1);
		std::cout << "enter the darkest_secret" << std::endl;
		std::getline(std::cin, input);
	}
	return (input);
}

void    Contact::print_info(int info) const
{
    if (info == FIRST_NAME_OUT)
    {
        if (this->first_name_.size() > 10)
            std::cout << std::string(this->first_name_.begin(), this->first_name_.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << this->first_name_;
    }
    if (info == LAST_NAME_OUT)
    {
        if (this->last_name_.size() > 10)
            std::cout << std::string(this->last_name_.begin(), this->last_name_.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << this->last_name_;
    }
    if (info == NICKNAME_OUT)
    {
        if (this->nickname_.size() > 10)
            std::cout << std::string(this->nickname_.begin(), this->nickname_.begin() + 9) << '.';
        else
            std::cout << std::setw(10) << this->nickname_;
    }
}

void	Contact::set_contact(void)
{
	this->first_name_ = Contact::get_first_name();
	this->last_name_ = Contact::get_last_name();
	this->nickname_ = Contact::get_nickname();
	this->phone_number_ = Contact::get_phone_number();
	this->darkest_secret_ = Contact::get_darkest_secret();
}
