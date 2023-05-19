//
// Created by vladi on 5/19/2023.
//

#include "Mammal.h"

int Mammal::eat() const {
    return 4; // each mammal eats 4 kg food xD
}

Food Mammal::getFoodType() const {
    return this->foodType;
}

Mammal::~Mammal() {
  delete[] this->nameOfAdopter;
  // Animal fields are deleted by Animal destructor
}

Mammal::Mammal(const char *name, int weight, Food foodType, const char *nameOfAdopter)  :
Animal(name, weight, foodType){
    this->nameOfAdopter = new char[strlen(nameOfAdopter) + 1];
    strcpy(this->nameOfAdopter, nameOfAdopter);

}

Mammal::Mammal(const Mammal &other) : Animal(other){
    this->nameOfAdopter =  new char[strlen(other.nameOfAdopter) + 1];
    strcpy(this->nameOfAdopter, other.nameOfAdopter);
}

Mammal::Mammal(Mammal &&other)  noexcept : Animal(other){
    this->nameOfAdopter = other.nameOfAdopter;
    other.nameOfAdopter = nullptr;
}

Mammal &Mammal::operator=(const Mammal &other) {
    if (this != &other) {
        Animal::operator=(other); // Animal copy assignment operator, we choose it, because of the type of other
        this->nameOfAdopter = new char[strlen(other.nameOfAdopter) + 1];
        strcpy(this->nameOfAdopter, other.nameOfAdopter);
    }
    return *this;
}

Mammal &Mammal::operator=(Mammal &&other)  noexcept {
    if (this != &other) {
        Animal::operator=(other); // Animal move assignment operator, we choose it, because of the type of other
        this->nameOfAdopter = other.nameOfAdopter;
        other.nameOfAdopter = nullptr;
    }
    return *this;
}
