#pragma once
#include "CarParts.h"
template <typename T> 
class FuelTank :
    public CarPart
{
private:
    T fuelType; 
    int volume; 
public:
    FuelTank(T fuelType, int volume,
        std::string name, std::string manufacturer, int year);
    void display() const override;
    CarPart* copy() const override;

};

template<typename T>
FuelTank<T>::FuelTank(T fuelType, int volume,
    std::string name, std::string manufacturer, int year)
    :CarPart(name,manufacturer, year), fuelType(fuelType), volume(volume)
{

}

template<typename T>
void FuelTank<T>::display() const
{
    this->displayBase(); 
    std::cout << volume << fuelType; 
}

template<typename T>
CarPart* FuelTank<T>::copy() const
{
    return new FuelTank<T>(*this);
}
