/*
Задача average2()

Условие задачи
int average(int a, int b)
Вернуть среднее арифметическое двух целых чисел. Использовать только тип int.
Если среднее значение не является целым, то округлить его к ближайшему целому в
сторону нуля.

code works
*/

#include <stdio.h>

int average(int a, int b) {
    int result = a / 2 + b / 2 + (a % 2 + b % 2) / 2;
    
    if ( a > 0 && a % 2 != 0 && b < 0 && b % 2 == 0 && result < 0 ) {
        result += 1;
    } else if ( a < 0 && a % 2 == 0 && b > 0 && b % 2 != 0 && result < 0 ) {
        result += 1;
    } else if ( a > 0 && a % 2 == 0 && b < 0 && b % 2 != 0 && result > 0 ) {
        result -= 1;
    } else if ( a < 0 && a % 2 != 0 && b > 0 && b % 2 == 0 && result > 0 ) {
        result -= 1;
    }
    
    return result;
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d\n", average(a, b));
    
    return 0;
}
