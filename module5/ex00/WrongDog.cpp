#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog(void): WrongAnimal() {
  std::cout << "WrongDog - Default constructor called" << std::endl;
  this->type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog & src): WrongAnimal(src) {
  std::cout << "WrongDog - Copy constructor called" << std::endl;
}

WrongDog::~WrongDog(void) {
  std::cout << "WrongDog - Destructor called" << std::endl;
}

WrongDog & WrongDog::operator=(WrongDog const & rhs) {
  std::cout << "WrongDog - Assignation operator called" << std::endl;
  WrongAnimal::operator=(rhs);
  return *this;
}

void WrongDog::makeSound(void) const {
  std::cout << "Woouuw!" << std::endl;
}