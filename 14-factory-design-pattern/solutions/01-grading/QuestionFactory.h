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
	тук се четат данни от клавиатурата необходими за създаването на въпрос
	*/
};

#endif