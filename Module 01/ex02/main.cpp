#include <iostream>

int main(void) {
  std::string var = "HI THIS IS BRAIN";
  std::string* stringPTR = &var;
  std::string& stringREF = var;

  std::cout << "var address:\t\t" << &var << std::endl;
  std::cout << "stringPTR address:\t" << stringPTR << std::endl;
  std::cout << "stringREF address:\t" << &stringREF << std::endl;

  std::cout << std::endl;

  std::cout << "var value:\t\t" << var << std::endl;
  std::cout << "stringPTR value:\t" << *stringPTR << std::endl;
  std::cout << "stringREF value:\t" << stringREF << std::endl;

  return 0;
}