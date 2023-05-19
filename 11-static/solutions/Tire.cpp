#include "Tire.h"

Tire::Tire(double width, int profile, int diameter,
	std::string name, std::string manufacturer, int year)
	:CarPart(name, manufacturer, year), width(width), profile(profile), diameter(diameter)
{

}

void Tire::display() const
{
	displayBase();
	std::cout << this->diameter << this->width << this->profile;
}

CarPart* Tire::copy() const
{
	return new Tire(*this);
}
