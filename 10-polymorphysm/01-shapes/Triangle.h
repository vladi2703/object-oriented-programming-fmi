#include "Shape.h"

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle : public Shape
{
	double side_a, side_b, side_c;

public:

	Triangle(const std::string& label1, double side_a1,double,double);

	double getPerimeter();

	void print();

	Shape* copy() const;
};

#endif
