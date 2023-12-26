#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
  std::cout << "Brain - Default constructor called" << std::endl;
}

Brain::Brain(const Brain & src) {
  std::cout << "Brain - Copy constructor called" << std::endl;
  *this = src;
}

Brain::~Brain(void) {
  std::cout << "Brain - Destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs) {
  std::cout << "Brain - Assignation operator called" << std::endl;
  if (this != &rhs) {
    for (int i = 0; i < 100; i++) {
      this->ideas[i] = rhs.ideas[i];
    }
  }
  return *this;
}
