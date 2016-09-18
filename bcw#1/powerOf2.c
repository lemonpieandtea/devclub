/*
Задача powerOf2

Условие задачи
Считать с клавиатуры целое неотрицательное число. Вывести через пробел степени
числа 2 от нулевой до заданной. Использовать цикл.

Пример ввода
3
Пример вывода
1 2 4 8

code works
*/

#include <stdio.h>

#define BASE 2

int main() {
    unsigned int power;
    unsigned int i = 1;
    
    scanf("%d", &power);
    
    for ( ; power > 0; power-- ) {
        printf("%d ", i);
        i *= BASE;
    }
    printf("%d\n", i);
    
    return 0;
}
