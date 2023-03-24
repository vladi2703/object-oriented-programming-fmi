#include <string>
#include <fstream>

#ifndef SHOE_H
#define SHOE_H
/*
компилатора сам създава голяма четворка, ако ние не я направим
копи-конструктора и оператора за присвояване генерирани от компилатора просто сляпо копират всичко
и съответно викат копи-конструктора и оператора за присвояване на член-данните от обектен тип (например std::string)
те не работят когато имаме динамична памет
*/
class Shoe
{
public:
	std::string model, producer;
	double price,rating;
	size_t pair_amount;

	/*  тези функции може да се реализират и по следния начин, чрез опратори >> <<:
	friend std::ofstream& operator<<(std::ofstream &stream, const Shoe&);
	friend std::ifstream& operator>>(std::ifstream &stream, const Shoe&);

	*/

	void readData(std::ifstream& stream);
	void writeData(std::ofstream& stream);
};

#endif