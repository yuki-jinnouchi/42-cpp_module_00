#include <Contact.hpp>

int Contact::checkEmpty(std::string str) {
  if (str.empty())
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int Contact::checkString(std::string str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (!isalpha(str[i]))
      return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

int Contact::checkNumber(std::string str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (!isdigit(str[i]))
      return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

int Contact::validContact(std::string field[5]) {
  if (Contact::checkEmpty(field[0]) || Contact::checkEmpty(field[1]) ||
      Contact::checkEmpty(field[2]) || Contact::checkEmpty(field[3]) ||
      Contact::checkEmpty(field[4]))
    return (EXIT_FAILURE);
  if (Contact::checkString(field[0]) || Contact::checkString(field[1]) ||
      Contact::checkString(field[2]) || Contact::checkString(field[4]))
    return (EXIT_FAILURE);
  if (Contact::checkNumber(field[3]))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int Contact::setContact(std::string field[5]) {
  if (Contact::validContact(field) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  else
    for (size_t i = 0; i < 5; i++)
      this->field[i] = field[i];
  return (EXIT_SUCCESS);
}
