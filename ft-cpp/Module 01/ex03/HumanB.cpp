#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
  this->weapon = NULL;
  // std::cout << "HumanB created" << std::endl;
}

HumanB::~HumanB() {
  // std::cout << "HumanB destroyed" << std::endl;
}

void HumanB::attack(void) {
  if (this->weapon == NULL) {
    std::cout << this->name << " has no weapon to attack" << std::endl;
  } else {
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
  }
}

void HumanB::setWeapon(Weapon& weapon) {
  this->weapon = &weapon;
}