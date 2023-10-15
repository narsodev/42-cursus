#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
  public:
    Cat(void);
    Cat(std::string name);
    Cat(const Cat & src);
    virtual ~Cat(void);

    Cat & operator=(Cat const & rhs);

    virtual void makeSound(void) const;
  
  private:
    Brain *brain;
};

#endif