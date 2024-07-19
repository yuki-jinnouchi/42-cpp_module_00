#include <PhoneBook.hpp>
#include <sstream>

void PhoneBook::addContact(const std::string first_name,
    const std::string last_name, const std::string nickname,
    const std::string phone_number, const std::string darkest_secret) {
  class Contact contact;
  std::string   field[5];
  int           status;

  field[0] = first_name;
  field[1] = last_name;
  field[2] = nickname;
  field[3] = phone_number;
  field[4] = darkest_secret;
  status = contact.validContact(field);
  if (status == EXIT_FAILURE) {
    std::cout << "Invalid contact." << std::endl;
    return;
  }
  if (PhoneBook::numContacts < 8) {
    contacts[PhoneBook::numContacts].setContact(field);
    PhoneBook::numContacts++;
  } else {
    contacts[PhoneBook::oldestContactIndex].setContact(field);
    PhoneBook::oldestContactIndex = (PhoneBook::oldestContactIndex + 1) % 8;
  }
  return;
}

std::string PhoneBook::trimString(std::string str) {
  if (str.length() > 10) {
    str.resize(9);
    str.append(".");
  } else {
    str.resize(10, ' ');
  }
  return (str);
}

void PhoneBook::showContacts(void) {
  int         i;
  std::string index;

  index = "0";
  std::cout << PhoneBook::trimString("Index") << "|";
  std::cout << PhoneBook::trimString("First Name") << "|";
  std::cout << PhoneBook::trimString("Last Name") << "|";
  std::cout << PhoneBook::trimString("Nickname") << std::endl;
  std::cout << "-------------------------------------------" << std::endl;
  i = 0;
  while (i < PhoneBook::numContacts) {
    index[0] = i + '0';
    std::cout << PhoneBook::trimString(index)  << "|";
    std::cout << PhoneBook::trimString(contacts[i].getFirstName()) << "|";
    std::cout << PhoneBook::trimString(contacts[i].getLastName()) << "|";
    std::cout << PhoneBook::trimString(contacts[i].getNickname())
              << std::endl;
    i++;
  }
  return;
}

void PhoneBook::searchContact(int i) {
  if (i < 0 || i >= PhoneBook::numContacts) {
    std::cout << "Invalid index." << std::endl;
  } else {
    std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[i].getDarkestSecret()
              << std::endl;
  }
  return;
}
