#include <vector>
#include <iostream>
#include "Shape.h"

#ifndef SHAPECONTAINER_H_
#define SHAPECONTAINER_H_

class ShapeContainer
{
	std::vector <Shape*> container;

	void copy(const ShapeContainer& other);
	void erase();

public:

	void addShape(const Shape& shape);
	void printPerimeters();
	void printShapes();

	ShapeContainer();
	ShapeContainer(const ShapeContainer& other);
	ShapeContainer& operator=(const ShapeContainer& other);
	~ShapeContainer();
};

#endif