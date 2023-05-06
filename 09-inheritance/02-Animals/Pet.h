#include "Animal.h"

#ifndef PET_H
#define PET_H

class Pet : public Animal
{
	char* owner_name;
	unsigned phone_number;

	void copyName(const char*);
	void copy(const Pet&);
	void erase();

public:
	Pet();
	Pet(const char* name, unsigned age, const char* owner, unsigned number);
	Pet(const Pet&);
	Pet& operator=(const Pet&);
	~Pet();

	void print();
	void changeOwner(const char* name1, unsigned number);
};

#endif

