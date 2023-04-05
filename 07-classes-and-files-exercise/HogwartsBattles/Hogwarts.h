//
// Created by vladi on 4/5/2023.
//

#ifndef HOGWARTS_H
#define HOGWARTS_H

#include "Student.h"

class Hogwarts {
 public:
  Hogwarts();
  Hogwarts(const Hogwarts& other);
  Hogwarts(Hogwarts&& other);
  Hogwarts& operator=(const Hogwarts& other);
  Hogwarts& operator=(Hogwarts&& other) noexcept;
  ~Hogwarts();

  friend std::ostream& operator<<(std::ostream& out, const Hogwarts& hogwarts);

  void addStudent(const Student& student);
  void assignHouse(const std::string& studentName, const std::string& house);
  void givePower(const std::string& name, const Power& power);
  int getHouseStudentsCount(const std::string& house) const;
  Student* getFirstStudent(const std::string& house);
  const Student* getStudents() const;
  bool removeStudent(const std::string& name);

 private:
  void clear();

  Student* students_;
  int numStudents_;
  int capacity_;
};

#endif  // HOGWARTS_H
