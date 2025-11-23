# Занятие 8: Динамическая память

**Длительность:** 2 пары (4 академических часа)

## Цели занятия
- Изучить работу с динамической памятью
- Понять операторы new и delete
- Освоить работу с динамическими массивами
- Изучить утечки памяти и как их избегать

---

## Пара 1: Операторы new и delete

### Теоретический материал

### Операторы new и delete

#### Выделение памяти для одного объекта
```cpp
int* ptr = new int;        // Выделение памяти
*ptr = 42;                 // Использование
delete ptr;                // Освобождение памяти
ptr = nullptr;             // Хорошая практика
```

#### Выделение памяти для массива
```cpp
int* arr = new int[10];    // Массив из 10 элементов
// Использование массива
delete[] arr;              // Освобождение памяти для массива
arr = nullptr;
```

### Инициализация при выделении памяти
```cpp
int* ptr = new int(42);           // Инициализация значением
int* arr = new int[5]{1,2,3,4,5}; // Инициализация массива (C++11)
```

### Проблемы с динамической памятью

#### Утечка памяти
```cpp
void leak() {
    int* ptr = new int[100];
    // Забыли вызвать delete[]
    // Память утекла!
}
```

#### Двойное освобождение
```cpp
int* ptr = new int;
delete ptr;
delete ptr;  // ОШИБКА! Двойное освобождение
```

#### Использование после освобождения
```cpp
int* ptr = new int;
delete ptr;
*ptr = 10;  // ОШИБКА! Использование после освобождения
```

### Умные указатели (C++11, краткое введение)
```cpp
#include <memory>

std::unique_ptr<int> ptr = std::make_unique<int>(42);
// Память автоматически освободится при выходе из области видимости
```

---

## Пара 2: Работа с динамическими массивами и отладка

### Теоретический материал

#### Динамические массивы

```cpp
// Выделение памяти для массива
int size = 10;
int* arr = new int[size];

// Инициализация
int* arr2 = new int[size]{1, 2, 3};  // Остальные элементы = 0

// Использование
for (int i = 0; i < size; ++i) {
    arr[i] = i * 2;
}

// Освобождение памяти
delete[] arr;
arr = nullptr;  // Хорошая практика
```

#### Изменение размера массива

```cpp
// Создание нового массива большего размера
int* oldArr = new int[5];
// ... заполнение oldArr ...

int newSize = 10;
int* newArr = new int[newSize];

// Копирование данных
for (int i = 0; i < 5; ++i) {
    newArr[i] = oldArr[i];
}

// Освобождение старого массива
delete[] oldArr;
oldArr = newArr;
```

#### Двумерные динамические массивы

```cpp
int rows = 3, cols = 4;

// Способ 1: Массив указателей
int** matrix = new int*[rows];
for (int i = 0; i < rows; ++i) {
    matrix[i] = new int[cols];
}

// Использование
matrix[0][0] = 10;

// Освобождение
for (int i = 0; i < rows; ++i) {
    delete[] matrix[i];
}
delete[] matrix;

// Способ 2: Один массив (более эффективно)
int* matrix2 = new int[rows * cols];
// Доступ: matrix2[i * cols + j] = value;
delete[] matrix2;
```

#### Проверка выделения памяти

```cpp
int* ptr = new (std::nothrow) int[1000];
if (ptr == nullptr) {
    std::cerr << "Не удалось выделить память!" << std::endl;
    return;
}
// Использование ptr
delete[] ptr;
```

#### Отладка утечек памяти

```cpp
// Использование valgrind
// valgrind --leak-check=full ./program

// Использование AddressSanitizer (компиляция)
// g++ -fsanitize=address -g program.cpp
```

### Практические примеры

```cpp
// Функция создания динамического массива
int* createArray(int size) {
    int* arr = new int[size];
    return arr;
}

// Функция удаления массива
void deleteArray(int* arr) {
    delete[] arr;
}

// Класс для управления динамическим массивом
class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int s) : size(s) {
        data = new int[size];
    }

    ~DynamicArray() {
        delete[] data;
    }

    // Запрет копирования (пока)
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;
};
```

### Домашнее задание
- Реализовать динамический массив с функциями добавления/удаления элементов
- Написать программу, которая работает с динамической памятью без утечек
- Изучить инструменты для обнаружения утечек памяти (valgrind, AddressSanitizer)
- Создать класс для управления динамическим массивом
- Реализовать функции для работы с динамическими матрицами

### Дополнительные материалы
- Умные указатели (unique_ptr, shared_ptr, weak_ptr)
- RAII (Resource Acquisition Is Initialization)
- Инструменты для отладки памяти
- Placement new
- Аллокаторы памяти

