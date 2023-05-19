//
// Created by vladi on 5/19/2023.
//

#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H


#include "Animal.h"

class Mammal : public Animal{
private:
    char* nameOfAdopter;
public:
    Mammal(const char* name, int weight, Food foodType, const char* nameOfAdopter);
    Mammal(const Mammal& other);
    Mammal(Mammal&& other) noexcept ;
    Mammal& operator=(const Mammal& other);
    Mammal& operator=(Mammal&& other) noexcept ;

    int eat() const override;

    Food getFoodType() const override;

    ~Mammal() override;
};


#endif //ZOO_MAMMAL_H
