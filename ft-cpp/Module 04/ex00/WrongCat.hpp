#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
  public:
    WrongCat(void);
    WrongCat(std::string name);
    WrongCat(const WrongCat & src);
    ~WrongCat(void);

    WrongCat & operator=(WrongCat const & rhs);

    void makeSound(void) const;
};

#endif