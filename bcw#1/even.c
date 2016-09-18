/*
Задача even

Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все чётные числа от нуля до указанного числа включительно.

Пример ввода
7
Пример вывода
0 2 4 6

epic win
*/

#include <stdio.h>

#define DIVISOR 2

int main() {
    int limit;
    
    scanf("%d", &limit);
    
    limit -= limit % DIVISOR;
    
    for ( int i = 0; i < limit; i += DIVISOR ) {
        printf("%d ", i);
    }
    printf("%d\n", limit);
    
    return 0;
}
