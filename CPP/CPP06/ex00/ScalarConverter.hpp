#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "utils.hpp"

class ScalarConverter {
	public:
		static void	convert(const std::string& arg);

	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter& s);
		ScalarConverter& operator=(const ScalarConverter& s);	
};
#endif
