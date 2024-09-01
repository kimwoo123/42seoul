#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& b) {
	*this = b;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& b) {
	if (this != &b)
		this->data_ = b.data_;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

void	BitcoinExchange::run(const std::string& arg) {
	this->readCsvFile();
	this->readTxtFile(arg);
}

bool	BitcoinExchange::parseDate(const std::string& date) {
	if (date.size() != 10)
		return false;
	for (size_t i = 0; i < date.size(); ++i) {
		if (i == 4 || i == 7) {
			if (date.at(i) != '-')
				return false;
		}
		else {
			if (std::isdigit(date.at(i)) == false)
				return false;
		}
	}
	return true;
}

int	BitcoinExchange::strToInt(const std::string& str) {
	std::stringstream ss;
	int	result;

	ss << str;
	ss >> result;
	if (ss.fail() == true)
		throw std::runtime_error("Error: strToInt failed\n");
	return result;
}

int	BitcoinExchange::calculateMaxDay(const int year, const int month) {
	static int maxDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return 29;
	}
	return maxDays[month];
}

bool	BitcoinExchange::checkDate(const std::string& date) {
	int year, month, day;

	year = strToInt(std::string(&date[0], &date[4]));
	month = strToInt(std::string(&date[5], &date[7]));
	day = strToInt(std::string(&date[8], &date[10]));

	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1)
		return false;

	int maxDay = calculateMaxDay(year, month);

	if (day > maxDay)
		return false;
	return true;
}

bool	BitcoinExchange::isValidDate(const std::string& date) {
	if (parseDate(date) == false)
		throw std::runtime_error("Erorr: failed parseDate()\n");
	if (checkDate(date) == false)
		throw std::runtime_error("Erorr: failed checkDate()\n");
	return true;
}

bool	BitcoinExchange::isValidValue(const std::string& value) {
	size_t	index = 0;
	bool	hasDot = false;
	int	numInt = 0;
	int	numFra = 0;

	if (value[index] == '+' || value[index] == '-')
		++index;

	for (; index < value.length(); ++index) {
		if (std::isdigit(value[index])) {
			if (!hasDot)
				++numInt;
			else
				++numFra;
		} else if (value[index] == '.' && !hasDot) {
			hasDot = true;
		} else {
			return false;
		}
	}

	if (numInt == 0)
		return false;
	else if (hasDot && numFra == 0)
		return false;
	return true;
}

void	BitcoinExchange::setData(const std::string& date, const float value) {
	this->data_.insert(std::make_pair(date, value));
}

void	BitcoinExchange::parseCsvLine(const std::string& line) {
	std::size_t	left = line.find(",");
	std::size_t	right = line.rfind(",");

	if (left == std::string::npos || left != right)
		throw std::runtime_error("Error: invalid line format\n");

	std::string	date;
	std::string	value;

	date = line.substr(0, left);
	value = line.substr(right + 1);

	if (isValidDate(date) == false || isValidValue(value) == false)
		throw std::runtime_error("Error: invalid data format\n");
	setData(date, strToFloat(value));
}

void	BitcoinExchange::readCsvFile(void) {
    std::ifstream   csv;
    std::string     line;

    csv.open("./data.csv");
	if (csv.is_open() == false)
		throw std::runtime_error("Error: csv file open failed\n");

	if (csv.eof() == false) {
		csv >> line;
		if (line != "date,exchange_rate")
			throw std::runtime_error("Error: csv file first line invalid\n");
	}

    while (csv.eof() == false) {
		csv >> line;
		if (line.size() != 0)
			parseCsvLine(line);
	}
    csv.close();
}

float	BitcoinExchange::strToFloat(const std::string& value) {
	char*	endptr = NULL;
	double	result = std::strtod(value.c_str(), &endptr);

	if (endptr != NULL && *endptr != '\0')
		throw std::runtime_error("Error: strToFloat() failed\n");
	return static_cast<float>(result);
}


void	BitcoinExchange::findData(const std::string& date, const float value) {
	std::map<std::string, float>::const_iterator iter = this->data_.find(date);
	float	result;

	if (iter == this->data_.end()) {
		iter = this->data_.lower_bound(date);
		if (iter == this->data_.begin()) {
			std::cout << "Error: invalid date" << std::endl;
			return ;
		}
		--iter;
	}
	std:: cout << "iter->second : " << iter->second << " value: " << value << std::endl;
	std::cout << 44334.4 * 3 << std::endl;
	result = iter->second * value;
	std::cout << date << " => " << value << " = " << result << std::endl;
}


std::string&	BitcoinExchange::ltrim(std::string& str) {
	static const char* d = " \t\n\r\f\v";

	str.erase(0, str.find_first_not_of(d));
	return str;
}

std::string&	BitcoinExchange::rtrim(std::string& str) {
	static const char* d = " \t\n\r\f\v";

	str.erase(str.find_last_not_of(d) + 1);
	return str;
}

void	BitcoinExchange::parseTxtLine(const std::string& line) {
	std::size_t	left = line.find("|");
	std::size_t	right = line.rfind("|");

	if (left == std::string::npos || left != right) {
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string	date;
	std::string	value;

	date = line.substr(0, left);
	value = line.substr(right + 1);
	rtrim(date);
	ltrim(value);

	float	f = 0;

	if (checkDate(date) == false || isValidValue(value) == false)
		std::cout << "Error: bad input => " << line << std::endl;
	else {
		f = strToFloat(value);
		if (f < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (f > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
			findData(date, f);
	}
}

void	BitcoinExchange::readTxtFile(const std::string& arg) {
	std::ifstream	txt;
	std::string	line;

	txt.open(arg.c_str());
	if (txt.is_open() == false)
		throw std::runtime_error("Error: txt file open failed\n");

	if (txt.eof() == false) {
		std::getline(txt, line);
		if (line != "date | value")
			throw std::runtime_error("Error: txt file first line invalid\n");
	}

	while (txt.eof() == false) {
		std::getline(txt, line);
		if (line.size() != 0)
			parseTxtLine(line);
	}
	txt.close();
}
