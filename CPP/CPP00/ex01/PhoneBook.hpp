#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iostream>
#include "Contact.hpp"

class PhoneBook 
{

	public:
		PhoneBook() : contacts_(), count_(0) {}
		void	set_info(void);
		void	exit_prompt(void) const;
		void	search_info(void) const;
		void	display_info(void) const;
		void	select_index(int max_index) const;
		bool	is_valid(std::string input, int max_index) const;

	private:
		Contact contacts_[8];
		int		count_;
};
#endif
