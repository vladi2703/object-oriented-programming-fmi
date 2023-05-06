#include "TeamLeader.h"

TeamLeader::TeamLeader(const std::string& name1, double salary1, const std::string& project_name1,
	const std::vector<Employee> & team1) : // викаме наследения конструнктор
	Employee(name1, salary1), project_name(project_name1), team(team1)
{
}

double TeamLeader::getExpenses()
{
	double value = getSalary();
	for (int i = 0; i < team.size(); i++)
		value += team[i].getSalary();

	return value;
}

std::ostream& operator<<(std::ostream& str, const TeamLeader& obj)
{
	const Employee& ref = obj; // ref ни позволява да третираме obj като обект от тип Employee
	
	str << "Project: " << obj.project_name << std::endl;
	str << "Team Leader: ";
	str << ref; // така извикваме версията на << която работи с обект Employee
	str << "Team: " << std::endl;
	for (int i = 0; i <obj.team.size(); i++)
	{
		str << obj.team[i];
	}
	str << std::endl;

	return str;
}
