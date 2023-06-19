#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name): ClapTrap(name) {
  std::cout << "FragTrap - Default constructor called" << std::endl;
  this->hitPoints = 100;
  this->energyPoints = 100;
  this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap & src): ClapTrap(src) {
  std::cout << "FragTrap - Copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap - Destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
  std::cout << "FragTrap - Assignation operator called" << std::endl;
  ClapTrap::operator=(rhs);
  return *this;
}

void FragTrap::highFivesGuys(void) {
  if (!this->isAlive(false)) {
    std::cout << "FragTrap " << this->name << " is dead!" << std::endl;
  } else {
    std::cout << "FragTrap " << this->name << " high fives guys" << std::endl;
  }
}