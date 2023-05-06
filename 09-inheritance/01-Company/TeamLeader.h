#include <iostream>
#include <vector>
#include "Employee.h"

#ifndef TEAMLEADER_H
#define TEAMLEDAER_H

class TeamLeader : public Employee
{
	std::vector <Employee> team;
	std::string project_name;
		
public:
	TeamLeader(const std::string& name, double salary, const std::string &project_name,
		const std::vector <Employee> &team1);

	friend std::ostream& operator<<(std::ostream& str, const TeamLeader& obj);

	double getExpenses();
};

#endif