#include <iostream>
#include <string>

std::string to_upper(std::string str) {
  int i;
  int strlen;

  i = 0;
  strlen = str.length();
  while (i < strlen) {
    str[i] = toupper(str[i]);
    i++;
  }
  return (str);
}

void megaphone(int argc, char **argv) {
  int i;
  std::string str;

  i = 1;
  while (i < argc) {
    str = argv[i];
    str = to_upper(str);
    std::cout << str;
    i++;
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    megaphone(argc, argv);
  } else {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }
  return (0);
}
