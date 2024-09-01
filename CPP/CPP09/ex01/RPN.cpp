#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN& r) {
	*this = r;
}

RPN& RPN::operator=(const RPN& r) {
	if (this != &r)
		this->stack_ = r.stack_;
	return *this;
}

RPN::~RPN(void) {}

RPN::RPN(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage : " << argv[0] << " \"expression\"" << std::endl;
		return;
	}
	if (isValidExpr(argv[1]) == false) {
		std::cout << "Error: invalid expr" << std::endl;
		return;
	}
	runCalculator(argv[1]);
}

bool	RPN::isOper(const char c) {
	return (c == '+' || c == '-' || c == '*' || c== '/');
}

bool	RPN::isValidExpr(const std::string& expr) {
	std::size_t	index = 0;

	for (; index < expr.length(); ++index) {
		if (std::isdigit(expr[index])) {
			if (std::isspace(expr[index + 1] == 0 && index + 1 != expr.length()))
				return false;
		}
		else if (isOper(expr[index]) == true) {
			if (std::isspace(expr[index + 1] == 0 && index + 1 != expr.length()))
				return false;
		}
		else if (std::isspace(expr[index]))
			continue;
		else
			return false;
	}
	return true;
}

int	RPN::calculate(const int a, const int b, const char oper) {
	switch (oper) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: divided by 0 occur\n");
			return a / b;
	}
	return 0;
}

void	RPN::operate(const char oper) {
	if (this->stack_.size() < 2)
		throw std::runtime_error("Error: operand in stack is under two\n");

	int	b = this->stack_.top();
	this->stack_.pop();
	int	a = this->stack_.top();
	this->stack_.pop();

	int	result = calculate(a, b, oper);
	this->stack_.push(result);
}

void	RPN::runCalculator(const std::string& expr) {
	std::size_t	index = 0;

	for(; index < expr.length(); ++index) {
		if (std::isdigit(expr[index])) 
			this->stack_.push(expr[index] - '0');
		else if (isOper(expr[index]) == true)
			operate(expr[index]);
	}
	if (this->stack_.size() != 1) {
		std::cout << "Error: not one value remain in stack" << std::endl;
		return;
	}
	std::cout << this->stack_.top() << std::endl;
}
