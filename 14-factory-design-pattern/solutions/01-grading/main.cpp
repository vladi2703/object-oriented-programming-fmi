#include <iostream>
#include "Exam.h"

int main()
{
	Exam exam;
	QuestionFactory factory;

	exam.addFromFactory(factory);
	exam.addFromFactory(factory);
	exam.addFromFactory(factory);
	exam.addFromFactory(factory);

	exam.answer();
	exam.grade();
	std::cout << exam.getPoints() << std::endl;
}