//
// Created by vladi on 5/19/2023.
//

#ifndef ZOO_ZOOSECTOR_H
#define ZOO_ZOOSECTOR_H
#include <vector>

template <typename AnimalType>
class ZooSector {
    std::vector<AnimalType> animals;
    int x, y; // coordinates of the sector
public:
    void addAnimal(AnimalType animal);
    // We don't need to implement rule of 3, because we don't have any dynamic memory
    // AnimalType is not a pointer, so we don't need to delete it
    // AnimalType has the responsibility to delete itself
};


template<typename AnimalType>
void ZooSector<AnimalType>::addAnimal(AnimalType animal) {
    this->animals.push_back(animal);
}


#endif //ZOO_ZOOSECTOR_H
