/*
Задача fibonacci

Условие задачи
Вывести число Фибоначчи с заданным целым номером, по модулю не превышающим 46.
Пример ввода
8
Пример вывода
21

code works
*/

#include <stdio.h>

#define DEVISOR 2

int main() {
    int number;
    long fib = 0;
    int sign = 1;
    
    scanf("%d", &number);
    
    if ( number < 0 ) {
        number *= -1;
        if ( number % DEVISOR == 0 ) {
            sign = -1;
        }
    }
    
    for ( int last = 0, preLast = 1; number > 0; number-- ) {
        fib = last + preLast;
        preLast = last;
        last = fib;
    }
    fib *= sign;
    
    printf("%ld\n", fib);
    
    return 0;
}
