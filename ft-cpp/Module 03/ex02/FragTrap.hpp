#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
  public:
    FragTrap(std::string name);
    FragTrap(const FragTrap & src);
    ~FragTrap(void);

    FragTrap & operator=(FragTrap const & rhs);

    void highFivesGuys(void);

  private:
    FragTrap(void);
};

#endif