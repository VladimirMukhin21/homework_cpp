# Занятие 10: Структуры и классы

**Длительность:** 2 пары (4 академических часа)

## Цели занятия
- Изучить структуры (struct) и объединения (union)
- Понять перечисления (enum)
- Освоить основы классов и объектов
- Изучить конструкторы и деструкторы

---

## Пара 1: Структуры, объединения и перечисления

### Теоретический материал

### Структуры (struct)

#### Объявление и использование
```cpp
struct Point {
    int x;
    int y;
};

Point p;
p.x = 10;
p.y = 20;

// Инициализация
Point p2 = {5, 15};
Point p3{3, 7};  // Uniform initialization (C++11)
```

#### Структуры с функциями
```cpp
struct Rectangle {
    int width;
    int height;

    int area() {
        return width * height;
    }

    void setSize(int w, int h) {
        width = w;
        height = h;
    }
};

Rectangle rect;
rect.setSize(10, 20);
int a = rect.area();
```

#### Указатели на структуры
```cpp
Point* ptr = &p;
ptr->x = 100;        // Доступ через указатель
(*ptr).y = 200;      // Альтернативный синтаксис
```

### Объединения (union)
```cpp
union Data {
    int i;
    float f;
    char c;
};

Data d;
d.i = 42;
// Теперь можно использовать d.f или d.c
// Но только одно значение актуально в каждый момент
```

### Перечисления (enum)
```cpp
enum Color {
    RED,
    GREEN,
    BLUE
};

Color c = RED;

// Enum class (C++11, типобезопасный)
enum class Status {
    OK,
    ERROR,
    PENDING
};

Status s = Status::OK;
```

### Вложенные структуры
```cpp
struct Address {
    std::string street;
    std::string city;
    int zipCode;
};

struct Person {
    std::string name;
    int age;
    Address address;
};
```

---

## Пара 2: Классы и объекты

### Теоретический материал

#### Классы vs Структуры

В C++ классы и структуры почти идентичны. Разница только в модификаторе доступа по умолчанию:
- `struct` - по умолчанию `public`
- `class` - по умолчанию `private`

#### Базовый класс

```cpp
class Rectangle {
private:
    int width;
    int height;

public:
    // Конструктор
    Rectangle(int w, int h) : width(w), height(h) {}

    // Методы
    int getArea() const {
        return width * height;
    }

    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};
```

#### Конструкторы

```cpp
class Point {
    int x, y;

public:
    // Конструктор по умолчанию
    Point() : x(0), y(0) {}

    // Конструктор с параметрами
    Point(int x, int y) : x(x), y(y) {}

    // Конструктор копирования
    Point(const Point& other) : x(other.x), y(other.y) {}

    // Делегирующий конструктор (C++11)
    Point(int value) : Point(value, value) {}
};
```

#### Деструктор

```cpp
class Resource {
    int* data;
    int size;

public:
    Resource(int s) : size(s) {
        data = new int[size];
    }

    // Деструктор
    ~Resource() {
        delete[] data;
        std::cout << "Ресурс освобожден" << std::endl;
    }
};
```

#### Модификаторы доступа
- `private` - доступ только внутри класса
- `protected` - доступ внутри класса и в наследниках
- `public` - публичный доступ

#### Константные методы
```cpp
class MyClass {
    int value;
public:
    int getValue() const {  // Не изменяет объект
        return value;
    }

    void setValue(int v) {  // Может изменять объект
        value = v;
    }
};
```

#### Инициализация членов класса

```cpp
class Example {
    int a;
    int b;
    const int c;

public:
    // Список инициализации
    Example(int x, int y) : a(x), b(y), c(100) {
        // Тело конструктора
    }
};
```

### Практические примеры

```cpp
// Класс для работы с комплексными числами
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void print() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};
```

### Домашнее задание
- Создать структуру для представления студента с функциями
- Реализовать класс для работы с комплексными числами
- Создать класс `BankAccount` с методами пополнения и снятия
- Использовать перечисления для статусов
- Работать с массивами объектов

### Дополнительные материалы
- Размер структур и выравнивание (alignment)
- Битовые поля
- Анонимные структуры и объединения
- Правило трех (Rule of Three)
- Статические члены класса

