#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>

class ClapTrap {
  public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap & src);
    ~ClapTrap(void);

    ClapTrap & operator=(ClapTrap const & rhs);

    void attack(std::string & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

  private:
    std::string name;
    int hitPoints;
    int energyPoints;
    unsigned int attackDamage;

    bool consumeEnergyPoints(int amount);
    bool isAlive(void) const;
    bool isAlive(bool printMessage) const;

    ClapTrap(void);
};

#endif