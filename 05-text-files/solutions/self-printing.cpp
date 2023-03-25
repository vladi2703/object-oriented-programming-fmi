// program that prints its own code
#include <fstream>
#include <iostream>

int main() {
  std::ifstream i_file("self-printing.cpp");
  if (!i_file.is_open()) {
    std::cout << "Error opening file!\n";
    return 1;
  }

  char c;
  while (!i_file.eof()) {
    i_file.get(c);
    std::cout << c;
  }

  i_file.close();
  return 0;
}