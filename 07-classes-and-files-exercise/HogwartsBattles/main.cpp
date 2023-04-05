#include <iostream>
#include <string>

#include "Hogwarts.h"
#include "Power.h"
#include "Student.h"

int main() {
  Power spell("Expelliarmus", 10);
  Power curse("Cruciatus", 20);
  Power charm("Lumos", 5);

  Hogwarts hogwarts;

  // Add some students
  hogwarts.addStudent(Student("Harry Potter"));
  hogwarts.addStudent(Student("Ron Weasley"));
  hogwarts.addStudent(Student("Hermione Granger"));
  hogwarts.addStudent(Student("Draco Malfoy"));
  hogwarts.addStudent(Student("Luna Lovegood"));

  // Assign them to houses
  hogwarts.assignHouse("Harry Potter", "Gryffindor");
  hogwarts.assignHouse("Ron Weasley", "Gryffindor");
  hogwarts.assignHouse("Hermione Granger", "Gryffindor");
  hogwarts.assignHouse("Draco Malfoy", "Slytherin");
  hogwarts.assignHouse("Luna Lovegood", "Ravenclaw");

  // Give them powers
  hogwarts.givePower("Harry Potter", spell);
  hogwarts.givePower("Ron Weasley", spell);
  hogwarts.givePower("Hermione Granger", curse);
  hogwarts.givePower("Draco Malfoy", curse);
  hogwarts.givePower("Luna Lovegood", charm);

  std::cout << "Students in Hogwarts: \n" << hogwarts << std::endl;

  // Fight!
  while (hogwarts.getHouseStudentsCount("Gryffindor") > 0 &&
         hogwarts.getHouseStudentsCount("Slytherin") > 0) {
    // Choose two random students from different houses
    Student* student1 = nullptr;
    Student* student2 = nullptr;
    while (student1 == nullptr || student2 == nullptr ||
           student1->getHouse() == student2->getHouse()) {
      student1 = hogwarts.getFirstStudent("Gryffindor");
      student2 = hogwarts.getFirstStudent("Slytherin");
    }
    std::cout << "Fight between " << student1->getName() << " (Gryffindor) and "
              << student2->getName() << " (Slytherin)" << std::endl;

    // Fight until one of them dies
    while (true) {
      if (!student1->isAlive()) {
        std::cout << student2->getName() << " (Slytherin) wins!" << std::endl;
        hogwarts.removeStudent(student1->getName());
        student1 = nullptr;
        break;
      }
      // Student 1 attacks student 2
      int damage = student1->attack();
      if (damage > 0) {
        student2->takeDamage(damage);
        std::cout << student1->getName() << " [" << student1->getHealth()
                  << "] "
                  << "(Gryffindor) attacks " << student2->getName()
                  << " (Slytherin) with " << student1->getPower()->getName()
                  << " for " << damage << " damage" << std::endl;
      }

      // Check if student 2 is still alive
      if (!student2->isAlive()) {
        std::cout << student1->getName() << " (Gryffindor) wins!" << std::endl;
        hogwarts.removeStudent(student2->getName());
        student2 = nullptr;
        break;
      }

      // Student 2 attacks student 1
      damage = student2->attack();
      if (damage > 0) {
        student1->takeDamage(damage);
        std::cout << student2->getName() << " [" << student2->getHealth()
                  << "] "
                  << " (Slytherin) attacks " << student1->getName()
                  << " (Gryffindor) with " << student2->getPower()->getName()
                  << " for " << damage << " damage" << std::endl;
      }
    }
  }
  // Declare the winning house
  if (hogwarts.getHouseStudentsCount("Gryffindor") > 0)
    std::cout << "Gryffindor wins!" << std::endl;
  else
    std::cout << "Slytherin wins!" << std::endl;
  return 0;
}