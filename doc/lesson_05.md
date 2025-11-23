# Занятие 5: Массивы и строки

**Длительность:** 2 пары (4 академических часа)

## Цели занятия
- Изучить работу с массивами
- Понять разницу между массивами и указателями
- Освоить работу со строками C-style
- Познакомиться с std::string

---

## Пара 1: Массивы

### Теоретический материал

### Массивы

#### Объявление и инициализация
```cpp
int arr[5];                    // Объявление массива из 5 элементов
int arr2[5] = {1, 2, 3, 4, 5}; // Инициализация
int arr3[] = {1, 2, 3};        // Автоматический размер
```

#### Доступ к элементам
```cpp
arr[0] = 10;        // Первый элемент
int x = arr[2];     // Третий элемент
int size = sizeof(arr) / sizeof(arr[0]);  // Размер массива
```

#### Передача массива в функцию
```cpp
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

// Или с указателем
void printArray(int* arr, int size) {
    // ...
}
```

### Строки C-style

```cpp
char str1[] = "Hello";           // Массив символов
char str2[10] = "World";         // С фиксированным размером
const char* str3 = "C++";        // Указатель на строковый литерал

// Функции для работы со строками
#include <cstring>
strlen(str1);                     // Длина строки
strcpy(dest, src);                // Копирование
strcat(dest, src);                // Конкатенация
strcmp(str1, str2);               // Сравнение
```

### std::string (C++)

```cpp
#include <string>

std::string str = "Hello";
str += " World";                  // Конкатенация
int len = str.length();           // Длина
str[0] = 'h';                     // Доступ к символам
std::string substr = str.substr(0, 5);  // Подстрока
```

---

## Пара 2: Строки

### Теоретический материал

#### Строки C-style (продолжение)

```cpp
#include <cstring>

char str1[20] = "Hello";
char str2[20] = "World";

// Сравнение
if (strcmp(str1, str2) == 0) {
    // Строки равны
} else if (strcmp(str1, str2) < 0) {
    // str1 меньше str2
}

// Безопасное копирование
char dest[20];
strncpy(dest, str1, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';  // Гарантируем нулевой терминатор

// Безопасная конкатенация
strncat(dest, str2, sizeof(dest) - strlen(dest) - 1);
```

#### std::string (C++)

```cpp
#include <string>
#include <iostream>

std::string str = "Hello";
str += " World";                    // Конкатенация
str.append("!");                    // Добавление в конец

// Размер и емкость
int len = str.length();              // или str.size()
int cap = str.capacity();

// Доступ к символам
char c = str[0];                     // Без проверки границ
char c2 = str.at(0);                 // С проверкой границ

// Поиск
size_t pos = str.find("World");       // Поиск подстроки
if (pos != std::string::npos) {
    std::cout << "Найдено на позиции " << pos << std::endl;
}

// Подстрока
std::string substr = str.substr(0, 5);  // "Hello"

// Замена
str.replace(0, 5, "Hi");            // Замена "Hello" на "Hi"

// Вставка
str.insert(2, "XX");                 // Вставка в позицию 2

// Удаление
str.erase(0, 2);                     // Удаление первых 2 символов
```

#### Преобразование между C-string и std::string

```cpp
// Из C-string в std::string
const char* cstr = "Hello";
std::string str(cstr);

// Из std::string в C-string
const char* ptr = str.c_str();       // Не изменяйте строку после этого!
char* data = str.data();             // C++17

// Копирование в буфер
char buffer[100];
str.copy(buffer, sizeof(buffer) - 1);
buffer[sizeof(buffer) - 1] = '\0';
```

#### Строковые потоки

```cpp
#include <sstream>

// Преобразование числа в строку
int num = 42;
std::stringstream ss;
ss << num;
std::string str = ss.str();

// Или в C++11
std::string str2 = std::to_string(num);

// Преобразование строки в число
std::string numStr = "123";
int value = std::stoi(numStr);       // string to int
double d = std::stod("3.14");        // string to double
```

### Практические примеры

```cpp
// Функция для работы с C-string
void processString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';  // Преобразование в верхний регистр
        }
    }
}

// Функция для работы с std::string
std::string reverseString(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}
```

### Домашнее задание
- Реализовать функцию поиска максимума в массиве
- Написать функцию для инверсии массива
- Создать программу для работы со строками (подсчет слов, поиск подстроки)
- Реализовать функции для преобразования между различными форматами строк
- Написать программу для работы с многострочным текстом

### Дополнительные материалы
- Многомерные массивы
- Динамические массивы
- Строковые потоки (stringstream)
- Регулярные выражения (regex, C++11)

