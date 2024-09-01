#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("diamondtrap_clap_trap")
{
	this->name_ = "diamondtrap";
	this->hit_ = FragTrap::hit_;
	this->energy_ = ScavTrap::energy_;
	this->damage_ = FragTrap::damage_;

	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
	this->name_ = name;
	this->hit_ = FragTrap::hit_;
	this->energy_ = ScavTrap::energy_;
	this->damage_ = FragTrap::damage_;

	std::cout << "DiamondTrap " << this->name_ << " constructor called\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name_ << " destructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d)
{
	this->name_ = d.name_;
	this->hit_ = d.hit_;
	this->energy_ = d.energy_;
	this->damage_ = d.damage_;

	std::cout << "DiamondTrap copy assignment operator called\n";
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
		if (this->hit_ == 0 || this->energy_ == 0)
	{
		std::cout << "DiamondTrap " << this->name_ << " can't do anything\n";
	}
	else
	{
		std::cout << "DiamondTrap name: " << this->name_ << "\n";
		std::cout << "ClapTrap name: " << ClapTrap::name_ << "\n";
	}
}

void	DiamondTrap::checkRelate(void) const
{
	std::cout << "======================================\n";
	std::cout << "DiamondTrap name: " << this->name_ << "\n";
	std::cout << "ClapTrap name: " << ClapTrap::name_ << "\n";
	std::cout << "DiamondTrap hit: " << this->hit_ << "\n";
	std::cout << "FragTrap hit: " << FragTrap::hit_ << "\n";
	std::cout << "DiamondTrap energy: " << this->energy_ << "\n";
	std::cout << "ScavTrap energy: " << ScavTrap::energy_ << "\n";
	std::cout << "DiamondTrap damage: " << this->damage_ << "\n";
	std::cout << "FragTrap damage: " << FragTrap::damage_ << "\n";
	std::cout << "======================================\n";
}
