#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstdlib>
#include <iostream>
#include <string>

/*
• Contact
  ◦ Stands for a phonebook contact.

◦ The contact fields are: first name, last name, nickname,
    phone number, and darkest secret. A saved contact
    can’t have empty fields.
*/
class Contact {
  public:
    std::string getFirstName() const {
      return field[0];
    }
    std::string getLastName() const {
      return field[1];
    }
    std::string getNickname() const {
      return field[2];
    }
    std::string getPhoneNumber() const {
      return field[3];
    }
    std::string getDarkestSecret() const {
      return field[4];
    }

    int checkEmpty(std::string);
    int checkString(std::string);
    int checkNumber(std::string);

    int validContact(std::string[5]);
    int setContact(std::string[5]);

  private:
    std::string field[5];
};

#endif
