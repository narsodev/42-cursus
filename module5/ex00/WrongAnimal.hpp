#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class WrongAnimal {
  public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal & src);
    ~WrongAnimal(void);

    WrongAnimal & operator=(WrongAnimal const & rhs);

    std::string getType(void) const;

    void makeSound(void) const;

  protected:
    std::string type;
};

#endif