#include <iostream>
#include "Zombie.hpp"

int main(void) {
  std::cout << "Creating a horde of 10 zombies..."  << std::endl;

  Zombie* zombies = zombieHorde(10, "Narciso");

  std::cout << "Announcing the horde..."  << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << "Zombie " << i + 1 << ": ";
    zombies[i].announce();
  }

  std::cout << "Killing the horde..."  << std::endl;
  delete [] zombies;

  return 0;
}