//
// Created by vladi on 5/19/2023.
//

#include <iostream>
#include "Zoo.h"

void Zoo::resize() {
    this->capacity *= 2;
    Animal** newAnimals = new Animal*[this->capacity];
    for (int i = 0; i < this->size; i++) {
        newAnimals[i] = this->animals[i];
    }
    delete[] this->animals;
    this->animals = newAnimals;
}

Zoo::Zoo(Zoo &&other) noexcept {
    this->size = other.size;
    this->capacity = other.capacity;
    this->animals = other.animals;
    other.animals = nullptr;
}

Zoo &Zoo::operator=(Zoo &&other) noexcept {
    if (this == &other) {
        return *this;
    }

    this->size = other.size;
    this->capacity = other.capacity;
    this->animals = other.animals;
    other.animals = nullptr;
    return *this;
}

Zoo::~Zoo() {
    for (int i = 0; i < this->size; i++) {
        delete this->animals[i];
    }
    delete[] this->animals;
}

void Zoo::addAnimal(Animal *animal) {
    if (this->size == this->capacity) {
        this->resize();
    }
    this->animals[this->size++] = animal;
}

Zoo::Zoo() : size(0), capacity(1){
   this -> animals = new Animal*[capacity];
}

void Zoo::addMammal(Mammal& mammal) {
    this->mammals.addAnimal(mammal);
    this->addAnimal(new Mammal(mammal));
    // make a copy so that we don't share memory with the mammals in the mammals array
}

void Zoo::addBird(Bird& bird) {
    this->birds.addAnimal(bird);
    this->addAnimal(new Bird(bird));
    // make a copy so that we don't share memory with the birds in the birds array
}




void Zoo::feedAnimals() {
    int kgOfMeatEatenToday = 0;
    int kgOfPlantsEatenToday = 0;

    for(int i =0; i < this->size; i++){
        switch (animals[i]->getFoodType()) {
            case Food::MEAT:
                kgOfMeatEatenToday += animals[i]->eat();
                this->kgOfMeat -= animals[i]->eat();
                break;
            case Food::PLANTS:
                kgOfPlantsEatenToday += animals[i]->eat();
                this->kgOfPlants -= animals[i]->eat();
                break;
            case Food::BOTH:
                kgOfMeatEatenToday += animals[i]->eat() / 2;
                kgOfPlantsEatenToday += animals[i]->eat() / 2;
                this->kgOfMeat -= animals[i]->eat() / 2;
                this->kgOfPlants -= animals[i]->eat() / 2;
                break;
        }
    }
    std::cout << "Today the animals ate " << kgOfMeatEatenToday << "kg of meat and " << kgOfPlantsEatenToday << "kg of plants" << std::endl;
}

void Zoo::getCountOfAnimalsBorn() {
    std::cout << "There are " << Animal::getCountAnimalsBorn() << " born" << std::endl;
}



