#include <iostream>
#include <string>

#include "Dictionary.hpp"


int main() {
  Dictionary<int, std::string> dict;

  dict.add(1, "one");
  dict.add(2, "two");
  dict.add(3, "three");

  std::cout << "Dictionary size: " << dict.size() << std::endl;

  std::string value;
  if (dict.contains(2)) {
    value = dict[2];
    std::cout << "Value of key 2: " << value << std::endl;
  }

  dict[4] = "four";

  std::cout << "Dictionary size: " << dict.size() << std::endl;

  if (dict.remove(3)) {
    std::cout << "Key 3 removed" << std::endl;
  }

  std::cout << "Dictionary size: " << dict.size() << std::endl;
}