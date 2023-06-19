#include "FragTrap.hpp"
#include <iostream>

int main( void ) {
  FragTrap FragTrap("Trapp");
  std::string target = "Target 1";

  // Attack
  FragTrap.attack(target);

  // High fives
  FragTrap.highFivesGuys();

  // Take damage
  FragTrap.takeDamage(8);

  // Be repaired
  FragTrap.beRepaired(10);

  // Lose all energy points
  for (int i = 0; i < 98; i++) {
    FragTrap.attack(target);
  }

  // Attack with no energy points
  FragTrap.attack(target);

  // Be repaired with no energy points
  FragTrap.beRepaired(10);

  // Die
  FragTrap.takeDamage(1000);

  // Attack when dead
  FragTrap.attack(target);

  // Be repaired when dead
  FragTrap.beRepaired(10);

  // High fives when dead
  FragTrap.highFivesGuys();
}