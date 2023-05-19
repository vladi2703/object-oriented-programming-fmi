#ifndef ZOO_BIRD_H
#define ZOO_BIRD_H

#include <string>
#include "Animal.h"
class Bird : public Animal{
private:
    int numberOfEggs;
    std::string nameOfNestCity;
public:
    Bird(const char* name, int weight, Food foodType, int numberOfEggs, const std::string& nameOfNestCity);
    int eat() const override;
    Food getFoodType() const override;
    ~Bird() override = default; // this line can be omitted
    // default destructor is enough, because we don't have any dynamic memory
};


#endif //ZOO_BIRD_H
