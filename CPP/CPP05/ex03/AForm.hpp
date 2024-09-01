#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(std::string name);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm& f);
		AForm& operator=(const AForm& f);
		virtual ~AForm(void);

		const std::string& getName(void) const;
		const bool&	getSigned(void) const;
		const int&	getSignGrade(void) const;
		const int&	getExecGrade(void) const;

		void	setSigned(const bool& s);
		void	beSigned(const Bureaucrat& b);
		virtual void	execute(Bureaucrat const& executor) const = 0;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class NoSignException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		AForm(void);

		const	std::string	name_;
		bool	signed_;
		const int	signGrade_;
		const int	execGrade_;
};

std::ostream& operator<<(std::ostream& o, const AForm& a);
#endif
