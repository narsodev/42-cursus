#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void): WrongAnimal() {
  std::cout << "WrongCat - Default constructor called" << std::endl;
  this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat & src): WrongAnimal(src) {
  std::cout << "WrongCat - Copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
  std::cout << "WrongCat - Destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs) {
  std::cout << "WrongCat - Assignation operator called" << std::endl;
  WrongAnimal::operator=(rhs);
  return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << "Meoouuw!" << std::endl;
}