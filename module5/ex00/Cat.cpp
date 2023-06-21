#include "Cat.hpp"
#include <iostream>

Cat::Cat(void): Animal() {
  std::cout << "Cat - Default constructor called" << std::endl;
  this->type = "Cat";
}

Cat::Cat(const Cat & src): Animal(src) {
  std::cout << "Cat - Copy constructor called" << std::endl;
}

Cat::~Cat(void) {
  std::cout << "Cat - Destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs) {
  std::cout << "Cat - Assignation operator called" << std::endl;
  Animal::operator=(rhs);
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "Meoouuw!" << std::endl;
}