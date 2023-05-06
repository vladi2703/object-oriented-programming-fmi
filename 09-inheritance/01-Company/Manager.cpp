#include "Manager.h"

Manager::Manager(const std::string& name, double salary,
	std::vector<TeamLeader> leaders1) :
	Employee(name, salary), leaders(leaders1)
{
}

double Manager::getExpenses()
{
	double value = getSalary();
	for (int i = 0; i < leaders.size(); i++)
		value += leaders[i].getExpenses();

	return value;
}

std::ostream& operator<<(std::ostream& str, const Manager& obj)
{
	const Employee& ref = obj; // ref ни позволява да третираме obj като обект от тип Employee

	str << "Manager: ";
	str << ref; // така извикваме версията на << която работи с обект Employee
	str << "Projects: " << std::endl;
	for (int i = 0; i < obj.leaders.size(); i++)
	{
		str << obj.leaders[i];
	}

	return str;
}
