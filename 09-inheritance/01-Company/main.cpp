#include <iostream>
#include <vector>
#include "Manager.h"

int main()
{
	Employee ivan("Ivan", 2000), georgi("Georgi", 2000);
	std::vector<Employee> team1;
	team1.push_back(ivan);
	team1.push_back(georgi);

	TeamLeader dimitar("Dimitar",4000,"App UI",team1);

	Employee petar("Petar", 3000);
	std::vector<Employee> team2;
	team2.push_back(petar);

	TeamLeader stoyan("Stoyan", 4000, "App Backend", team2);

	std::vector<TeamLeader> leaders;
	leaders.push_back(dimitar);
	leaders.push_back(stoyan);

	Manager pavel("Pavel", 10000, leaders);

	std::cout << pavel;

	std::cout << pavel.getExpenses() << std::endl;
}