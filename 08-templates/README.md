# Шаблони

Шаблонът е механизъм в C++, който ви позволява да дефинирате функции и класове с общи типове. Това означава, че можете да дефинирате функция или клас, без да посочвате конкретен тип, а типът ще бъде определен по време на компилация въз основа на аргумента(ите), предадени на функцията или класа.

## Шаблони на функции

В C++ можете да дефинирате шаблон на функция, като използвате ключовата дума `template`, последвана от списък с параметри на шаблона, затворени в ъглови скоби `< >`. Пример:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

В този шаблон на функция `T` е параметърът на шаблона. Той представлява тип, който ще бъде определен по време на компилация въз основа на аргумента(ите), предадени на функцията. Тялото на функцията използва `T` като тип на аргументите a и b, както и като тип на връщане.

За да използвате този шаблон на функция, можете да я извикате с два аргумента от един и същи тип:

```cpp
int max_int = max(42, 13); // returns 42
double max_double = max(3.14, 2.71); // returns 3.14
```

:bangbang: Ако извикате функцията с два аргумента от различни типове, компилаторът ще генерира грешка:

```cpp
int max_int = max(42, 'a') // грешка: типовете на аргументите не съвпадат
```

:bangbang: Компилаторът няма да извърши имплицитно преобразуване.

При първото извикване се извежда, че T е `int`, а при второто извикване се извежда, че T е `double`. Компилаторът генерира конкретна версия на функцията за всеки използван тип, с цел оптимизация при използването на шаблони.

Можете също така да посочите изрично аргументите на шаблона, като предоставите типа(овете) в ъглови скоби:

```cpp
int max_int = max<int>(42, 13); // returns 42
double max_double = max<double>(3.14, 2.71); // returns 3.14
```

В този случай казвате на компилатора да използва `int` като параметър на шаблона за първото извикване и `double` за второто извикване.

## Шаблони на класове

В C++ можете да дефинирате и шаблони за класове, като използвате ключовата дума `template`, последвана от списък с параметри на шаблона, затворени в ъглови скоби `< >`. Например, ето един прост шаблон на клас, който представлява обща двойка стойности:

```cpp
template <typename T1, typename T2>
class Pair {
public:
    Pair(T1 first, T2 second) : first_(first), second_(second) {}

    T1 first() const { return first_; }
    T2 second() const { return second_; }

private:
    T1 first_;
    T2 second_;
};
```

В този шаблон на класа T1 и T2 са параметрите на шаблона. Те представляват типове, които ще бъдат определени по време на компилация въз основа на аргументите, подадени на конструктора.

За да използвате този шаблон на клас, можете да го инстанцирате с конкретни типове:

```cpp
Pair<int, double> pair(42, 3.14);
std::cout << pair.first() << ", " << pair.second() << std::endl; // prints "42, 3.14"
```

В този пример създаваме екземпляр на `Pair` с `int` като параметър от първи тип и `double` като параметър от втори тип.

Можете също така да използвате аргументи на шаблона по подразбиране, за да предоставите стойности по подразбиране за параметрите на шаблона:

```cpp
template <typename T1, typename T2 = int>
class Pair {
public:
    Pair(T1 first, T2 second) : first_(first), second_(second) {}

    T1 first() const { return first_; }
    T2 second() const { return second_; }
private:
    T1 first_;
    T2 second_;
};
```

В този пример параметърът на шаблона T2 има стойност по подразбиране `int`. Това означава, че ако не посочите стойност за T2 при инстанциране на шаблона, тя ще бъде `int`:

```cpp
Pair<int> pair(42, 314);
std::cout << pair.first() << ", " << pair.second() << std::endl; // prints "42, 314"
```

В този пример създаваме екземпляр на `Pair` с `int` като параметър от първи тип и `int` като параметър от втори тип, тъй като не посочваме стойност за T2.

Няма никакъв проблем да влагаме шаблони:

```cpp
template <typename T1, typename T2>
class Pair {
public:
    Pair(T1 first, T2 second) : first_(first), second_(second) {}

    T1 first() const { return first_; }
    T2 second() const { return second_; }

private:
    T1 first_;
    T2 second_;
};

template <typename T>
class Wrapper {
public:
    Wrapper(T value) : value_(value) {}

    T value() const { return value_; }

private:
    T value_;
};
```

В този пример `Wrapper` е шаблон на клас, който приема един параметър на шаблона. Този параметър на шаблона се използва за дефиниране на типа на член-данната `value_`. Този тип може да бъде друг шаблон на клас, например `Pair`:

```cpp
Wrapper<Pair<int, double>> wrapper(Pair<int, double>(42, 3.14));
std::cout << wrapper.value().first() << ", " << wrapper.value().second() << std::endl; // prints "42, 3.14"
```

## Задачи

### Задача Swap

Напишете шаблонна функция `swap(a,b)`, след извикването ня която a и b имат разменени стойности.

### Задача Set

Напишете шаблонен клас Set, който представлява математичиско множество.(В него не може да има два елемента с еднаква стойност).
Напишете следните методи:  

- голяма четворка
- `add(...)` добавяне на елемент
- `isEmpty()` връща дали множеството е празно
- `print()` отпечатва съдържанието на множеството, всеки елемент на нов ред
- `contains(...)` връща дали множеството съдържа даден елемент
- `operator+(...)` - a+b e ново множество, което e представлява обединението на a и b.
- `operator<(...)` - a<b проверява дали a е подмножество на b.

### Задача Dictionary

В програмирането абстрактната структура данни "речник" представлява съвкупност от наредени двойки (ключ, стойност), заедно с дефинирани операции за достъп до стойностите по ключ. Алтернативно тази структура може да бъде наречена още "карта" (map).

Напишете шаблонен клас Dictionary, който представлява речник. Речникът е с ограничен брой "страници" - 100 (може да съдържа не повече от 100 наредени двойки (ключ, стойност)). Речникът трябва да поддържа следните операции:

- `add(key, value)` - добавя нова двойка (ключ, стойност) в речника. Ако вече има двойка със същия ключ, старата стойност трябва да бъде заменена с новата.
- `remove(key)` - премахва двойката (ключ, стойност) от речника.
- `operator[]` - достъп до стойността по ключ. Ако в речника няма двойка с дадения ключ, трябва да се хвърли изключение.
- `contains(key)` - проверява дали в речника има двойка с дадения ключ.
- `size()` - връща броя на двойките в речника.

:bulb: Би ви било от полза да реализирате помощен клас, помислете какъв.
