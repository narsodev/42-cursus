#include "Dog.hpp"
#include <iostream>

Dog::Dog(void): Animal() {
  std::cout << "Dog - Default constructor called" << std::endl;
  this->type = "Dog";
}

Dog::Dog(const Dog & src): Animal(src) {
  std::cout << "Dog - Copy constructor called" << std::endl;
}

Dog::~Dog(void) {
  std::cout << "Dog - Destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs) {
  std::cout << "Dog - Assignation operator called" << std::endl;
  Animal::operator=(rhs);
  return *this;
}

void Dog::makeSound(void) const {
  std::cout << "Woouuw!" << std::endl;
}