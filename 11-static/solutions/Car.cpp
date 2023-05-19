#include "Car.h"

void Car::copy(const Car& other)
{
	size = other.size;
	capacity = other.capacity;
	// преоразмеряваме и запълваме с nullptr
	container = new CarPart * [other.capacity];

	for (int i = 0; i < other.size; i++)
	{
		container[i] = other.container[i]->copy();
	}
}

void Car::resize()
{
	capacity *= 2;
	CarPart** new_container = new CarPart * [capacity];

	for (int i = 0; i < size; i++)
	{
		new_container[i] = container[i];
	}

	delete[] container;
	container = new_container;
}

void Car::erase()
{
	for (int i = 0; i < size; i++)
		delete container[i];

	delete[] container;
}

void Car::addCarPart(const CarPart& part)
{
	if (size == capacity)
		resize();

	container[size] = part.copy();
	size++;
}

void Car::printParts()
{
	std::cout << "Parts: \n";
	for (int i = 0; i < size; i++)
	{
		container[i]->display();
		std::cout   << std::endl;
	}
}

Car::Car()
// ако не укажем конструктора на вектора в иниц. списък,
// се вика конструктура му по подразбиране, който създава празен вектор
{
	size = 0;
	capacity = 8;
	container = new CarPart * [capacity];
}

Car::Car(const Car& other)
{
	copy(other);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

Car::~Car()
{
	erase();
}