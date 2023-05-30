#include "Car.h"

#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

class ElectricCar : public Car
{
public:
	ElectricCar(const char* str, int hp, int weight, const std::string& owner);

	void startEngine();
};

#endif