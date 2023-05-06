#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
	// може би трябваше да добавя и вид на животното в условието...
	char* name;
	unsigned age;

	void copyName(const char*);
	void copy(const Animal&);
	void erase();

public:
	Animal();
	Animal(const char*, unsigned);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	~Animal();

	void print();
	void changeName(const char*);
};

#endif
