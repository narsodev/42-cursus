#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap - Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src) {
  std::cout << "ClapTrap - Copy constructor called" << std::endl;
  *this = src;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap - Destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
  std::cout << "ClapTrap - Copy assignment operator called" << std::endl;
  if (this != &rhs) {
    this->name = rhs.name;
    this->hitPoints = rhs.hitPoints;
    this->energyPoints = rhs.energyPoints;
    this->attackDamage = rhs.attackDamage;
  }
  return *this;
}

bool ClapTrap::isAlive(void) const {
  if (this->hitPoints <= 0) {
    std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
    return false;
  }
  return true;
}

bool ClapTrap::isAlive(bool printMessage) const {
  if (this->hitPoints <= 0) {
    if (printMessage) {
      std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
    }
    return false;
  }
  return true;
}

bool ClapTrap::consumeEnergyPoints(int amount) {
  if (this->energyPoints - amount < 0) {
    std::cout << "ClapTrap " << this->name << " has not enough energy points!" << std::endl;
    return false;
  }

  this->energyPoints -= amount;
  return true;
}

bool ClapTrap::consumeEnergyPoints(int amount, bool printMessage) {
  if (this->energyPoints - amount < 0) {
    if (printMessage)
      std::cout << "ClapTrap " << this->name << " has not enough energy points!" << std::endl;
    return false;
  }

  this->energyPoints -= amount;
  return true;
}

void ClapTrap::attack(std::string & target) {
  if (!this->isAlive()) return;
  if (!this->consumeEnergyPoints(1)) return;

  std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!this->isAlive()) return;

  this->hitPoints -= amount;
  if (this->hitPoints < 0) this->hitPoints = 0;
  std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! Remaining health: " << this->hitPoints << std::endl;

  if (!this->isAlive(false)) {
    std::cout << "ClapTrap " << this->name << " has dead!" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!this->isAlive()) return;
  if (!this->consumeEnergyPoints(1)) return;

  std::cout << "ClapTrap " << this->name << " is repaired " << amount << " points!" << std::endl;
}
