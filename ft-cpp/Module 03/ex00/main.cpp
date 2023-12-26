#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
  ClapTrap clapTrap("Trapp");
  std::string target = "Target 1";

  // Attack
  clapTrap.attack(target);

  // Take damage
  clapTrap.takeDamage(8);

  // Be repaired
  clapTrap.beRepaired(10);

  // Lose all energy points
  clapTrap.attack(target);
  clapTrap.attack(target);
  clapTrap.attack(target);
  clapTrap.attack(target);
  clapTrap.attack(target);
  clapTrap.attack(target);
  clapTrap.attack(target);
  clapTrap.attack(target);

  // Attack with no energy points
  clapTrap.attack(target);

  // Be repaired with no energy points
  clapTrap.beRepaired(10);

  // Die
  clapTrap.takeDamage(100);

  // Attack when dead
  clapTrap.attack(target);

  // Be repaired when dead
  clapTrap.beRepaired(10);
}