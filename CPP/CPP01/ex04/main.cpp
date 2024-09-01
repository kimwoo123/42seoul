#include <iostream>
#include <fstream>

void	replace_string(const std::string &s1, const std::string &s2, std::string &line)
{
	size_t	start_pos;

	start_pos = 0;
	start_pos = line.find(s1, start_pos);
    while (start_pos != std::string::npos)
	{
		line.erase(start_pos, s1.length());
		line.insert(start_pos, s2);
		start_pos = line.find(s1, start_pos + s2.length());
    }
}

void	input_string(char *argv_2, char *argv_3, std::ifstream &ifs, std::ofstream &ofs)
{
	std::string	line;
	std::string	s1;
	std::string	s2;

	s1 = argv_2;
	s2 = argv_3;
	while (std::getline(ifs, line))
	{
		if (ifs.eof())
			break ;
		replace_string(s1, s2, line);
		ofs << line << "\n";
	}
}

int main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		output_file;
	
	if (argc != 4)
	{
		std::cout << "usage: ./SED [file name] [string1] [string2]" << "\n";
		return (0);
	}
	ifs.open(argv[1]);
	if (ifs.fail())
	{
		std::cout << "fail to open " << argv[1] << "\n";
		return (0);
	}
	output_file = (std::string)argv[1] + ".replace";
	ofs.open(output_file);
	if (ofs.fail())
	{
		ifs.close();
		std::cout << "fail to open " << output_file << "\n";
	}
	input_string(argv[2], argv[3], ifs, ofs);
	ifs.close();
	ofs.close();
}
