#include "ShapeContainer.h"

void ShapeContainer::copy(const ShapeContainer& other)
{
	// преоразмеряваме и запълваме с nullptr
	container.resize(other.container.size(), nullptr);
	
	for (int i = 0; i < container.size(); i++)
	{
		container[i] = other.container[i]->copy();
	}
}

void ShapeContainer::erase()
{
	for (int i = 0; i < container.size(); i++)
		delete container[i];
}

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

ShapeContainer::ShapeContainer()
// ако не укажем конструктора на вектора в иниц. списък,
// се вика конструктура му по подразбиране, който създава празен вектор
{
	
}

ShapeContainer::ShapeContainer(const ShapeContainer& other)
{
	copy(other);
}

ShapeContainer& ShapeContainer::operator=(const ShapeContainer& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

ShapeContainer::~ShapeContainer()
{
	erase();
}
