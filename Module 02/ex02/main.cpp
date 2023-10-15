#include "Fixed.hpp"
#include <iostream>

int main( void ) {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;
  std::cout << Fixed::min( a, b ) << std::endl;

  Fixed c(Fixed(10) + Fixed(3));
  std::cout << c << std::endl;

  Fixed d(Fixed(10.9f) - Fixed(10.9f));
  std::cout << d << std::endl;

  Fixed e(Fixed(100) * Fixed(5));
  std::cout << e << std::endl;

  Fixed f(Fixed(4.5f) / Fixed(3));
  std::cout << f << std::endl;

return 0;
}