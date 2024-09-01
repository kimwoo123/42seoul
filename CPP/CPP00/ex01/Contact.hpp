#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <iostream>
#include <iomanip>
#define FIRST_NAME_OUT 0
#define LAST_NAME_OUT 1
#define NICKNAME_OUT 2

class Contact
{
	public:
		void		set_contact(void);
		void		print_info(int info) const;
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_darkest_secret(void) const;

	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;
};
#endif
