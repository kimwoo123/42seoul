#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <sstream>
# include <fstream>
# include <iostream>
# include <map>

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& b);
		BitcoinExchange& operator=(const BitcoinExchange& b);
		~BitcoinExchange(void);
		void	run(const std::string& arg);

	private:
		void	readCsvFile(void);
		void	parseCsvLine(const std::string& line);
		bool	isValidValue(const std::string& value);
		bool	isValidDate(const std::string& date);
		bool	checkDate(const std::string& date);
		bool	parseDate(const std::string& date);
		void	readTxtFile(const std::string& arg);
		void	parseTxtLine(const std::string& line);
		float	strToFloat(const std::string& value);
		int	calculateMaxDay(const int year, const int month);
		int	strToInt(const std::string& str);
		void	findData(const std::string& date, const float value);
		void	setData(const std::string& date, const float value);
		std::string&	ltrim(std::string& str);
		std::string&	rtrim(std::string& str);

		std::map<std::string, float> data_;
};

#endif
