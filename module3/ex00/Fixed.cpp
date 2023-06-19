#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->rawBits = 0;
}

Fixed::Fixed(const Fixed & src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
    this->setRawBits(rhs.getRawBits());
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->rawBits;
}

void Fixed::setRawBits(int rawBits) {
  this->rawBits = rawBits;
}