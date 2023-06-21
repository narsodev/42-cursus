#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"

class Dog: public Animal {
  public:
    Dog(void);
    Dog(std::string name);
    Dog(const Dog & src);
    ~Dog(void);

    Dog & operator=(Dog const & rhs);

    virtual void makeSound(void) const;
};

#endif