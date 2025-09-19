#include <iostream>

int main() {
    int a = 42;
    int *b = &a;
    *b=10;
    std::cout << a << '\n';
    std::cout << *b << '\n';
    return 0;
}
