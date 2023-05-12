#include <iostream>
#include "Triangle.h"

Triangle::Triangle(const std::string& label1, double side_a1, double side_b1, double side_c1):
	Shape(label1), side_a(side_a1), side_b(side_b1), side_c(side_c1)
{
}

double Triangle::getPerimeter()
{
	return side_a + side_b + side_c;
}

void Triangle::print()
{
	std::cout<<" /\\ \n";
	std::cout<<"/__\\ \n";
	std::cout<<"\n";
}

Shape* Triangle::copy() const
{
	return new Triangle(*this);
}
