#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
  public:
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& src);
    ~Fixed(void);

    Fixed & operator = (Fixed const & rhs);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    int toInt(void) const;
    float toFloat(void) const;

  private:
    int rawBits;
    static const int fractionalBits = 8;

};

std::ostream & operator << (std::ostream & os, const Fixed & fixed);

#endif