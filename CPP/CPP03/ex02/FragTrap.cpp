#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name_ = "fragtrap";
	this->hit_ = 100;
	this->energy_ = 100;
	this->damage_ = 30;

	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name)
{
	this->name_ = name;
	this->hit_ = 100;
	this->energy_ = 100;
	this->damage_ = 30;

	std::cout << "FragTrap " << name << " constructor called\n";
}

FragTrap::FragTrap(const FragTrap& f)
{
	this->name_ = f.name_;
	this->hit_ = f.hit_;
	this->energy_ = f.energy_;
	this->damage_ = f.damage_;

	std::cout << "FragTrap " << this->name_ << " copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& f)
{
	this->name_ = f.name_;
	this->hit_ = f.hit_;
	this->energy_ = f.energy_;
	this->damage_ = f.damage_;

	std::cout << "FragTrap copy assignment operator called\n";
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name_ << " destructor called\n";
}

void	FragTrap::highFivesGuys(void)
{
	if (this->hit_ == 0 || this->energy_ == 0)
	{
		std::cout << "FragTrap " << this->name_ << " can't do anything\n";
	}
	else
	{
		std::cout << "FragTrap High Fives~\n";
	}
}
