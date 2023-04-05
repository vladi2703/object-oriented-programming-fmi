#include "Power.h"

Power::Power(const std::string &name, int damage) : name_(name), damage_(damage) {}
int Power::getDamage() const { return damage_; }
const std::string &Power::getName() const { return name_; }
bool Power::operator<(const Power &other) const { return damage_ < other.damage_; }
