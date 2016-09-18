/*
Задача powerOfX

Условие задачи
Считать с клавиатуры целое основание и целый неотрицательный показатель. Вывести
через пробел степени числа основания от нулевой до заданной.

Пример ввода
2 3
Пример вывода
1 2 4 8

code works
*/

#include <stdio.h>

int main() {
    unsigned int base;
    unsigned int power;
    unsigned int i = 1;
    
    scanf("%d %d", &base, &power);
    
    for ( ; power > 0; power-- ) {
        printf("%d ", i);
        i *= base;
    }
    printf("%d\n", i);
    
    return 0;
}
