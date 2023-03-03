#include "Shop.h"
#include <iostream>

void Shop::initialize(int max_count)
{
	if (max_count < 0)
		this->max_count = 20;
	else
	{
		this->max_count = max_count;
		count = income = expences = 0;
	}
}

void Shop::orderWafers(Wafer wafer, int count)
{
	if (this->count != 0)
		throw std::exception("Shop not empty");
	if(max_count < count || count < 1)
		throw std::exception("Not enough space");

	example_wafer = wafer;
	this->count = count;

	expences += wafer.factory_price * count;
}

void Shop::sellWafer()
{
	if (count == 0)
		throw std::exception("No wafers");
	count--;
	income += example_wafer.client_price;
}

void Shop::printShop()
{
	std::cout << count << " wafers of brand " << example_wafer.brand << std::endl;
	std::cout << "Total weight: " << example_wafer.weight * count << std::endl;
}

void Shop::printProfit()
{
	std::cout << "Profit: " << income - expences << std::endl;
}
