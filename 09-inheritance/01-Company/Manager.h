#include "TeamLeader.h"

#ifndef MANAGER_H
#define MANAGER_H

class Manager : public Employee
{
	std::vector <TeamLeader> leaders;

public:
	Manager(const std::string& name, double salary,
		std::vector <TeamLeader> leaders1);

	friend std::ostream& operator<<(std::ostream& str, const Manager& obj);

	double getExpenses();
};

#endif