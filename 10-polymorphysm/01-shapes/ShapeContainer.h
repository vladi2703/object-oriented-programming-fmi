#include <vector>
#include <iostream>
#include "Shape.h"

#ifndef SHAPECONTAINER_H_
#define SHAPECONTAINER_H_

class ShapeContainer
{
	std::vector <Shape*> container;

public:

	void addShape(const Shape& shape);
	void printPerimeters();
	void printShapes();

	~ShapeContainer();
};

#endif