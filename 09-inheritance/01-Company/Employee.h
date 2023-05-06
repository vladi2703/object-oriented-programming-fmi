#include <string>
#include <vector>
#include <iostream>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
	std::string name;
	double salary;

public:
	Employee(const std::string& name, double salary);
	double getSalary();

	friend std::ostream& operator<<(std::ostream& str, const Employee& obj);
};

#endif