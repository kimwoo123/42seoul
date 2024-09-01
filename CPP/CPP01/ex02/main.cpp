#include <iostream>

int main()
{
	std::string	origin_str;
	std::string	*stringPTR;
	std::string &stringREF = origin_str;

	origin_str = "HI THIS IS BRAIN";
	stringPTR = &origin_str;
	
	std::cout << "ORG: " << &origin_str << "\n";
	std::cout << "REF: " << &stringREF << "\n";
	std::cout << "PTR rv: " << stringPTR << "\n";
	std::cout << "PTR lv: " << &stringPTR << "\n";

	stringREF[0] = 'T';

	std::cout << "ORG: " << origin_str << "\n";
	std::cout << "REF: " << stringREF << "\n";
	std::cout << "PTR: " << *stringPTR << "\n";

}
