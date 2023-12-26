#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
  public:
    Dog(void);
    Dog(std::string name);
    Dog(const Dog & src);
    virtual ~Dog(void);

    Dog & operator=(Dog const & rhs);

    virtual void makeSound(void) const;
  
  private:
    Brain *brain;
};

#endif