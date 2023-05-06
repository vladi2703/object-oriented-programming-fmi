#include <iostream>
#include "Pet.h"

int main()
{
	Pet dog("Rex", 5, "Ivan", 36912345),dog2;
	dog2 = dog;
	dog2.print();

	dog2.changeName("Doggo");
	dog2.changeOwner("Petur",123456);

	dog2.print();

}