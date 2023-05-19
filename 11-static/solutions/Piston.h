#pragma once
#include "CarParts.h"
class Piston : public CarPart
{
private:
    double diameter; 
    double range; 
public:
    void display() const override; 

    Piston(double range, double diameter,
        std::string name, std::string manufacturer, int year);

    CarPart* copy() const override;
    
};

