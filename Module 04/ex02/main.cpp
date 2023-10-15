#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#include <stdlib.h>

int main( void ) {
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  delete j;
  delete i;

  {
    Dog dog;
    std::cout << dog.getType() << std::endl;
    dog.makeSound();
  }

  {
    Cat cat;
    std::cout << cat.getType() << std::endl;
    cat.makeSound();
  }

  // Compilation error:
  // Animal animal;

  return 0;
}