#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP

# include "AForm.hpp"

class PresidentialPardon: public AForm {
	public:
		PresidentialPardon(const std::string& name);
		PresidentialPardon(const PresidentialPardon& p);
		PresidentialPardon& operator=(const PresidentialPardon& p);
		~PresidentialPardon(void);

		void execute(Bureaucrat const& executor) const;

	private:
		PresidentialPardon(void);
};
#endif
