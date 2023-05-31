#include "Question.h"

#ifndef OPENQUESTION_H_
#define OPENQUESTION_H_

class OpenQuestion : public Question
{
    std::string student_answer;

public:
    OpenQuestion(const std::string& question1, double points1);

    void ask();
    double grade();
    void print();
};

#endif