#include <iostream>
#include "Shop.h"

int main()
{
	Shop shop;
	shop.initialize(50);

	Wafer wafer{ "Borovec",0.05,1.50,0.80 };

	shop.orderWafers(wafer, 30);
	shop.printProfit();
	shop.printShop();

	std::cout << " \nSelling 20 wafers..\n " << std::endl;
	for (int i = 1; i <= 20; i++)
		shop.sellWafer();

	shop.printProfit();
	shop.printShop();
}