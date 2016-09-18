/*
Задача base2

Условие задачи
Считать с клавиатуры целое число в десятичной системе счисления и основание
новой системы счисления (целое число от 2 до 36).
Вывести в консоль число, записанное в новой системе счисления.
В качестве цифр, превышающих 9, использовать заглавные буквы латинского
алфавита.
Для решения можно пользоваться только циклами. Задача решается без массивов.
Использовать только тип int.

Пример ввода
-255 16
Пример вывода
-FF

code works
*/

#include <stdio.h>

#define BASE 10
#define SHIFT 55

int main() {
    int number;
    int base;
    int exponent = 1;
    
    scanf("%d %d", &number, &base);
    
    if ( number < 0 ) {
        number *= -1;
        printf("-");
    }
    
    for ( int i = number; i >= base; i /= base ) {
        exponent *= base;
    }
    
    for ( int digit; exponent != 0; exponent /= base ) {
        digit = number / exponent;
        if ( digit < BASE ) {
            printf("%d", digit);
        } else {
            printf("%c", digit+SHIFT);
        }
        if ( digit != 0 ) {
            number -= exponent * digit;
        }
    }
    printf("\n");
    
    return 0;
}
