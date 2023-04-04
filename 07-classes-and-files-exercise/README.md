# Класове и работа с файлове - упражнение

## Оператори за входи и изход

Както можем да предефинираме аритметичните оператори, така `C++` ни предоставя възможност да предефинираме и операторите за вход `>>` и изход `<<`. Както всеки от операторите, които сме разгледали, така и тези оператори са функции, които имат тип на връщане и приемат обект. Синтаксиса на тези оператори е следният:

```cpp
std::ostream& operator<<(std::ostream& out, const Student& student);
std::istream& operator>>(std::istream& in, Student& student);
```

```cpp
Student pesho;
// Вариант 1
std::cout << pesho.name << pesho.age << pesho.grade;
// Вариант 2
std::cout << pesho;
// Вариант 3
operator<<(std::cout, pesho);
```

Операторите за вход и изход са инфиксни оператори. Това означава, че са оператори, които се използват между два операнда. В случая операторите за вход и изход са оператори, които се използват между поток и обект, като първия аргумент (потокът) стои от ляво, а вторият (обектът) - отдясно. 

Причината операторите да връщат референция към поток е, че искаме да можем да ги използваме като верига. Например:

```cpp
std::cout << "Hello" << " " << "World" << std::endl;
```

Често операторите за вход и изход се дефинират като приятелски функции. Защо?

## Задача 1 - :nerd_face: :zap:

Днес леко ще изкривим представата си за училището Hogwarts и ще създадем клас училище, в който учениците от различните `Домове` ще могат да си организират битки.\
За целта ще създадем клас `Power`, който ще съдържа информация за магическа сила. Той ще има следните полета:

* `name` - име на магическата сила
* `damage` - сила на магическата сила

Предефинирайте оператор `<` за класа `Power`. Той трябва да сравнява магическите сили по силата им.

Клас `Student` ще представлява ученик от училището. Той ще има следните полета:

* `name` - име на ученика
* `house` - дом, в който е ученика
* `power` - магическа сила, която използва ученика (константен указател към обект от клас `Power`)
* `health` - здраве на ученика

Клас `School` ще представлява училището. Той ще има следните полета:

* `students` - масив от ученици. За разлика от Hogwarts училището ни има **неограничен брой места**. 
  
Класът `School` ще има следните методи:

* `addStudent` - добавя ученик към училището
* `assignHouse` - присвоява дом на ученик
* `givePower` - дава магическа сила на ученик

Предефинирайте оператор `<<` за класа `School`. Той трябва да извежда информация за всички ученици в училището.

Напишете функция за битка между два от домовете. Тя трябва да приема имена на домовете. Битката трябва се проведе по следния начин:
Докато някой от домовете не остане без ученици:

1. Избират се по един ученик от всеки дом
2. Един по един, двамата ученици използват магическата си сила, като взимат `damage` от здравето на опонента си
3. Когато един ученик загуби, той се премахва от училището. Училището трябва да излъчи нов ученик, който ще заеме неговото място на арената

Моля за да имаме яснота как протича битката - вижте примерния изход.

```text
Fight between Harry Potter (Gryffindor) and Draco Malfoy (Slytherin)
Harry Potter [100] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Draco Malfoy [90]  (Slytherin) attacks Harry Potter (Gryffindor) with Cruciatus for 20 damage
Harry Potter [80] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Draco Malfoy [80]  (Slytherin) attacks Harry Potter (Gryffindor) with Cruciatus for 20 damage
Harry Potter [60] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Draco Malfoy [70]  (Slytherin) attacks Harry Potter (Gryffindor) with Cruciatus for 20 damage
Harry Potter [40] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Draco Malfoy [60]  (Slytherin) attacks Harry Potter (Gryffindor) with Cruciatus for 20 damage
Harry Potter [20] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Draco Malfoy [50]  (Slytherin) attacks Harry Potter (Gryffindor) with Cruciatus for 20 damage
Draco Malfoy (Slytherin) wins!
Fight between Ron Weasley (Gryffindor) and Draco Malfoy (Slytherin)
Ron Weasley [100] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Draco Malfoy [40]  (Slytherin) attacks Ron Weasley (Gryffindor) with Cruciatus for 20 damage
Ron Weasley [80] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Draco Malfoy [30]  (Slytherin) attacks Ron Weasley (Gryffindor) with Cruciatus for 20 damage
Ron Weasley [60] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Draco Malfoy [20]  (Slytherin) attacks Ron Weasley (Gryffindor) with Cruciatus for 20 damage
Ron Weasley [40] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Draco Malfoy [10]  (Slytherin) attacks Ron Weasley (Gryffindor) with Cruciatus for 20 damage
Ron Weasley [20] (Gryffindor) attacks Draco Malfoy (Slytherin) with Expelliarmus for 10 damage
Ron Weasley (Gryffindor) wins!
Gryffindor wins!
```

Може да погледнете хедърите на класовете в [директорията](./HogwartsBattles/). Помислете кои методи може да бъдат константни. Можете свободно да дефинирате допълнителни методи.

## Задача

Напишете следните класове:

Клас **Account**, който има:  

private:

* `std::string` owner
* `size_t` id  

public:

* `double` balance

Създайте конструктор, който по подадени аргументи задава стоности на owner и id, а на balance задава 0.  
Класът **не трябва** да има конструктор по подразбиране.
Създайте подходящи get методи.

Клас **Bank**, който има:

* масив от акаунтите(указатели към тях)
* други променливи нужни за реализацията на класа
* `size_t currentId`; *(при създаване на банката се дава начална стойност на `currentId` и после се увеличава с 1 при всяко добавяне на нов акаунт)*
* голяма четворка

Класът трябва да позволява следните операции, като при невалидни аргументи, трябва да се хвърля грешка:

* Отваряне на акаунт по дадено име, `id`-то се генерира от банката
* Транзакция: Теглене на пари от акаунт по дадено `id` и сума *(за целта трябва да има достатчъно пари в сметката)*
* Транзакция: Добавяне на пари в акаунт по дадено `id` и сума
* Транзакция: Изпращане на пари от един акаунт на друг по дадени `id`-та и сума *(за целта и двата акаунта трябва да съществуват и изпращащия да има достатъчно пари в сметката)*
* Отпечатване в конзолата: Да се изведат всички акаунти по азбучен ред на имената на собствениците, съответно и всички данни в тях.
