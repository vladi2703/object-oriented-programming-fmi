#include <string>
#include <vector>

// Define the Person class
class Person {
 protected:
  std::string firstName;
  std::string middleName;
  std::string lastName;

 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the Principal class, which inherits from Person
class Principal : public Person {
 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the Employee class, which also inherits from Person
class Employee : public Person {
 protected:
  std::string appointmentNumber;

 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the Teacher class, which inherits from Employee
class Teacher : public Employee {
 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the GradeEntry class
class GradeEntry {
  std::string subject;
  std::vector<int> grades;

 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the Gradebook class
class Gradebook {
  std::string studentUniqueId;
  std::vector<GradeEntry> entries;

 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the Student class, which inherits from Person
class Student : public Person {
  std::string uniqueId;
  std::string group;
  int grade;

 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the Lesson class
class Lesson {
  std::string subject;
  Teacher teacher;
  std::vector<std::string> studentGroupIds;

 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the ScheduleEntry class
class ScheduleEntry {
  int hour;
  Lesson lesson;

 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the Curriculum class
class Curriculum {
  std::vector<ScheduleEntry*> dailySchedule;

 public:
  // Constructors, destructors, getters, setters etc.
};

// Define the HighSchool class
class HighSchool {
  std::string name;
  Principal principal;
  std::vector<Teacher> teachers;
  std::vector<Student> students;
  std::vector<Gradebook> gradebooks;
  Curriculum curriculum;

 public:
  // Constructors, destructors, getters, setters etc.
};
