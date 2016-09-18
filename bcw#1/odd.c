/*
Задача odd

Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все нечётные числа от нуля до указанного числа включительно.

Пример ввода
9
Пример вывода
1 3 5 7 9

code works
*/

#include <stdio.h>

#define DIVISOR 2

int main() {
    int limit;
    
    scanf("%d", &limit);
    
    limit += limit % DIVISOR - 1;
    
    for ( int i = 1; i < limit; i += DIVISOR ) {
        printf("%d ", i);
    }
    printf("%d\n", limit);
    
    return 0;
}
