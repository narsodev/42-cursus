#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
  ScavTrap scavTrap("Trapp");
  std::string target = "Target 1";

  // Attack
  scavTrap.attack(target);

  // Guard gate
  scavTrap.guardGate();

  // Take damage
  scavTrap.takeDamage(8);

  // Be repaired
  scavTrap.beRepaired(10);

  // Lose all energy points
  for (int i = 0; i < 48; i++) {
    scavTrap.attack(target);
  }

  // Attack with no energy points
  scavTrap.attack(target);

  // Be repaired with no energy points
  scavTrap.beRepaired(10);

  // Die
  scavTrap.takeDamage(100);

  // Attack when dead
  scavTrap.attack(target);

  // Be repaired when dead
  scavTrap.beRepaired(10);

  // Guard gate when dead
  scavTrap.guardGate();
}