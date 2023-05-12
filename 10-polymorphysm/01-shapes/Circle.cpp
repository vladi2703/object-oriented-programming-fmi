#include "Circle.h"

Circle::Circle(const std::string& label1, double radius1) 
	: Shape(label1), radius(radius1)
{
}

Shape* Circle::copy() const
{
	return new Circle(*this);
}

void Circle::print()
{
	std::cout <<"    _   \n";
	std::cout <<" /     \\ \n";
	std::cout <<"|       |\n";
	std::cout <<" \\  _  /\n";
	std::cout <<"\n";
}

double Circle::getPerimeter()
{
	const double PI = 3.14;
	return 2*PI*radius;
}
