# Полиморифзъм. Виртуални функции. Абстрактни класове

## Полиморфизъм

Полиморфизъмът е свойство на езика, което позволява да се използват обекти от различни типове по един и същи начин.

### Виртуални методи

Ключовата дума `virtual` - виртуален метод, е метод, който МОЖЕ да бъде предефиниран в класовете наследници.

Пример:
  
```cpp
class Animal {
public:
    virtual void makeSound() {
        std::cout << "I am an animal" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Bau!" << std::endl;
    }
};
class Mouse : public Animal {
public:
    void makeSound() override {
        std::cout << "Цър цър" << std::endl;
    }
};

class Checheneca : public Animal {
public:
    void makeSound() override {
        std::cout << "Кое е това животно?" << std::endl;
    }
};

int main(){
    Animal generic = Animal();
    generic.makeSound();

    Dog dog = Dog();
    dog.makeSound();
    
    Animal mouse = Mouse(); // what will happen here?
    mouse.makeSound(); // whats the sound?

    Animal* jivotno = Checheneca();
    jivotno->makeSound(); // whats the sound now?


    Animal** animals = new Animal*[4];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Mouse();
    animals[3] = new Checheneca();

    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
        delete animals[i];
    }
    delete[] animals;
    
}
```

Разликата между `Animal mouse = Mouse();` и `Animal* mouse = new Mouse();` се крие в начина, по който обектите се създават и съхраняват в паметта.

В първия случай `Animal mouse = Mouse();` се създава обект `Mouse` и след това неявно се преобразува в обект `Animal`, който след това се копира в променливата `mouse`. Това се нарича ??нарязване на обект?? (object slicing), защото се запазва само частта `Animal` от обекта `Mouse`, а останалата част се отрязва. Следователно, когато се извика `mouse.makeSound()`, функцията `Animal::makeSound` ще бъде изпълнена вместо функцията `Mouse::makeSound`, тъй като променливата `mouse` е от тип `Animal`.

Във втория случай, `Animal* mouse = new Mouse();`, в хийпа се създава обект `Mouse` и указател към този обект се съхранява в променлива от тип `Animal*`. Указателят е от правилния тип за достъп до обекта `Mouse`, така че когато се извика `mouse->makeSound()`, функцията `Mouse::makeSound` ще бъде изпълнена.

Следователно, ако искате да сте сигурни, че се извиква правилната функция за производен клас, трябва да използвате указател или референция към класа наследник, вместо да го копирате в обект от типа на базовия клас.

### Типове свързване

Съществуват два типа свързване на функции - статично и динамично свързване.

| Compile time polymorphism | Runtime polymorphism |
| --- | --- |
| Също се нарича **статично свързване** | Също се нарича **динамично свързване** |
| Чрез *function overloading* и *operator overloading* | Чрез *method overriding* |
| Осъществява се по време на **компилация** | Осъществява се по време на **изпълнение** |
| **Няма** отражение въхру производителността | **Има** отражение върху производителността |

Разлика между function overloading и method overriding:

```cpp
class Animal {
public:
    virtual void makeSound() {
        std::cout << "I am an animal" << std::endl;
    }
};

class Dog : public Animal {
public: 
    void makeSound() override { // function overriding
        std::cout << "Bau!" << std::endl;
    }
};
```

```cpp
int sum(int a, int b) {
    return a + b;
}
int sum(int a, int b, int c) { // function overloading
    return a + b + c;
}

int sum(std::vector<int> numbers) {
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }
    return sum;
}
```

- **overloading** – позволява да съществува функция с едно и също име, но различен брой и/или тип параметри.
- **overriding** – предефиниране на метод в производен клас. Има същата сигнатура като метода на базовия клас - същия тип на връщане и параметри.

Правила за виртуалните методи:

  1. Виртуалните функции **не** могат да бъдат статични.
  2. Прототипът на виртуален метод трябва да бъде един и същи в базовия и наследения клас.
  3. Виртуалните методи се дефинират в базовия клас. В производните класове те се предефинират, **ако
   е нужно**. Ако метод не е предефиниран в класа-наследник се използва базовата му дефиниция.  
  4. Клас може да има виртуален деструктор, но **не и виртуален конструктор**.

### Абстрактни класове/Виртуални класове/Интерфейси

Абстрактен клас е клас, който има поне една чисто виртуална функция. Чисто виртуална функция е функция, която няма имплементация. Такъв клас **не може** да бъде инстанциран, т.е. не може да се създаде обект от него. Такъв клас се използва само за наследяване.

:bangbang: Класът наследник ТРЯБВА да предефинира чисто виртуалните функции, иначе той също става абстрактен клас.

```cpp
class Printable {
public:
    virtual void print() const = 0;
};

class Person : public Printable {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    void print() const override {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

class Book : public Printable {
public:
    Book(const std::string& title, const std::string& author) : title(title), author(author) {}

    void print() const override {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }

private:
    std::string title;
    std::string author;
};

void printObject(const Printable& obj) { //obj ТРЯБВА да бъде референция, защото иначе ще се извика копиращия конструктор на Printable
    obj.print();
}

int main() {
    Person person("Alice", 30);
    Book book("The Great Gatsby", "F. Scott Fitzgerald");

    printObject(person); // prints "Name: Alice, Age: 30"
    printObject(book); // prints "Title: The Great Gatsby, Author: F. Scott Fitzgerald"

    return 0;
}
```

### :exclamation: Виртуален деструктор?

```cpp
class Animal {
public:
     ~Animal() {
        std::cout << "Animal destructor" << std::endl;
    }

    virtual void makeSound() const = 0;
};

class Dog : public Animal {
public:
    ~Dog() {
        std::cout << "Dog destructor" << std::endl;
    }
    void makeSound() const override {
        std::cout << "Bau!" << std::endl;
    }
};

int main() {
    Animal* animalPtr = new Dog();
    animalPtr->makeSound();

    delete animalPtr; // will print only "Animal destructor"
    return 0;
}
```

При полиморфна архитектура деструкторът на базовия клас трябва да е виртуален, за да се извика правилния деструктор при изтриване на обект, който е инстанция на производен клас.
Ако деструкторът на базовия клас не е виртуален, при изтриване на обект от производен клас ще се извика само деструкторът на базовия клас, което може да доведе до memory leak.

:exclamation: Извод: правете деструктора на базовия клас виртуален. Дори той самият да е празен, важно е да бъде виртуален.

## Задача 1

Позволено е ползването на std::string и std::vector
Имате няколко вида форми, които трябва да реализирате като класове:

- `Triangle` - има дължини на трите му страни
- `Circle` - има дължина на радиуса
- `Square` - има дължина на страната

Тези класове трябва да наследят абстрактен клас `Shape`, който има

- член-данна label от тип std::string - идентификатор на формата (например "Triangle A")
- член-функция getLabel()
- чисто виртуални член-функции print(), copy() и getPerimeter(). print() да отпечатва в конзолата пиктограма на обекта.
copy() да връща указател(Shape*) към новосъздадено копие от наследен тип на обекта-this в динамичната памет.

Приемете че PI = 3.14

Освен това трябва да реализирате клас `ShapeContainer`, който съхранява форми от всякакви видове в реда, в който са били добавени от потребителя.
Този клас има функции за:

- добавяне на обект
- извеждане на информацията за периметрите на всички обекти във вида "идентификатор - периметър". Пример:  
`Triangle A - 12`
- отпечатване на обектите в контейнера чрез пиктограми в реда, в който са били добавени.
  Не е нужно пиктограмите да отговарят на точните форми и размери на обектите. Пример:

```

 /\
/__\
 ___
|   |
|___|
 /\
/__\
   _
 /   \
|     |
 \ _ /
```

## Задача 2

Работите за компанията `Spark`. След като таксиметровите шофьори разбраха, че когато чупят колите получават съответните глоби, решиха да съботират приложението. Имате 20 минути да го оправите. Помогнете на компанията да оцелее.
От компанията може да си наемете:

- Джип (SUV)
- Лека кола
- Бус

Всяко превозно средство има следните характеристики:

- уникален номер
- брой места
- максимална скорост
- цена на наем за ден

Джипът от своя страна има:

- булева променлива, която показва дали е 4х4

Леката кола:

- име на марката (низ с произволна дължина)

Бусът:

- цяло число - вместимост на багажника

Създайте клас `Spark` който съдържа динамичен масив от превозни средства. Класът трябва да има следните функционалности:

- добавяне на ново превозно средство
- връщане на цена на превозно средство по индекс в масива
