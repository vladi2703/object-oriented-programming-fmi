#include <iostream>
#include "Square.h"

Square::Square(const std::string& label1, double side1):
	Shape(label1), side(side1)
{
}

double Square::getPerimeter()
{
	return 4 * side;
}

void Square::print()
{
	std::cout << " ___\n";
	std::cout << "|   |\n";
	std::cout << "|___| \n";
	std::cout << "\n";
}

Shape* Square::copy() const
{
	Shape* ptr = new Square(*this);
	return ptr;
}
