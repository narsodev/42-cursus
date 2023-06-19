#ifndef SED_HPP
# define SED_HPP

# include <string>

class Sed {
  public:
    Sed();
    ~Sed(void);
	void replace(std::string & filepath, std::string & s1, std::string & s2);
};

#endif