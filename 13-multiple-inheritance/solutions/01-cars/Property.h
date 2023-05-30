#include <string>
#include <string>

#ifndef PROPERTY_H
#define PROPERTY_H

class Property
{
	std::string owner;
	bool tangible;

public:
	Property(const std::string& str, bool tang);

	const std::string& getOwner();
	bool isTangible();

};

#endif