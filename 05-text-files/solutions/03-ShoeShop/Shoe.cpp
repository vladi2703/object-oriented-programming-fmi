#include "Shoe.h"

void Shoe::readData(std::ifstream& stream)
{
	std::getline(stream, model);
	std::getline(stream, producer);
	stream >> price >> rating >> pair_amount;
	stream.ignore(); // за да прочетем и остатъчния символ нов ред 
}

void Shoe::writeData(std::ofstream& stream)
{
	stream << model << std::endl;
	stream << producer << std::endl;
	stream << price<< std::endl;
	stream << rating<< std::endl;
	stream << pair_amount<< std::endl;
}
