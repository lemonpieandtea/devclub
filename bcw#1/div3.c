/*
Задача div3

Условие задачи
Считать min, max. Вывести в столбик кратные тройке числа от min до max включительно.

Пример ввода
0 9
Пример вывода
0
3
6
9

code works
*/

#include <stdio.h>

#define DIVISOR 3

int main() {
    int min, max;
    int i;
    
    scanf("%d %d", &min, &max);
    
    i = min - min % DIVISOR;
    if ( min > 0 && min % DIVISOR != 0 ) {
        i += DIVISOR;
    }
    
    for ( ; i <= max; i += DIVISOR ) {
        printf("%d\n", i);
    }
    
    return 0;
}
