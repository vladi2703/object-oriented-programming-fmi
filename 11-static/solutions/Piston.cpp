#include "Piston.h"

void Piston::display() const
{
	this->displayBase(); 
	std::cout << diameter << " " << range;
}

Piston::Piston(double range, double diameter, std::string name, std::string manufacturer, int year)
	:CarPart(name,manufacturer,year), range(range), diameter(diameter)
{

}

CarPart* Piston::copy() const
{
	return new Piston(*this);
}
