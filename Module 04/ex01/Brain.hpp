#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
  public:
    Brain(void);
    Brain(std::string name);
    Brain(const Brain & src);
    ~Brain(void);

    Brain & operator=(Brain const & rhs);

  private:
    std::string ideas[100];
};

#endif