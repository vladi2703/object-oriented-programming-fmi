#include "CarParts.h"

#ifndef CAR_H_
#define CAR_H_

class Car
{
	int size, capacity;
	CarPart ** container;

	void copy(const Car& other);
	void resize();
	void erase();

public:

	void addCarPart(const CarPart& shape);
	void printParts();

	Car();
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();
};

#endif