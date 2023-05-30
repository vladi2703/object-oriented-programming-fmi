#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Car.h"



void Car::copy(const Car& other)
{
	int len = strlen(other.brand_and_model);
	brand_and_model = new char[len + 1];
	strcpy(brand_and_model, other.brand_and_model);
}

void Car::erase()
{
	delete[] brand_and_model;
}

Car::Car(const char* str, int hp, int weight, const std::string& owner)
	: Vehicle(hp,weight), Property(owner, true)
{
	int len = strlen(str);
	brand_and_model = new char[len + 1];
	strcpy(brand_and_model, str);
}

Car::Car(const Car& other)
	:Property(other), Vehicle(other)
{
	copy(other);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
		Property::operator=(other);
		erase();
		copy(other);
	}
	return *this;
}

Car::~Car()
{
	erase();
}

void Car::startEngine()
{
	std::cout << "Vr";
	int hp = getHp();
	for (int i = 0; i < hp / 30; i++)
		std::cout << "o";

	std::cout << "m\n";
}
