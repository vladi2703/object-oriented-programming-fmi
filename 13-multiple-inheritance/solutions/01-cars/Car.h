#include "Vehicle.h"
#include "Property.h"

#ifndef CAR_H
#define CAR_H

class Car : public Property, public Vehicle
{
	char* brand_and_model;

	void copy(const Car& other);
	void erase();

public:
	Car(const char* str, int hp, int weight, const std::string& owner);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();

	void startEngine();
};

#endif