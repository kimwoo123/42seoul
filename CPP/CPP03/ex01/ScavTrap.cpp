#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->name_ = "scavtrap";
	this->hit_ = 100;
	this->energy_ = 50;
	this->damage_ = 20;

	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name)
{
	this->name_ = name;
	this->hit_ = 100;
	this->energy_ = 50;
	this->damage_ = 20;

	std::cout << "ScavTrap " << name << " constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& s)
{
	this->name_ = s.name_;
	this->hit_ = s.hit_;
	this->energy_ = s.energy_;
	this->damage_ = s.damage_;
	
	std::cout << "ScavTrap " << this->name_ << " copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s)
{
	this->name_ = s.name_;
	this->hit_ = s.hit_;
	this->energy_ = s.energy_;
	this->damage_ = s.damage_;

	std::cout << "ScavTrap copy assignment operator called\n";
	return (*this);

}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name_ << " destructor called\n";
}

void ScavTrap::guardGate(void)
{
	if (this->hit_ == 0 || this->energy_ == 0)
	{
		std::cout << "ScavTrap " << this->name_ << " can't do anything\n";
	}
	else
	{
		std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode\n";
	}
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hit_ == 0 || this->energy_ == 0)
	{
		std::cout << "ScavTrap " << this->name_ << " can't attack\n";
	}
	else
	{
		std::cout	<< "ScavTrap " << this->name_ << " attacks " << target
					<< ", causing " << this->damage_ << " points of damage!\n";
		this->energy_ -= 1;
	}
}
