/*
Задача div2

Условие задачи
Считать min, max. Вывести в столбик чётные числа от min до max включительно.

Пример ввода
0 8
Пример вывода
0
2
4
6
8

epic win
*/

#include <stdio.h>

#define DIVISOR 2

int main() {
    int min, max;
    
    scanf("%d %d", &min, &max);
    
    if ( min % DIVISOR != 0 ) {
        min += 1;
    }
    
    for ( int i = min; i <= max; i += DIVISOR ) {
        printf("%d\n", i);
    }
    
    return 0;
}
