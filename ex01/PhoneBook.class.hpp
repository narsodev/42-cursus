#ifndef PHONE_BOOK_CLASS_HPP
# define PHONE_BOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook {
  public:
    PhoneBook(void);
    ~PhoneBook(void);

    void addContact(void);
    void searchContact(void);

  private:
    Contact _contacts[8];
    int _contactCount;
    int _lastContactIndex;

    std::string _getContactColumn(std::string property);
    void _printContacts(void);
};

#endif
