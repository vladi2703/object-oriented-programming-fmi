#include "Vehicle.h"

Vehicle::Vehicle(int hp1, int weight1)
	: hp(hp1), weight(weight1)
{
}

int Vehicle::getHp()
{
	return hp;
}

int Vehicle::getWeight()
{
	return weight;
}

Vehicle::~Vehicle()
{
}
