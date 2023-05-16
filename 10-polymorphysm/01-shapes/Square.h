#include "Shape.h"

#ifndef SQAURE_H_
#define SQAURE_H_

class Square : public Shape
{
	double side;

public:

	Square(const std::string &label1, double side1);

	double getPerimeter();

	void print();

	Shape* copy() const;
};

#endif