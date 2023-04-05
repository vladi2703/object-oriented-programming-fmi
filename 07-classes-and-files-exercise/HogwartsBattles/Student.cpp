#include "Student.h"

Student::Student(const std::string &name)
        : name_(name), house_(""), health_(100), power_(nullptr) {}

const std::string &Student::getName() const { return name_; }
const std::string &Student::getHouse() const { return house_; }
void Student::setHouse(const std::string &house) { house_ = house; }
int Student::getHealth() const { return health_; }
void Student::takeDamage(int damage) { health_ -= damage; }
void Student::setPower(const Power *power) { power_ = power; }
const Power *Student::getPower() const { return power_; }
bool Student::isAlive() const { return health_ > 0; }
int Student::attack() const { return power_ ? power_->getDamage() : 0; }
