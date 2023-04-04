#include "Power.h"
#include "Student.h"
#include "Hogwarts.h"

void fightHouses(Hogwarts& hogwarts, const std::string& house1, const std::string& house2){
  std::cout << "Fight between " << house1 << " and " << house2 << std::endl;
}

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

  fightHouses(hogwarts, "Gryffindor", "Slytherin");
  return 0;
}