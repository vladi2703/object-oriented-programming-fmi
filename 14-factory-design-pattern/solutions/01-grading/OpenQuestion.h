#include "Question.h"

#ifndef OPENQUESTION_H_
#define OPENQUESTION_H_

class OpenQuestion
{
    std::string student_answer;

public:
    OpenQuestion(const std::string& question1, double points1);

    void ask();
    int grade();
    void print();
};

#endif