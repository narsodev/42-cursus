#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat: public Animal {
  public:
    Cat(void);
    Cat(std::string name);
    Cat(const Cat & src);
    ~Cat(void);

    Cat & operator=(Cat const & rhs);

    virtual void makeSound(void) const;
};

#endif