#include <iostream>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main(void) {
  std::string option;

  PhoneBook phoneBook;

  do {
    std::cout << "Available commands:" << std::endl;
    std::cout << "- ADD" << std::endl;
    std::cout << "- SEARCH" << std::endl;
    std::cout << "- EXIT" << std::endl;
    std::cout << "Enter a command: ";
    std::cin >> option;
    if (option == "ADD") {
      phoneBook.addContact();
    } else if (option == "SEARCH") {
      phoneBook.searchContact();
      // phoneBook.searchContact();
    } else if (option != "EXIT") {
      std::cout << "Invalid command" << std::endl;
    }
  } while (option != "EXIT");

  std::cout << "Bye!" << std::endl;
  return 0;
}
