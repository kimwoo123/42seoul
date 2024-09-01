#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) 
{
	this->name_ = "claptrap";
	this->damage_ = 0;
	this->hit_ = 10;
	this->energy_ = 10;
	
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
{
	this->name_ = name;
	this->damage_ = 0;
	this->hit_ = 10;
	this->energy_ = 10;
	
	std::cout << "ClapTrap " << name << " called\n";
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	this->name_ = c.name_;
	this->damage_ = c.damage_;
	this->hit_ = c.hit_;
	this->energy_ = c.energy_;

	std::cout << "ClapTrap Copy constructor called\n";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name_ << " Destructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	this->name_ = c.name_;
	this->damage_ = c.damage_;
	this->hit_ = c.hit_;
	this->energy_ = c.energy_;

	std::cout << "ClapTrap Copy assignment operator called\n";
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_ == 0 || this->energy_ == 0)
		std::cout << "ClapTrap " << this->name_ << " can't attack!\n";
	else
	{
		this->energy_ -= 1;
		std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing " << this->damage_ << " points of damage!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hit_)
	{
		this->hit_ = 0;
		std::cout << "ClapTrap " << this->name_ << " take " << amount << " points of damage!\n";
	}
	else
	{
		this->hit_ -= amount;
		std::cout << "ClapTrap " << this->name_ << " take " << amount << " points of damage!\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_ == 0 || this->energy_ == 0)
	{
		std::cout << "ClapTrap " << this->name_ << " can't repair\n";
	}
	else
	{
		this->hit_ += amount;
		this->energy_ -= 1;
		std::cout << "ClapTrap " << this->name_ << " repair " << amount << " point\n";
	}
}


