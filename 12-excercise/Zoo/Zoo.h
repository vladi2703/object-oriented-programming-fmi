#ifndef ZOO_ZOO_H
#define ZOO_ZOO_H

#include <vector>
#include "Animal.h" // we need to include it, because we use it in the vector
#include "Mammal.h"
#include "Bird.h"
#include "ZooSector.h"
// but we don't need to INHERIT it - Zoo !!is not!! an Animal

class Zoo {
private:
    Animal** animals;
    int size;
    int capacity;
    ZooSector<Mammal> mammals;
    ZooSector<Bird> birds;
    void resize();
    int kgOfMeat;
    int kgOfPlants;

public:

    Zoo();
    Zoo(Zoo&& other) noexcept ;
    Zoo& operator=(Zoo&& other) noexcept ;
    ~Zoo();


    Zoo(const Zoo& other) = delete; // we don't want to copy a sector
    Zoo& operator=(const Zoo& other) = delete; // we don't want to copy a sector
    /* If we want to copy a sector, we need to copy all the animals in it
    So each animal needs to know how to copy itself
    For this we need to implement clone() method in Animal
    And each of the children need to implement it */

    void addAnimal(Animal* animal);
    void addMammal(Mammal& mammal);
    void addBird(Bird& bird);
    void feedAnimals();

    static void getCountOfAnimalsBorn();
};


#endif //ZOO_ZOO_H
