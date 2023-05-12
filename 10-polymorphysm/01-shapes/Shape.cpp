#include "Shape.h"

Shape::Shape(const std::string& label1) : label(label1)
{
}

const std::string& Shape::getLabel()
{
	return label;
}

// деструктора нищо не прави, но трябва да го напишем явно и да е виртуален винаги
// когато ползваме полиморфизъм
Shape::~Shape()
{
}
