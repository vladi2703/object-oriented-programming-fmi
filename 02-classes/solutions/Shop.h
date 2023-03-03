#ifndef SHOP_H_
#define SHOP_H_

#include "Wafer.h"

class Shop
{
private:
	Wafer example_wafer;
	int count, max_count;
	double income, expences;

public:
	void initialize(int max_count);
	void orderWafers(Wafer waffle, int count);
	void sellWafer();
	void printShop();
	void printProfit();
};

#endif
