#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
  public:
    Animal(void);
    Animal(const Animal & src);
    virtual ~Animal(void);

    Animal & operator=(Animal const & rhs);

    std::string getType(void) const;

    virtual void makeSound(void) const;

  protected:
    std::string type;
};

#endif