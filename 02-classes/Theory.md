# Класове. Член-функции. Модификатори за достъп. Капсулация

Пример за динамичен масив от цели числа:

```c++
struct DynamicArray
{
 int* data;
 size_t used;
 size_t allocated;
};

void initialise(DynamicArray& da)
{
 da.data = nullptr;
 da.used = 0;
 da.allocated = 0;
}
void free(DynamicArray& da)
{
 delete[] da.data;
 da.data = nullptr;
 da.used = 0;
 da.allocated = 0;
}
void allocate(DynamicArray& da, size_t size)
{
 da.data = new int[size];
 da.used = 0;
 da.allocated = size;
}

int& at(DynamicArray& da, size_t index)
{
 assert(index < da.used);
 return da.data[index];
}

int main()
{
 DynamicArray da;
 initialise(da);
 free(da);
}
```

Пример за човек:

```c++
struct Person {
    std::string name;
    int age;
    
};
    void introduce (Person& per, std::string n, int a) {
        per.name = n;
        per.age = a;
    }
    
    
    void createPerson (Person& per) {
        per.name = "Unknown";
        per.age = 0;
    }
    
    void greet(const Person& per) {
        std::cout << "Hi, my name is " << per.name << " and I am " << per.age << " years old." << std::endl;
    }
    
    void go(Person& per) {
        std::cout << "Goodbye, " << per.name << "!" << std::endl;
        per.name = "Unknown";
        per.age = 0;
    }
};
```

Горният програмен фрагмент е напълно валиден.  
Но всички написани функции се отнасят за структурата DynamicArray/Person. Не можем ли да ги "групираме" по някакъв начин?  

## Член-функции

- Функции, които **не съществуват глобално**.
- **Работят с член-данните на инстанцията/обекта** от дадена структура/клас.
- **Извикват се с инстанция/обект** на структурата/класа.
- Компилаторът преобразува всяка член-функция на дадена структура/клас в обикновена функция с уникално име и един допълнителен параметър –**указател към инстанцията/обекта**.

**Константни член-функции**:

- **Не променят член-данните** на структурата/класа.
- Обозначават се чрез записване на ключовата дума **const**  в декларацията и в края на заглавието в дефиницията им.
- Могат да се извикват от **константни обекти**.

```c++
class DynamicArray
{
private:
 int* data;
 size_t used;
 size_t allocated;

public:
 void initialise() // inline function
 {
  data = nullptr;
  used = 0;
  allocated = 0;
 }
 void free()
 {
  delete[] data;
  data = nullptr;
  used = 0;
  allocated = 0;
 }
 void allocate(size_t size)
 {
  data = new int[size];
  used = 0;
  allocated = size;
 }

 int& at(size_t index)
 {
  assert(index < used);
  return data[index];
 }
};

int main()
{
 DynamicArray da;
 da.initialise();
 da.allocate(100);
 da.at(5) = 22;
}
```

```c++
struct Person {
    // Properties
    std::string name;
    int age;
    
    void introduce(std::string n, int a) {
        name = n;
        age = a;
    }
    
    void createPerson() {
        name = "Unknown";
        age = 0;
    }
    
    void greet() {
        std::cout << "Hi, my name is " << this->name << " and I am " << this->age << " years old." << std::endl;
    }
    
    // Destructor
    void go() {
        std::cout << "Goodbye, " << this->name << "!" << std::endl;
        this->name = "Unknown";
        this->age = 0;
    }
};

```

Горните два фрагмента са еквивалентни с тези по-горе. Разликата е, че функциите са член-функции на класа. Това означава че извикването им изглежда по следния начин:  

```c++
Person p;
p.introduce("Pesho", 20);
```

Вместо:  

```c++
Person p;
introduce(p, "Pesho", 20);
```

Всяка член-функция, скрито от нас, получава като аргумент специална променлива (**this**) - **пойнтър към текущия обект, с който функцията работи**.  
Можем да си мислим, че нещата изглеждат така:  
(Долният програмен фрагмент **няма да се компилира**! Той е за нашата интуиция !!)  

```c++
{
 // ...
 void initialise(DynamicArray* this)
 {
  this->data = nullptr;
  this->used = 0;
  this->allocated = 0;
 }
 // ...
};
 
int main()
{
 DynamicArray da;
 DynamicArray::initialise(&da);
 // ...
}
```

Сега, искаме "външният свят" да **няма достъп до всички член-данни и методи на даден клас**. Това е така, защото тяхната промяна може да доведе до неочаквано поведение на нашата програма. Как можем да го постигнем?  

## Капсулация (encapsulation) - първи принцип на Обектно-ориентираното програмиране

|Модификатор за достъп|Предназначение|  
|--|--|  
|private|Атрибутите, попадащи в обхвата на този модификатор, са вътрешни за съответния клас (не могат да се използват от "външния свят").|  
|protected|Като private + съответните атрибути могат да се използват и от наследниците на класа.|  
|public|Атрибутите, попадащи в обхвата на този модификатор, са видими и за "външния свят").|  

:bangbang: **Разлика между структура и клас**  
По подразбиране всички член данни и методи **на структурата са public-елементи**, а тези **на класа - private-елементи**.  

Капсулирането е основен принцип на обектно-ориентираното програмиране (ООП).
С няколко думи:
Трябва да се **избягва** промяната на **вътрешните данни** на класа от "външния свят". Външния свят трябва да има достъп до възможно най-малко данни и методи на класа.

## Accessors and mutators (getters and setters)

**Get-ъри** - функции, които използваме за **достъп** до "скрити" данни (попадащи в обхвата на модификатора private (protected)).  
**Set-ъри** - функции, които използваме за **промяна** на "скрити" данни. В тях задължително правим валидация на подадените данни (ако такава е необходима)!  

*Пример:*  

```c++
struct Student
{
private:
    size_t grade;
    size_t age;

public:
    size_t getGrade() const
    {
        return grade;
    }
    size_t getAge() const
    {
        return age;
    }

    void setGrade(size_t grade)
    {
        assert(grade <= 6);
        this->grade = grade;
    }
    void setAge(size_t age)
    {
        this->age = age;
    }
};
```

## Абстракция (abstraction) - втори принцип на Обектно-ориентираното програмиране

Пример за **лоша абстракция**:

```c++
struct Triangle
{
 int x1;
 int y1;
 
 int x2;
 int y2;
 int x3;
 int y3;
};
int getPer(const Triangle& t)
{
 return
  sqrt( (t.x1-t.x2)*(t.x1-t.x2) + (t.y1-t.y2)*(t.y1-t.y2) + 
  sqrt( (t.x2-t.x3)*(t.x2-t.x3) + (t.y2-t.y3)*(t.y2-t.y3) + 
  sqrt( (t.x3-t.x1)*(t.x3-t.x1) + (t.y3-t.y1)*(t.y3-t.y1); 
}
 ```

 Пример за **по-добра абстракция**:

 ```c++
struct Point
{
 int x;
 int y
 double getDistTo(const Point& other)
 {
  return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
 }
};
struct Triangle
{
 Point p1;
 Point p2;
 Point p3;
};
int getPer(const Triangle& t)
{
 return t.p1.getDistTo(t.p2) + t.p2.getDistTo(t.p3) + t.p3.getDistTo(t.p1);
}
 ```
