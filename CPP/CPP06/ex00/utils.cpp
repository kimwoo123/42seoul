#include "utils.hpp"

bool	isNan(const std::string& arg) {
	if (arg == "nan" || arg == "nanf")
		return true;
	return false;
}

bool	isInf(const std::string& arg) {
	std::string	dest[6] = {"inf", "inff", "+inf", "-inf", "+inff", "-inff"};

	for (int i = 0; i < 6; ++i) {
		if (arg == dest[i])
			return true;
	}
	return false;
}

bool	isChar(const std::string& arg) {
	if (arg.size() == 1) {
		if (std::isprint(arg.at(0)) != 0)
			return true;
	}
	return false;
}

// it could be only +, - but it can filtered by isChar() function by order
bool	isInt(const std::string& arg) {
	unsigned long	index = 0;
	unsigned long	len = arg.length();

	if (arg[index] == '+' || arg[index] == '-')
		++index;

	while (index < len) {
		if (std::isdigit(arg[index]) == false)
			return false;
		++index;
	}
	return true;
}

bool	isFloat(const std::string& arg) {
	unsigned long	index = 0;
	bool hasDecimal = false;
	int numDigits = 0;

	if (arg[index] == '+' || arg[index] == '-')
		++index;
	if (arg[index] == '.')
		return false;

    for (; index < arg.length() - 1; ++index) {
        if (std::isdigit(arg[index])) {
            numDigits++;
        } else if (arg[index] == '.' && !hasDecimal) {
            hasDecimal = true;
        } else {
            return false;
        }
    }
	if (arg[arg.size() -1] != 'f')
		return false;
    return numDigits > 0 && (hasDecimal || numDigits == 1);
}

bool	isDouble(const std::string& arg) {
	unsigned long	index = 0;
	bool hasDecimal = false;
	int numDigits = 0;

	if (arg[index] == '+' || arg[index] == '-')
		++index;
	if (arg[index] == '.')
		return false;

    for (; index < arg.length(); ++index) {
        if (std::isdigit(arg[index])) {
            numDigits++;
        } else if (arg[index] == '.' && !hasDecimal) {
            hasDecimal = true;
        } else {
            return false;
        }
    }
    return numDigits > 0 && (hasDecimal || numDigits == 1);

}

void	printInt(const std::string& arg) {
	char* endptr = NULL;
	int64_t num = std::strtol(arg.c_str(), &endptr, 10);

	if (endptr != NULL && *endptr != '\0')
		return printImpossible();
	if (num < 0 || num > 255)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(num))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	double limit = std::strtod(arg.c_str(), NULL);
	if (limit < ((-1) * std::numeric_limits<float>::max()) || limit > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else {
		if (num < 1.0e+06f)
			std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	}
	if (limit < ((-1) * std::numeric_limits<double>::max()) || limit > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else {
		if (num < 1.0e+06)
			std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
}

void	printFloat(const std::string& arg) {
	float num = std::atof(arg.c_str());
	float integral, fractional;
	fractional = std::modf(num, &integral);

	char* endptr = NULL;
	double limit = std::strtod(arg.c_str(), &endptr);
	if (endptr != NULL && *endptr != 'f')
		return printImpossible();
	if (num < 0 || num > 255)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(num))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (limit < std::numeric_limits<int>::min() || limit > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (fractional == 0 && num < 1.0e+06) {
		if (limit < ((-1) * std::numeric_limits<float>::max()) || limit > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << num << ".0f" << std::endl;
		if (limit < ((-1) * std::numeric_limits<double>::max()) || limit > std::numeric_limits<double>::max())
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
	}
	else {
		if (limit < ((-1) * std::numeric_limits<float>::max()) || limit > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::scientific << num << "f" << std::endl;
		if (limit < ((-1) * std::numeric_limits<double>::max()) || limit > std::numeric_limits<double>::max())
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::scientific << static_cast<double>(num) << std::endl;
	}
}

void	printDouble(const std::string& arg) {
	char* endptr = NULL;
	double num = std::strtod(arg.c_str(), &endptr);
	double integral, fractional;
	fractional = std::modf(num, &integral);

	if (endptr != NULL && *endptr != '\0')
		return printImpossible();
	if (num < 0 || num > 255)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(num))
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (fractional == 0 && num < 1.0e+06) {
		if (num < ((-1) * std::numeric_limits<float>::max()) || num > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
		if (num < ((-1) * std::numeric_limits<double>::max()) || num > std::numeric_limits<double>::max())
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << num << ".0" << std::endl;
	}
	else {
		if (num < ((-1) * std::numeric_limits<float>::max()) || num > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::scientific << static_cast<float>(num) << "f" << std::endl;
		if (num < ((-1) * std::numeric_limits<double>::max()) || num > std::numeric_limits<double>::max())
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::scientific << num << std::endl;
	}
}

void	printChar(const std::string& arg) {
	char c = arg.at(0);

	if (std::isprint(c))
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printNan(const std::string& arg) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (arg == "nan") {
		double nan = std::numeric_limits<double>::quiet_NaN();
		std::cout << "float: " << static_cast<float>(nan) << "f" << std::endl;
		std::cout << "double: " << nan << std::endl;
	}
	else {
		float nan = std::numeric_limits<float>::quiet_NaN();

		std::cout << "float: " << nan << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nan) << std::endl;
	}
}

void	printInf(const std::string& arg) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	std::size_t index = arg.find("inff");
	if (index != std::string::npos) {
		float inf = std::numeric_limits<float>::infinity();

		if (arg.at(0) == '-')
			inf *= -1;
		std::cout << "float: " << inf << "f"<< std::endl;
		std::cout << "double: " << static_cast<double>(inf) << std::endl;
	}
	else {
		double inf = std::numeric_limits<double>::infinity();

		if (arg.at(0) == '-')
			inf *= -1;
		std::cout << "float: " << static_cast<float>(inf) << "f" << std::endl;
		std::cout << "double: " << inf << std::endl;
	}
}

void	printImpossible(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

int	parseArg(const std::string& arg) {
	if (isNan(arg) == true)
		return kNan;
	if (isInf(arg) == true)
		return kInf;
	if (isChar(arg) == true)
		return kChar;
	if (isInt(arg) == true)
		return kInt;
	if (isFloat(arg) == true)
		return kFloat;
	if (isDouble(arg) == true)
		return kDouble;
	return kImpossible;
}
