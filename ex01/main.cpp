// You have to implement two classes:
// • PhoneBook
//   ◦ It has an array of contacts.
//   ◦ It can store a maximum of 8 contacts. If the user tries to add a
//       9th contact, replace the oldest one by the new one.
//   ◦ Please note that dynamic allocation is forbidden.
// • Contact
//   ◦ Stands for a phonebook contact.

// In your code, the phonebook must be instantiated as an instance of the
//   PhoneBook class. Same thing for the contacts. Each one of them
//   must be instantiated as an instance of the Contact class. You’re
//   free to design the classes as you like but keep in mind that anything
//   that will always be used inside a class is private, and that anything
//   that can be used outside a class is public.
// On program start-up, the phonebook is empty and the user is prompted
//   to enter one of three commands. The program only accepts
//   ADD, SEARCH and EXIT.
// • ADD: save a new contact
//   ◦ If the user enters this command, they are prompted to input
//       the information of the new contact one field at a time. Once
//       all the fields have been completed, add the contact to the phonebook.
//   ◦ The contact fields are: first name, last name, nickname,
//       phone number, and darkest secret. A saved contact
//       can’t have empty fields.
// • SEARCH: display a specific contact
//   ◦ Display the saved contacts as a list of 4 columns:
//       index, first name, last name and nickname.
//   ◦ Each column must be 10 characters wide. A pipe character (’|’)
//       separates them. The text must be right-aligned. If the text is
//       longer than the column, it must be truncated and the last
//       displayable character must be replaced by a dot (’.’).
//   ◦ Then, prompt the user again for the index of the entry to display.
//       If the index is out of range or wrong, define a relevant behavior.
//       Otherwise, display the contact information, one field per line.
// • EXIT
//   ◦ The program quits and the contacts are lost forever!
// • Any other input is discarded.
// Once a command has been correctly executed, the program waits for another
//   one. It stops when the user inputs EXIT. Give are levant name to your
//   executable.

#include <Contact.hpp>
#include <PhoneBook.hpp>

void command_add(PhoneBook &phone_book) {
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;

  std::cout << "- Enter first name (only alphabets): ";
  std::cin >> first_name;
  std::cout << "- Enter last name (only alphabets): ";
  std::cin >> last_name;
  std::cout << "- Enter nickname (only alphabets): ";
  std::cin >> nickname;
  std::cout << "- Enter phone number (only numbers): ";
  std::cin >> phone_number;
  std::cout << "- Enter darkest secret: (only alphabets): ";
  std::cin >> darkest_secret;
  phone_book.addContact(
      first_name, last_name, nickname, phone_number, darkest_secret);
}

void command_search(PhoneBook &phone_book) {
  int index;

  phone_book.showContacts();
  std::cout << "- Enter an index number: ";
  std::cin >> index;
  phone_book.searchContact(index);
}

int main() {
  PhoneBook   phone_book;
  std::string command;

  while (1) {
    std::cout << "Enter a command: ";
    if (!(std::cin >> command)) {
      break;
    }
    if (command == "ADD") {
      command_add(phone_book);
    } else if (command == "SEARCH") {
      command_search(phone_book);
    } else if (command != "EXIT") {
      std::cout << "Invalid command. Command should be (ADD | SEARCH | EXIT)"
                << std::endl;
    } else if (command == "EXIT") {
      break;
    }
  }
  return 0;
}
