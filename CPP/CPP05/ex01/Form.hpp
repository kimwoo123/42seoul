#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(std::string name);
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& f);
		Form& operator=(const Form& f);
		~Form(void);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		const std::string& getName(void) const;
		const bool&	getSigned(void) const;
		const int&	getSignGrade(void) const;
		const int&	getExecGrade(void) const;

		void	beSigned(const Bureaucrat& b);

	private:
		Form(void);

		const	std::string	name_;
		bool	signed_;
		const int	signGrade_;
		const int	execGrade_;
};

std::ostream& operator<<(std::ostream& o, const Form& f);
#endif
