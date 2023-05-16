#include <string>

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape
{
	std::string label;

public:

	Shape(const std::string& label1);

	const std::string& getLabel();

	virtual Shape* copy() const = 0;
	virtual void print() = 0;
	virtual double getPerimeter() = 0;

	virtual ~Shape();
};

#endif