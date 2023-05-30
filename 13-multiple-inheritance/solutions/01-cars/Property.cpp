#include "Property.h"

Property::Property(const std::string& str, bool tang)
	: owner(str), tangible(tang)
{
}

const std::string& Property::getOwner()
{
	return owner;
}

bool Property::isTangible()
{
	return tangible;
}
