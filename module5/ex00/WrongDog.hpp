#ifndef WRONG_DOG_HPP
# define WRONG_DOG_HPP

# include <string>
# include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal {
  public:
    WrongDog(void);
    WrongDog(std::string name);
    WrongDog(const WrongDog & src);
    ~WrongDog(void);

    WrongDog & operator=(WrongDog const & rhs);

    void makeSound(void) const;
};

#endif