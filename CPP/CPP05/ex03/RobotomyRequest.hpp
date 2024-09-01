#ifndef ROBOTOMYREQUEST_HPP
# define ROBOTOMYREQUEST_HPP

# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequest: public AForm {
	public:
		RobotomyRequest(const std::string& name);
		RobotomyRequest(const RobotomyRequest& r);
		RobotomyRequest& operator=(const RobotomyRequest& r);
		~RobotomyRequest(void);

		void execute(Bureaucrat const &executor) const;

	private:
		RobotomyRequest(void);
};
#endif
