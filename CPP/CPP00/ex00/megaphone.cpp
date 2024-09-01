#include <iostream>

int	is_lowalpha(char c)
{
	return (c >= 97 && c <= 122);
}

int main(int argc, char **argv)
{
	int arg_index;
	int	str_index;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		arg_index = 1;
		while (argv[arg_index])
		{
			str_index = 0;
			while (argv[arg_index][str_index])
			{
				if (is_lowalpha(argv[arg_index][str_index]))
					std::cout << char(argv[arg_index][str_index] - 32);
				else
					std::cout << argv[arg_index][str_index];
				str_index++;
			}
			arg_index++;
		}
		std::cout << std::endl;
	}
}
