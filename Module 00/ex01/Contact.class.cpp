#include <iostream>
#include "Contact.class.hpp"

Contact::Contact()
{
}

Contact::~Contact(void)
{
}

std::string Contact::getFirstName(void)
{
  return this->_firstName;
}

std::string Contact::getLastName(void)
{
  return this->_lastName;
}

std::string Contact::getNickname(void)
{
  return this->_nickname;
}

std::string Contact::getPhoneNumber(void)
{
  return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void)
{
  return this->_darkestSecret;
}

std::string Contact::_requestField(std::string fieldName) {
  std::string info;

  do {
    std::cout << "Enter " << fieldName << ": ";
    std::cin >> info;
    if (info.length() < 2) {
      std::cout << "Invalid " << fieldName << std::endl;
    }
  } while (info.length() < 2);

  return info;
}

void Contact::requestInfo(void) {
  this->_firstName = this->_requestField("first name");
  this->_lastName = this->_requestField("last name");
  this->_nickname = this->_requestField("nickname");
  this->_phoneNumber = this->_requestField("phone number");
  this->_darkestSecret = this->_requestField("darkest secret");
}

void Contact::printContact(void) {
  std::cout << "- First name: " << this->_firstName << std::endl;
  std::cout << "- Last name: " << this->_lastName << std::endl;
  std::cout << "- Nickname: " << this->_nickname << std::endl;
  std::cout << "- Phone number: " << this->_phoneNumber << std::endl;
  std::cout << "- Darkest secret: " << this->_darkestSecret << std::endl;
}
