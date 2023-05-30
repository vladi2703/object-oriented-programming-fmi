#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
	int hp; // horse power
	int weight;

public:
	Vehicle(int hp1, int weight1);

	int getHp();
	int getWeight();

	virtual void startEngine() = 0;

	virtual ~Vehicle();
};

#endif