#pragma once
#include "CarParts.h"
#include <iostream> 
class Tire : public CarPart
{
private: 
	double width; 
	int profile; 
	int diameter; 
public:
	Tire(double width, int profile, int diameter,
		std::string name, std::string manufacturer, int year);
	void display() const override;

	CarPart* copy() const override;
};

