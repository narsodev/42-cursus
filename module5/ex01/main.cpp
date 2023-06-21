#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#include <stdlib.h>

int main( void ) {
  std::cout << "---------------------" << std::endl;
  std::cout << "Subject example test" << std::endl;
  std::cout << "---------------------" << std::endl;
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  delete j;//should not create a leak
  delete i;

  std::cout << "---------------------" << std::endl;
  std::cout << "Subject required test" << std::endl;
  std::cout << "---------------------" << std::endl;

  const Animal* animals[10];
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      animals[i] = new Dog();
    } else {
      animals[i] = new Cat();
    }
  }

  for (int i = 0; i < 10; i++) {
    delete animals[i];
  }

  std::cout << "---------------------" << std::endl;
  std::cout << "Dog and Cat copies are not shallow copies" << std::endl;
  std::cout << "---------------------" << std::endl;

  Dog dog;
  {
    std::cout << "Assignation operator" << std::endl;
    Dog dog_copy = dog;
  }
  {
    std::cout << "Copy constructor" << std::endl;
    Dog dog_copy(dog);
  }

  // system("leaks world_on_fire");

  return 0; 
}