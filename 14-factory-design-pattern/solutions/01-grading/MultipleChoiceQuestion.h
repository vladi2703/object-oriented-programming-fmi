#include <vector>
#include "Question.h"

#ifndef MULTIPLECHOICEQUESTION_H_
#define MULTIPLECHOICEQUESTION_H_

class MultipleChoiceQuestion
{
    int n;
    std::vector<bool> correct_is_yes;
    std::vector<std::string> statements;

    std::vector<std::string> student_answers;
    /*
        възможна е и друга архитектура - вместо student_answers да имаме
        int result, което представлява получените точки и
        се изчислява при изпълнението на ask(). След това grade()
        просто връща result
    */

public:
    MultipleChoiceQuestion(const std::string& question1, double points1,
        std::vector<std::string> statements1, std::vector<bool> correct_is_yes);
    /*
        n = std::min( statements1.size(), correct_is_yes.size() )
        statements1.resize(n);
        correct_is_yes.resize(n);
        така се скъсява по-големия вектор

        така правим вектор от n празни низа:
        student_answers.resize(n); - възможно е въпроса да се зададе няколко пъти
        и затова не е удачно да се ползва push_back
    */

    void ask();
    double grade();
    void print();
};

#endif
