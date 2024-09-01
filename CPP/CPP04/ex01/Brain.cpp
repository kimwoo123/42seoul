#include "Brain.hpp"

Brain::Brain(void)
{
	this->ideas_ = new std::string[100];
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& b)
{
	this->ideas_ = new std::string[100];
	for (int i = 0; i < 100; ++i)
	{
		this->ideas_[i] = b.ideas_[i];
	}
	std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(const Brain& b)
{
	if (this != &b)
	{
		for (int i = 0; i < 100; ++i)
		{
			this->ideas_[i] = b.ideas_[i];
		}
	}
	std::cout << "Brain assign operator called\n";

	return *this;
}

Brain::~Brain(void)
{
	delete[] ideas_;
	std::cout << "Brain destructor called\n";
}

