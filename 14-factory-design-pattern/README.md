# Упражнение и шаблон за дизайн - Фабрика

## [Factory design pattern](https://refactoring.guru/design-patterns/factory-method)

## Задача Оценяване

За задачата са позволени std::vector и std::string

### Да се реализира абстрактен базов клас Question, който описва следните методи върху въпрос от тест

* `ask`, който извежда въпроса на конзолата и очаква студента да въведе негов отговор отново през конзолата;
* `grade`, който оценява въпроса и връща броя точки.
* `print`, просто извежда въпроса без да очаква въвеждане на отговор.

Класа да съдържа и следните статични полета и методи:

* `bool validYesNoAnswer(const std::string& ans)` връща дали ans е един от низовете "yes" или "no"
* `bool correctYesNoAnswer(const std::string& ans, bool correct_is_yes)` Връща true точно когато `(correct_is_yes == true && ans == YES) || (correct_is_yes == false && ans == NO)`
* `const std::string YES = "yes"`
* `const std::string NO = "no"`

### Да се реализират следните видове въпроси

* `YesNoQuestion`, който описва въпрос с два възможни отговора: yes или no.
Конструктора приема текст на въпроса, точки и верен отговор.  
Въпросът дава 0 т. при грешен и пълен брой точки при верен отговор.  
При задаване на въпроса студента трябва да отговори "yes" или "no" с малки букви.
* `MultipleChoiceQuestion`, който представялва въпрос и няколко твърдения номерирани от 1 до n, от които някои са верни.  
Конструктора приема текст на въпроса, точки x, вектор с твърденията и булев вектор отбелязващ дали са верни или не.
Ако твърденията са повече от размера на булевия вектор, допънителните твърдения да се игнорират.
Ако булевия вектор е по-голям от броя на твърденията, допълните булеви стойности да се игнорират. (Ползвайте `v.resize( необходимия размер )` )  
Всеки правилно посочен отговор добавя (x / брой верни) точки, а всеки погрешно посочен отговор отнема (x / брой грешни) точки.  
При задаване на въпроса се отпечатват текста, точките и твърденията, след това се отпечатват числата от 1 до n всяко на нов ред и след всяко се
изчаква студента да въведе "yes" или "no".
* `OpenQuestion`, който описва въпрос със свободен текст. При конструиране се задават текст и брой точки.  
При задаване на въпроса се извеждат тескта и точките и се очаква студента да въведе свободен текст.  
При оценяване се извеждат въпроса и отговора на студента и проверяващия въвежда оценка в проценти. Ако отговор не е даден, въпросът автоматично се оценява с 0т.

### Да се реализира клас QuestionFactory, който има само един метод и (за да не усложняваме задачата) няма член-данни

* `Question* createQuestion()`- създава въпрос в динамичната памет и го връща, като данните за него прочита от стандартния вход.
Първо се прочита низ "YesNo" "MultipleChoice" или "Open" за да се определи какъв въпрос да се построи. Ако е въведено нещо друго, метода връща `nullptr`.
След това се прочитат данните необходими за конструиране на въпроса. При невалидни данни да се връща `nullptr`

### Да се реализира клас Exam, представящ тест с въпроси от всякакъв вид. Да се реализират функциите

* `void addFromFactory(const QuestionFactory&)` приема фабрика за въпроси и чрез нея създава въпрос и го добавя към изпита като последен въпрос.
* `answer`, която задава всички въпроси подред и събира отговорите им;
* `grade`, която оценява теста и запазва броя събрани точки в член-данна.
* `getPoints` връща събраните точки. Ако теста не е оценен още, хвърля грешка.  
* `printQuestions` отпечтва въпросите с номерата им (приемаме, че номераацията започва от 1).
* `removeQuestion(int index)` Изтрива въпроса с номер index. Ако такъв няма, хвърля грешка. (ползвайте `v.remove(v.begin() + index)`и помислете за динамичната памет)
  
Да се забрани копиране или присвояване на обекти от класа Exam