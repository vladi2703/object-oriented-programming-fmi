#include "Hogwarts.h"

#include <iostream>

void Hogwarts::clear() {
  delete[] students_;
  students_ = nullptr;
  numStudents_ = 0;
  capacity_ = 0;
}
Hogwarts::Hogwarts() : students_(nullptr), numStudents_(0), capacity_(0) {}

Hogwarts::Hogwarts(const Hogwarts &other)
    : students_(nullptr), numStudents_(0), capacity_(0) {
  for (int i = 0; i < other.numStudents_; ++i) {
    addStudent(other.students_[i]);
  }
}

Hogwarts &Hogwarts::operator=(Hogwarts &&other) noexcept {
  if (this != &other) {
    clear();  // first clear the current object
    students_ = other.students_;
    numStudents_ = other.numStudents_;
    capacity_ = other.capacity_;
    other.students_ = nullptr;
    other.numStudents_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}

Hogwarts::Hogwarts(Hogwarts &&other)
    : students_(other.students_),
      numStudents_(other.numStudents_),
      capacity_(other.capacity_) {
  other.students_ = nullptr;
  other.numStudents_ = 0;
  other.capacity_ = 0;
}

Hogwarts &Hogwarts::operator=(const Hogwarts &other) {
  if (this != &other) {
    clear();
    for (int i = 0; i < other.numStudents_; ++i) {
      addStudent(other.students_[i]);
    }
  }
  return *this;
}

Hogwarts::~Hogwarts() { clear(); }

const Student *Hogwarts::getStudents() const { return students_; }

bool Hogwarts::removeStudent(const std::string &name) {
  for (int i = 0; i < numStudents_; ++i) {
    if (students_[i].getName() == name) {
      for (int j = i; j < numStudents_ - 1; ++j) {  // shift the array
        students_[j] = students_[j + 1];
      }
      numStudents_--;
      return true;
    }
  }
  return false;
}

void Hogwarts::addStudent(const Student &student) {
  if (numStudents_ == capacity_) {  // check if we need to resize
    capacity_ = capacity_ == 0 ? 1 : capacity_ * 2;  // double the capacity
    Student *newStudents = new Student[capacity_];   // allocate new array
    for (int i = 0; i < numStudents_; ++i) {         // copy the old array
      newStudents[i] = students_[i];
    }
    delete[] students_;       // delete the old array
    students_ = newStudents;  // update the pointer
  }
  students_[numStudents_] = student;  // add the new student
  numStudents_++;                     // update the number of students
}

void Hogwarts::assignHouse(const std::string &studentName,
                           const std::string &house) {
  for (int i = 0; i < numStudents_; ++i) {
    if (students_[i].getName() == studentName) {  // find the student
      students_[i].setHouse(house);
      break;
    }
  }
}

void Hogwarts::givePower(const std::string &name, const Power &power) {
  for (int i = 0; i < numStudents_; ++i) {
    if (students_[i].getName() == name) {
      students_[i].setPower(&power);
      break;
    }
  }
}

int Hogwarts::getHouseStudentsCount(const std::string &house) const {
  int count = 0;
  for (int i = 0; i < numStudents_; ++i) {
    if (students_[i].getHouse() == house) {
      count++;
    }
  }
  return count;
}

Student *Hogwarts::getFirstStudent(const std::string &house) {
  for (int i = 0; i < numStudents_; ++i) {
    if (students_[i].getHouse() == house) {
      return &students_[i];
    }
  }
  return nullptr;
}

std::ostream &operator<<(std::ostream &out, const Hogwarts &hogwarts) {
  for (int i = 0; i < hogwarts.numStudents_; ++i) {
    out << hogwarts.students_[i].getName() << " ("
        << hogwarts.students_[i].getHouse() << ")" << std::endl;
  }
  return out;
}
