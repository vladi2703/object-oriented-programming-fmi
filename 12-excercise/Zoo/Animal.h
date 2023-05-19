#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H
#include <cstring>

enum class Food {
    MEAT,
    PLANTS,
    BOTH
};
class Animal {
private:
    char* name;
    static int countAnimalsBorn;
protected:
    int weight; // Bird needs to access it
    Food foodType;
public:
    Animal(const char* name, int weight, Food foodType);
    Animal(const Animal& other);
    Animal(Animal&& other);
    Animal& operator=(const Animal& other);
    Animal& operator=(Animal&& other);
    // can be not pure virtual, but for the sake of example we do it
    virtual int eat() const = 0;
    virtual Food getFoodType() const = 0;
    virtual ~Animal();

    static int getCountAnimalsBorn(); // cannot be const because it is static, so there is no object to be const
};


#endif //ZOO_ANIMAL_H
