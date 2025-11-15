# Занятие 7: Управление потоком выполнения

**Длительность:** 2 пары (4 академических часа)

## Цели занятия
- Изучить условные операторы
- Освоить циклы (for, while, do-while)
- Понять операторы break и continue
- Изучить switch-case

---

## Пара 1: Условные операторы и switch

### Теоретический материал

### Условные операторы

#### if-else
```cpp
if (condition) {
    // код
} else if (another_condition) {
    // код
} else {
    // код
}
```

#### Тернарный оператор
```cpp
int max = (a > b) ? a : b;
```

#### switch-case
```cpp
switch (value) {
    case 1:
        // код
        break;
    case 2:
    case 3:
        // код для 2 и 3
        break;
    default:
        // код по умолчанию
}
```

### Циклы

#### for
```cpp
for (int i = 0; i < 10; ++i) {
    std::cout << i << std::endl;
}

// Range-based for (C++11)
int arr[] = {1, 2, 3, 4, 5};
for (int x : arr) {
    std::cout << x << std::endl;
}
```

#### while
```cpp
while (condition) {
    // код
}
```

#### do-while
```cpp
do {
    // код выполнится хотя бы один раз
} while (condition);
```

### Операторы управления циклом

```cpp
for (int i = 0; i < 10; ++i) {
    if (i == 5) {
        continue;  // Пропустить оставшуюся часть итерации
    }
    if (i == 8) {
        break;     // Выйти из цикла
    }
    std::cout << i << std::endl;
}
```

### Вложенные циклы
```cpp
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        std::cout << i << "," << j << " ";
    }
    std::cout << std::endl;
}
```

---

## Пара 2: Циклы

### Теоретический материал

#### Цикл for (продолжение)

```cpp
// Цикл с несколькими переменными
for (int i = 0, j = 10; i < 10; ++i, --j) {
    std::cout << i << " " << j << std::endl;
}

// Цикл без инициализации
int i = 0;
for (; i < 10; ++i) {
    // ...
}

// Бесконечный цикл
for (;;) {
    // код
    if (condition) break;
}
```

#### Range-based for (C++11)

```cpp
// Для массивов
int arr[] = {1, 2, 3, 4, 5};
for (int x : arr) {
    std::cout << x << " ";
}

// Для std::string
std::string str = "Hello";
for (char c : str) {
    std::cout << c << " ";
}

// С ссылкой (для изменения)
for (int& x : arr) {
    x *= 2;  // Удваиваем каждый элемент
}

// С auto
for (auto& x : arr) {
    std::cout << x << " ";
}
```

#### Вложенные циклы и примеры

```cpp
// Таблица умножения
for (int i = 1; i <= 10; ++i) {
    for (int j = 1; j <= 10; ++j) {
        std::cout << i * j << "\t";
    }
    std::cout << std::endl;
}

// Поиск в двумерном массиве
bool found = false;
for (int i = 0; i < rows && !found; ++i) {
    for (int j = 0; j < cols; ++j) {
        if (matrix[i][j] == target) {
            found = true;
            break;  // Выход из внутреннего цикла
        }
    }
}
```

#### Практические паттерны

```cpp
// Подсчет элементов
int count = 0;
for (int i = 0; i < size; ++i) {
    if (arr[i] > threshold) {
        count++;
    }
}

// Поиск максимума
int max = arr[0];
for (int i = 1; i < size; ++i) {
    if (arr[i] > max) {
        max = arr[i];
    }
}

// Сумма элементов
int sum = 0;
for (int i = 0; i < size; ++i) {
    sum += arr[i];
}
```

### Практические примеры

```cpp
// Меню с использованием switch
int choice;
do {
    std::cout << "1. Опция 1\n2. Опция 2\n3. Выход\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            // Действие 1
            break;
        case 2:
            // Действие 2
            break;
        case 3:
            std::cout << "Выход..." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
    }
} while (choice != 3);
```

### Домашнее задание
- Реализовать различные алгоритмы с использованием циклов (поиск, сортировка, фильтрация)
- Написать программу с вложенными циклами (вывод паттернов, работа с матрицами)
- Использовать switch для создания интерактивного меню
- Создать программу-калькулятор с циклом и меню операций
- Реализовать игру "Угадай число" с использованием циклов

### Дополнительные материалы
- Оптимизация циклов
- Бесконечные циклы и их использование
- Метки и goto (не рекомендуется)
- Идиомы C++ для работы с коллекциями

