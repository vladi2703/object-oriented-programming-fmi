#include "Pet.h"

void Pet::copyName(const char* name1)
{
	int len = strlen(name1);
	owner_name = new char[len + 1];
	strcpy(owner_name, name1);
}

void Pet::copy(const Pet& other)
{
	copyName(other.owner_name);
	phone_number = other.phone_number;
}

void Pet::erase()
{
	delete[] owner_name;
}

Pet::Pet() // ако не сме указали кой, извиква се конструктора по подразбиране на базовия клас
{
	owner_name = new char[1]{ '\0' };
	phone_number = 0;
}

Pet::Pet(const char* name, unsigned age, const char* owner, unsigned number):
	Animal(name,age) // викаме наследения конструктор
{
	copyName(owner);
	phone_number = number;
}

Pet::Pet(const Pet& other) : Animal(other)
{
	copy(other);
}

Pet& Pet::operator=(const Pet& other)
{
	if (this != &other)
	{
		Animal::operator=(other); // викаме наследената версия на оператора
		erase();
		copy(other);
	}
	return *this;
}

Pet::~Pet()
{
	// деструктора на базовия клас се вика автоматично
	erase();
}

void Pet::print()
{
	Animal::print();
	std::cout << "Owner name: " << owner_name << ", Phone number: " << phone_number << std::endl;
}

void Pet::changeOwner(const char* name1, unsigned number)
{
	erase();
	copyName(name1);
	phone_number = number;
}
