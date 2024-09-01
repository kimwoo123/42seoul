#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& s) {
	(void)s;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& s) {
	(void)s;
	return *this;
}

void	ScalarConverter::convert(const std::string& arg) {
	// need check size, but size 0 arg is can happen?
	switch (parseArg(arg)) {
		case kChar:
			return printChar(arg);
		case kDouble:
			return printDouble(arg);
		case kFloat:
			return printFloat(arg);
		case kInt:
			return printInt(arg);
		case kInf:
			return printInf(arg);
		case kNan:
			return printNan(arg);
		default:
			printImpossible();
	}
}
