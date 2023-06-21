#include "Dog.hpp"
#include <iostream>

Dog::Dog(void): Animal() {
  std::cout << "Dog - Default constructor called" << std::endl;
  this->type = "Dog";
  this->brain = new Brain();
}

Dog::Dog(const Dog & src): Animal(src) {
  std::cout << "Dog - Copy constructor called" << std::endl;
  this->brain = NULL;
  *this = src;
}

Dog::~Dog(void) {
  std::cout << "Dog - Destructor called" << std::endl;
  delete this->brain;
}

Dog & Dog::operator=(Dog const & rhs) {
  std::cout << "Dog - Assignation operator called" << std::endl;
  Animal::operator=(rhs);

  if (this != &rhs) {
    if (this->brain) delete this->brain;
    this->brain = new Brain(*rhs.brain);
  }

  return *this;
}

void Dog::makeSound(void) const {
  std::cout << "Woouuw!" << std::endl;
}