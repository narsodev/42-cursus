#include <iostream>
#include "Animal.hpp"

Animal::Animal() {
  std::cout << "Animal - Default constructor called" << std::endl;
  this->type = "Animal";
}

Animal::Animal(const Animal & src) {
  std::cout << "Animal - Copy constructor called" << std::endl;
  *this = src;
}

Animal::~Animal() {
  std::cout << "Animal - Destructor called" << std::endl;
}

Animal & Animal::operator=(Animal const & rhs) {
  std::cout << "Animal - Copy assignment operator called" << std::endl;
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return *this;
}

std::string Animal::getType(void) const {
  return this->type;
}

void Animal::makeSound(void) const {
  std::cout << "Animal sound!" << std::endl;
}