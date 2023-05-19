#include "Animal.h"

int Animal::countAnimalsBorn = 0;


Animal::Animal(const char *name, int weight, Food foodType) {
    /* Although we cannot create an object of type animal, we can use constructors in children */
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->weight = weight;
    this->foodType = foodType;
    countAnimalsBorn++;
}

Animal::Animal(const Animal &other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->weight = other.weight;
    this->foodType = other.foodType;
    countAnimalsBorn++;
}

Animal::Animal(Animal &&other) {
    this->name = other.name;
    this->weight = other.weight;
    this->foodType = other.foodType;
    other.name = nullptr;
    other.weight = 0;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->weight = other.weight;
        this->foodType = other.foodType;
    }
    return *this;
}

Animal &Animal::operator=(Animal &&other) {
    if (this != &other) {
        this->name = other.name;
        this->weight = other.weight;
        this->foodType = other.foodType;
    }
    other.name = nullptr;
    other.weight = 0;
    return *this;
}

Animal::~Animal() {
    delete[] this->name;

}

int Animal::getCountAnimalsBorn() {
    return countAnimalsBorn;
}

