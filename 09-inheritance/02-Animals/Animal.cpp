
#include "Animal.h"

void Animal::copyName(const char* name1)
{
	int len = strlen(name1);
	name = new char[len + 1];
	strcpy(name, name1);
}

void Animal::copy(const Animal& other)
{
	copyName(other.name);
	age = other.age;
}

void Animal::erase()
{
	delete[] name;
}

Animal::Animal()
{
	name = new char[1]{'\0'};
	age = 0;
}

Animal::Animal(const char* name1, unsigned age1)
{
	copyName(name1);
	age = age1;
}

Animal::Animal(const Animal& other)
{
	copy(other);
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

Animal::~Animal()
{
	erase();
}

void Animal::print()
{
	std::cout << "Name: " << name << ", Age: " << age<< std::endl;
}

void Animal::changeName(const char* name1)
{
	erase();
	copyName(name1);
}
