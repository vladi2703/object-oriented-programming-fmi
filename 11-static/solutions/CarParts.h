#pragma once
#include <string>
#include <iostream>
class CarPart
{
private:
	std::string name;
	std::string manufacturer;
	int year;
	int serialNumber;
	static int count;

protected:
	void displayBase() const;
public:
	static int getCarPartsCount();
	virtual void display() const = 0;
	virtual CarPart* copy() const = 0;

	CarPart(std::string name, std::string manufacturer, int year);
	virtual ~CarPart() = default;



};