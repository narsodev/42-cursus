#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->rawBits = 0;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  this->rawBits = value << Fixed::fractionalBits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  this->rawBits = roundf(value * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed & src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator = (Fixed const & rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
    this->setRawBits(rhs.getRawBits());
  return *this;
}

std::ostream & operator << (std::ostream & os, Fixed const & f) {
  os << f.toFloat();
  return os;
}

int Fixed::getRawBits(void) const {
  return this->rawBits;
}

void Fixed::setRawBits(int rawBits) {
  this->rawBits = rawBits;
}

int Fixed::toInt(void) const {
  return this->rawBits >> Fixed::fractionalBits;
}

float Fixed::toFloat(void) const {
  return (float) this->rawBits / (1 << Fixed::fractionalBits);
}