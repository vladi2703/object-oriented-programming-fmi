#include "CarParts.h"

int CarPart::count = 0;

void CarPart::displayBase() const
{
	std::cout << name << manufacturer << year << serialNumber; 
}

int CarPart::getCarPartsCount()
{
	return count;
}

CarPart::CarPart(std::string name, std::string manufacturer, int year)
	:name(name), manufacturer(manufacturer), year(year)
{
	serialNumber = count++;
}