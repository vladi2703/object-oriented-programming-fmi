#include <vector>
#include "QuestionFactory.h"

class Exam
{
    bool is_graded;
    double points;
	std::vector<Question*> questions;

public:
    void addFromFactory(const QuestionFactory&);
    void answer();
    void grade();
    double getPoints();
    void printQuestions();
    void removeQuestion(int index);

    Exam();
	Exam(const Exam&) = delete;
	Exam& operator=(const Exam&) = delete;
	~Exam();
};
