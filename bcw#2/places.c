/*
Задача places

Условие задачи
Считать с клавиатуры целое число.
Вывести на экран количество знакомест, нужных для вывода этого числа.

Пример ввода
123
Пример вывода
3

code works
*/

#include <stdio.h>

#define BASE 10

int main() {
    int number;
    int places = 0;
    
    scanf("%d", &number);
    
    if ( number < 1 ) {
        places += 1;
    }
    
    for ( ; number != 0; number /= BASE ) {
        places += 1;
    }
    
    printf("%d\n", places);
    
    return 0;
}
