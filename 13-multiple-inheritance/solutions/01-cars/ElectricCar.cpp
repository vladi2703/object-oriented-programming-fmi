#include <iostream>

#include "ElectricCar.h"

ElectricCar::ElectricCar(const char* str, int hp, int weight, const std::string& owner)
	:Car(str,hp,weight,owner)
{
}

void ElectricCar::startEngine()
{
	std::cout << "(No Sound)\n";
}
