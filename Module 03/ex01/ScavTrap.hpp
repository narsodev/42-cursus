#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
  public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap & src);
    ~ScavTrap(void);

    ScavTrap & operator=(ScavTrap const & rhs);

    void attack(std::string & target);
    void guardGate(void);

  private:
    ScavTrap(void);
};

#endif