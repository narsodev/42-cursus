#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::addContact(void)
{
  Contact contact;
  contact.requestInfo();

  if (this->_contactCount < 8) {
    this->_contacts[this->_contactCount] = contact;
    this->_lastContactIndex = this->_contactCount;
    this->_contactCount++;
  } else {
    this->_contacts[this->_lastContactIndex] = contact;
    this->_lastContactIndex++;
    if (this->_lastContactIndex == 8) {
      this->_lastContactIndex = 0;
    }
  }

  std::cout << "Contact added" << std::endl;
}

std::string PhoneBook::_getContactColumn(std::string property) {
  std::string column;

  if (property.length() > 10) {
    column = property.substr(0, 9) + ".";
  } else {
    column = property;
    for (int i = property.length(); i < 10; i++) {
      column = " " + column;
    }
  }

  return column;
}

void PhoneBook::_printContacts(void) {
  std::string indexHelper = "         ";

  for (int i = 0; i < this->_contactCount; i++) {
    std::cout << indexHelper << i + 1 << "|";
    std::cout << _getContactColumn(this->_contacts[i].getFirstName()) << "|";
    std::cout << _getContactColumn(this->_contacts[i].getLastName()) << "|";
    std::cout << _getContactColumn(this->_contacts[i].getNickname());
    std::cout << std::endl;
  }

}

void PhoneBook::searchContact(void) {
  std::string buffer;
  int index;
  bool error;

  if (this->_contactCount == 0) {
    std::cout << "No contacts" << std::endl;
    return;
  }

  this->_printContacts();

  do {
    std::cout << "Enter index: ";
    std::cin >> buffer;

    error = buffer.length() != 1 || buffer[0] < '1' || buffer[0] > '8';
    if (!error) {
      index = buffer[0] - '0';
      error = index < 1 || index > this->_contactCount;
    }
    if (error) {
      std::cout << "Invalid index" << std::endl;
    }
  } while (error);

  this->_contacts[index - 1].printContact();

}

// void PhoneBook::addContact(Contact contact) {
//   if (this->_contactCount < 8) {
//     this->_contacts[this->_contactCount] = contact;
//     this->_lastContactIndex = this->_contactCount;
//     this->_contactCount++;
//   } else {
//     this->_contacts[this->_lastContactIndex] = contact;
//     this->_lastContactIndex++;
//     if (this->_lastContactIndex == 8) {
//       this->_lastContactIndex = 0;
//     }
//   }
// }