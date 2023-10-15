#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void): ClapTrap("ScavTrap") {
  std::cout << "ScavTrap - Default constructor called" << std::endl;
  this->hitPoints = 100;
  this->energyPoints = 50;
  this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
  std::cout << "ScavTrap - Constructor called" << std::endl;
  this->hitPoints = 100;
  this->energyPoints = 50;
  this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap & src): ClapTrap(src) {
  std::cout << "ScavTrap - Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap - Destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
  std::cout << "ScavTrap - Assignation operator called" << std::endl;
  ClapTrap::operator=(rhs);
  return *this;
}

void ScavTrap::attack(std::string & target) {
  if (!this->isAlive(false)) {
    std::cout << "ScavTrap " << this->name << " is dead!" << std::endl;
  } else if (!this->consumeEnergyPoints(1, false)) {
    std::cout << "ScavTrap " << this->name << " has not enough energy points!" << std::endl;
  } else {
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
  }
}

void ScavTrap::guardGate(void) {
  if (!this->isAlive(false)) {
    std::cout << "ScavTrap " << this->name << " is dead!" << std::endl;
  } else {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
  }
}