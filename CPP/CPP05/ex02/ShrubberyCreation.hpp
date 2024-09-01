#ifndef SHRUBBERYCREATION_HPP
# define SHRUBBERYCREATION_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreation: public AForm {
	public:
		ShrubberyCreation(const std::string& name);
		ShrubberyCreation(const ShrubberyCreation& s);
		ShrubberyCreation& operator=(const ShrubberyCreation& s);
		~ShrubberyCreation(void);

		void execute(Bureaucrat const &executor) const;

		class CannotOpenFileException: public std::exception {
		public:
			virtual const char* what() const throw();
		};

	private:
		ShrubberyCreation(void);
};
#endif
