#include "Employee.h"

Employee::Employee(const std::string& name1, double salary1):
	name(name1), salary(salary1)
{

}

double Employee::getSalary()
{
	return salary;
}

std::ostream& operator<<(std::ostream& str, const Employee& obj)
{
	str << "Name: " << obj.name << ", Salary: " << obj.salary << std::endl;
	return str;
}
