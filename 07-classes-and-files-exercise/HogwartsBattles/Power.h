#ifndef POWER_H
#define POWER_H
#include <string>

class Power {
 public:
  Power(const std::string& name, int damage);

  const std::string& getName();
  int getDamage();

  bool operator<(const Power& other);
};

#endif  // POWER_H