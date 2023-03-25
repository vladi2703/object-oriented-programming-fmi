#include <iostream>
#include "ShoeShop.h"

int main()
{
	ShoeShop shop1(20);
	// когато нямаме собствен конструктор на Shoe, можем да ползваме следната агрегатна инициализация:
	Shoe shoe1{ "Gazelle BB54","Adidas",150, 0.5, 6 };
	Shoe shoe2{"Club 381","Puma", 120, 0.3, 10};
	Shoe shoe3{"Pados 10 174", "Lloyd", 230, 0.7, 3};
	shop1.addModel(shoe1);
	shop1.addModel(shoe2);
	shop1.addModel(shoe3);

	std::ofstream file("ShoeData.txt");
	if (!file)
	{
		std::cout << "Error opening file\n";
		return 0;
	}
	shop1.writeData(file);
	file.close();

	// четем от същия файл и записваме в shop2
	ShoeShop shop2(1);
	std::ifstream file2("ShoeData.txt");
	if (!file2)
	{
		std::cout << "Error opening file\n";
		return 0;
	}
	shop2.readData(file2);
	file2.close();
	
	try
	{
		shop2.addAmount("Pados 10 174", 2);
		shop2.changeRating("Gazelle BB54", 0.4);
		shop2.removeModel("Club 381");
		shop2.sellPair("Pados 10 174");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	file.open("ShoeData.txt");
	if (!file)
	{
		std::cout << "Error opening file\n";
		return 0;
	}
	shop2.writeData(file);
	file.close();


	// отворете файла за да видите резултата от програмата
}