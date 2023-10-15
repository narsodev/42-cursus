#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class Fixed {
  public:
    Fixed(void);
    Fixed(const Fixed& src);
    ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);

    int getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    int rawBits;
    static const int fractionalBits = 8;

};

#endif