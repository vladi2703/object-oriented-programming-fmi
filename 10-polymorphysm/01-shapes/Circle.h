#include <iostream>
#include "Shape.h"

#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle : public Shape
{
	double radius;

public:
	
	Circle(const std::string& label1, double radius1);

	Shape* copy() const;
	void print();
	double getPerimeter();
};

#endif