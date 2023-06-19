#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
  this->type = type;
  // std::cout << "Weapon created" << std::endl;
}

Weapon::~Weapon() {
  // std::cout << "Weapon destroyed" << std::endl;
}

void Weapon::setType(std::string type) {
  this->type = type;
}

const std::string& Weapon::getType(void) const {
  return this->type;
}