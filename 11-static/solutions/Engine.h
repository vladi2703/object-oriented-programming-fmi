#pragma once
#include "CarParts.h"
#include "Piston.h"
#include <vector>

class Engine :
    public CarPart
{
private:
    int hp; 
    std::vector<Piston> pistons; 
public:
    Engine(int hp, 
        std::string name, std::string manufacturer, int year);
    void addPiston(const Piston& piston); 
    void display() const override; 
   
    CarPart* copy() const override;

};

