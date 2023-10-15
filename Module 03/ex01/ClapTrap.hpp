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

  protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    unsigned int attackDamage;

    bool consumeEnergyPoints(int amount);
    bool consumeEnergyPoints(int amount, bool printMessage);
    bool isAlive(void) const;
    bool isAlive(bool printMessage) const;

  private:
    ClapTrap(void);
};

#endif