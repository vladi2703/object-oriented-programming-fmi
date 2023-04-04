#ifndef HOGWARTS_H
#define HOGWARTS_H

#include <iostream>
#include <string>

#include "Power.h"
#include "Student.h"

class Hogwarts {
 public:
  Hogwarts();
  Hogwarts(const Hogwarts& other);
  Hogwarts(Hogwarts&& other);
  Hogwarts& operator=(const Hogwarts& other);
  Hogwarts& operator=(Hogwarts&& other);
  ~Hogwarts();

  friend std::ostream& operator<<(std::ostream& out, const Hogwarts& hogwarts);

  void addStudent(const Student& student);
  void assignHouse(const std::string& studentName, const std::string& house);
  void givePower(const std::string& name, const Power& power);

  int getHouseStudentsCount(const std::string& house);
  Student* getFirstStudent(const std::string& house);
  const Student* getStudents();
  bool removeStudent(const std::string& name);
};

#endif  // HOGWARTS_H