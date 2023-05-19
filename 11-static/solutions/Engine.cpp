#include "Engine.h"

Engine::Engine(int hp, 
	std::string name, std::string manufacturer, int year)
	:hp(hp), CarPart(name, manufacturer, year)
{
	
}

void Engine::addPiston(const Piston& piston)
{
	pistons.push_back(piston); 
}

void Engine::display() const
{
	this->displayBase(); 
	std::cout << hp;
	for (int i = 0; i < pistons.size(); i++) {
		pistons[i].display(); 
	}
}

CarPart* Engine::copy() const
{
	return new Engine(*this);
}
