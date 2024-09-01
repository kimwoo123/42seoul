#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {
	public:
		RPN(int argc, char** argv);
		~RPN(void);

	private:
		RPN(void);
		RPN(const RPN& r);
		RPN& operator=(const RPN& r);

		bool	isOper(const char c);
		bool	isValidExpr(const std::string& expr);
		void	operate(const char oper);
		void	runCalculator(const std::string& expr);
		int	calculate(const int a, const int b, const char oper);

		std::stack<int>	stack_;
};
#endif
