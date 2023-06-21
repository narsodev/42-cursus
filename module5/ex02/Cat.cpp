#include "Cat.hpp"
#include <iostream>

Cat::Cat(void): Animal() {
  std::cout << "Cat - Default constructor called" << std::endl;
  this->type = "Cat";
  this->brain = new Brain();
}

Cat::Cat(const Cat & src): Animal(src) {
  std::cout << "Cat - Copy constructor called" << std::endl;
  this->brain = NULL;
  *this = src;
}

Cat::~Cat(void) {
  std::cout << "Cat - Destructor called" << std::endl;
  delete this->brain;
}

Cat & Cat::operator=(Cat const & rhs) {
  std::cout << "Cat - Assignation operator called" << std::endl;
  Animal::operator=(rhs);

  if (this != &rhs) {
    if (this->brain) delete this->brain;
    this->brain = new Brain(*rhs.brain);
  }

  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "Meoouuw!" << std::endl;
}