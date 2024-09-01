#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardon.hpp"
# include "RobotomyRequest.hpp"
# include "ShrubberyCreation.hpp"

class Intern {
	public:
		Intern(void);
		~Intern(void);

		AForm* makeForm(const std::string& formName, const std::string& target);

		class FormDoesntExistException: public std::exception {
		public:
			virtual const char* what() const throw();
		};

	private:
		Intern(const Intern& i);
		Intern& operator=(const Intern& i);
};
#endif
