/*
Задача base

Условие задачи
Считать с клавиатуры целое неотрицательное число в десятичной системе счисления
и основание новой системы счисления (целое число от 2 до 10).
Вывести в консоль число, записанное в новой системе счисления.
Задача решается без массивов.

Пример ввода
8 3
Пример вывода
22

code works
*/

#include <stdio.h>

int main() {
    int number;
    int base;
    int exponent = 1;
    
    scanf("%d %d", &number, &base);
    
    for ( int i = number; i >= base; i /= base ) {
        exponent *= base;
    }
    
    for ( int digit; exponent != 0; exponent /= base ) {
        digit = number / exponent;
        printf("%d", digit);
        if ( digit != 0 ) {
            number -= exponent * digit;
        }
    }
    printf("\n");
    
    return 0;
}
