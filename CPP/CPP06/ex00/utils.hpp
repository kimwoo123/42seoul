#ifndef UTILS_HPP
# define UTILS_HPP

# include <cmath>
# include <cstdlib>
# include <limits>
# include <string>
# include <iostream>
# include <iomanip>

enum type {
	kChar,
	kDouble,
	kFloat,
	kInt,
	kInf,
	kNan,
	kImpossible
};

bool	isNan(const std::string& arg);
bool	isInf(const std::string& arg);
bool	isChar(const std::string& arg);
bool	isInt(const std::string& arg);
bool	isFloat(const std::string& arg);
bool	isDouble(const std::string& arg);
void	printInt(const std::string& arg);
void	printFloat(const std::string& arg);
void	printDouble(const std::string& arg);
void	printChar(const std::string& arg);
void	printNan(const std::string& arg);
void	printInf(const std::string& arg);
void	printImpossible(void);
int	parseArg(const std::string& arg);
#endif
