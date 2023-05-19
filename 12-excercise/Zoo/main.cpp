#include <iostream>
#include "Zoo.h"
int main() {
    Zoo zoo;
    Mammal elephant("Slon", 10, Food::MEAT, "Petkan");
    Bird nightingale("Slavei", 10, Food::PLANTS, 10, "Selo Slaveevo");
    zoo.addMammal(elephant);
    zoo.addBird(nightingale);
    zoo.feedAnimals();


    return 0;
}
