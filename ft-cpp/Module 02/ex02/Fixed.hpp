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

    bool operator > (Fixed const & rhs) const;
    bool operator < (Fixed const & rhs) const;
    bool operator >= (Fixed const & rhs) const;
    bool operator <= (Fixed const & rhs) const;
    bool operator == (Fixed const & rhs) const;
    bool operator != (Fixed const & rhs) const;

    Fixed operator + (Fixed const & rhs) const;
    Fixed operator - (Fixed const & rhs) const;
    Fixed operator * (Fixed const & rhs) const;
    Fixed operator / (Fixed const & rhs) const;

    Fixed & operator ++ (void);
    Fixed operator ++ (int);
    Fixed & operator -- (void);
    Fixed operator -- (int);

    static Fixed & min(Fixed & a, Fixed & b);
    static Fixed const & min(Fixed const & a, Fixed const & b);
    static Fixed & max(Fixed & a, Fixed & b);
    static Fixed const & max(Fixed const & a, Fixed const & b);

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