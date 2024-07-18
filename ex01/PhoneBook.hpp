#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <string>

#include "Contact.hpp"

/*
• PhoneBook
  ◦ It has an array of contacts.
  ◦ It can store a maximum of 8 contacts. If the user tries to add a
      9th contact, replace the oldest one by the new one.
  ◦ Please note that dynamic allocation is forbidden.
*/
class PhoneBook {
  public:
    PhoneBook()
        : numContacts(0)
        , oldestContactIndex(0) {};
    ~PhoneBook() {}

    void addContact(const std::string first_name, const std::string last_name,
        const std::string nickname, const std::string phone_number,
        const std::string darkest_secret);

    std::string trimString(std::string);
    void        showContacts(void);
    void        searchContact(int);

  private:
    Contact contacts[8];
    int     numContacts;
    int     oldestContactIndex;
};

#endif
