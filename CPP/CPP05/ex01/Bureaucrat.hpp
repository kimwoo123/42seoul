#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& b);
		Bureaucrat& operator=(Bureaucrat const& b);
		~Bureaucrat(void);

		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(Form &f);

		int	getGrade(void) const;
		const std::string	getName(void) const;
		void	setGrade(const int new_grade);

		class Exception: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException: public Bureaucrat::Exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public Bureaucrat::Exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	name_;
		int	grade_;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& b);

#endif
