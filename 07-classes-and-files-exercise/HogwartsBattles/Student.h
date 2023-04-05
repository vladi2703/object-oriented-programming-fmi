#ifndef STUDENT_H
#define STUDENT_H

#include "Power.h"

class Student {
 public:
  Student() = default;
  Student(const std::string& name);

  const std::string& getName() const;
  const std::string& getHouse() const;
  void setHouse(const std::string& house);
  int getHealth() const;
  void takeDamage(int damage);
  void setPower(const Power* power);
  const Power* getPower() const;
  bool isAlive() const;
  int attack() const;

 private:
  std::string name_;
  std::string house_;
  int health_;
  const Power* power_;
};

#endif  /// STUDENT_H
