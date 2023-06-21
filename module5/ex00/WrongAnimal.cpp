#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal - Default constructor called" << std::endl;
  this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal & src) {
  std::cout << "WrongAnimal - Copy constructor called" << std::endl;
  *this = src;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal - Destructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs) {
  std::cout << "WrongAnimal - Copy assignment operator called" << std::endl;
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return *this;
}

std::string WrongAnimal::getType(void) const {
  return this->type;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "WrongAnimal sound!" << std::endl;
}