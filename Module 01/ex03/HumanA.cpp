#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
  // std::cout << "HumanA created" << std::endl;
}

HumanA::~HumanA() {
  // std::cout << "HumanA destroyed" << std::endl;
}

void HumanA::attack(void) {
  std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}