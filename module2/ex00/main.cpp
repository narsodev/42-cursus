#include <iostream>
#include "Zombie.hpp"

int main(void) {
  std::cout << "Creating a zombie allocated on the heap. Zombie name: " << "Narciso." << std::endl;
  Zombie* zombie3 = newZombie("Narciso");
  zombie3->announce();
  delete zombie3;

  std::cout << "Creating a zombie allocated on the stack. Zombie name: " << "Pepe." << std::endl;
  randomChump("Pepe");

  return 0;
}