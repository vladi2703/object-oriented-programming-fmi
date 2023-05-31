#include "YesNoQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "OpenQuestion.h"

#ifndef QUESTIONFACTORY_H_
#define QUESTIONFACTORY_H_

class QuestionFactory
{
public:
	Question* createQuestion();
	/*
	 Примерна имплментация в cpp файла:
	
	{
		std::string type;
		std::getline(std::cin, type);
		if (type == "YesNo")
		{
			std::string question,ans;
			double points;
			std::cout << "Write question: \n";
			std::getline(std::cin, question);
			std::cout << "Write correct answer: \n";
			std::getline(std::cin, ans);

			std::cout << "Write points: \n";
			std::cin >> points;

			if (Question::validYesNoAnswer(ans))
				if (ans == Question::YES)
					return new YesNoQuestion(question, points, true);
				else
					return new YesNoQuestion(question, points, false);
			else
				return nullptr;
		}
		else if ....
	*/
};

#endif