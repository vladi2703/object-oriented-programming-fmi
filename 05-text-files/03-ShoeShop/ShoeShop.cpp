#include "ShoeShop.h"



void ShoeShop::copy(const ShoeShop& other)
{
	cur_amount = other.cur_amount;
	max_amount = other.max_amount;
	shoes = new Shoe[max_amount];
	
	for (int i = 0; i < cur_amount; i++)
		shoes[i] = other.shoes[i];
}

void ShoeShop::erase()
{
	delete[] shoes;
}

int ShoeShop::findIndex(std::string model)
{
	for (int i = 0; i < cur_amount; i++)
		if (shoes[i].model == model)
			return i;
	return -1;
}

ShoeShop::ShoeShop(size_t max_amount)
{
	if (max_amount == 0)
		max_amount = 1; // може да имплементирате и магазин с нула обувки, но трябва да се разглеждат доста случаи

	this->max_amount = max_amount;
	cur_amount = 0;

	shoes = new Shoe[max_amount];
}

ShoeShop::ShoeShop(const ShoeShop& other)
{
	copy(other);
}

ShoeShop& ShoeShop::operator=(const ShoeShop& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

ShoeShop::~ShoeShop()
{
	delete[] shoes;
}

void ShoeShop::addModel(const Shoe& shoe)
{
	int index = findIndex(shoe.model);
	if (index != -1 || shoe.pair_amount == 0 || cur_amount == max_amount)
		// този модел вече го има или искаме да добавим 0 количество или няма повече място
		throw std::exception("failed operation add model");
	
	shoes[cur_amount] = shoe;
	cur_amount++;
}

void ShoeShop::sellPair(std::string model)
{
	int index = findIndex(model);
	if (index == -1)
		throw std::exception("failed operation sell pair");

	shoes[index].pair_amount--;
	if (shoes[index].pair_amount == 0)
		removeModel(model);
}

void ShoeShop::addAmount(std::string model, int amount)
{
	int index = findIndex(model);
	if (index == -1)
		throw std::exception("failed operation add amount");

	shoes[index].pair_amount += amount;
}

void ShoeShop::changeRating(std::string model, double new_rating)
{
	int index = findIndex(model);
	if (index == -1)
		throw std::exception("failed operation change rating");

	shoes[index].rating = new_rating;
}

void ShoeShop::removeModel(std::string model)
{
	int index = findIndex(model);
	if (index == -1)
		throw std::exception("failed operation remove model");

	// преместваме с едно наляво за да "запълним" дупката
	for (int i = index; i < cur_amount - 1; i++)
		shoes[i] = shoes[i + 1];

	cur_amount--;
}

void ShoeShop::readData(std::ifstream& stream)
{
	erase();
	stream >> max_amount >> cur_amount;
	stream.ignore(); // за да прочетем и остатъчния символ нов ред 
	shoes = new Shoe[max_amount];
	for (int i = 0; i < cur_amount; i++)
		shoes[i].readData(stream);
}

void ShoeShop::writeData(std::ofstream& stream)
{
	stream << max_amount << std::endl;
	stream << cur_amount << std::endl;
	for (int i = 0; i < cur_amount; i++)
		shoes[i].writeData(stream);
}
