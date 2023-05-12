#include "ShapeContainer.h"

void ShapeContainer::addShape(const Shape& shape)
{
	Shape* obj = shape.copy();
	container.push_back(obj);
}

void ShapeContainer::printPerimeters()
{
	std::cout << "Perimeters: \n";
	for (int i = 0; i < container.size(); i++)
	{
		std::cout << container[i]->getLabel() << ": "
			<< container[i]->getPerimeter() << std::endl;
	}
}

void ShapeContainer::printShapes()
{
	for (int i = 0; i < container.size(); i++)
		container[i]->print();
}

ShapeContainer::~ShapeContainer()
{
	for (int i = 0; i < container.size(); i++)
		delete container[i];
}
