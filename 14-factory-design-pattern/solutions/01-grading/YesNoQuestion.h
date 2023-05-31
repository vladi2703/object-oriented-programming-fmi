#include "Question.h"

#ifndef YESNOQUESTION_H_
#define YESNOQUESTION_H_

class YesNoQuestion : public Question
{
    bool correct_is_yes;
    std::string student_answer;


/*
    възможна е и друга архитектура - вместо student_answer да имаме
    int result, което представлява получените точки и 
    се изчислява при изпълнението на ask(). След това grade() 
    просто връща result
*/

public:
    YesNoQuestion(const std::string& question1, double points1, bool correct_is_yes1);

    void ask();
    double grade();
    void print();
};

#endif