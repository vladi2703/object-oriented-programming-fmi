//
// Created by vladi on 5/19/2023.
//

#include "Bird.h"

int Bird::eat() const {
    // calculate the amount of food that the bird eats
    // cannot be decided in base class, because it is different for each bird
    // that is why we make eat pure virtual
    return weight / 10 + numberOfEggs;
}

Food Bird::getFoodType() const {
    return this->foodType;
}

Bird::Bird(const char *name, int weight, Food foodType, int numberOfEggs, const std::string& nameOfNestCity) : Animal(name, weight, foodType) {
    this->numberOfEggs = numberOfEggs;
    this->nameOfNestCity = nameOfNestCity;
}
