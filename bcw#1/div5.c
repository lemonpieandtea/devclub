/*
Задача div5

Условие задачи
Считать min, max. Вывести в столбик кратные пяти числа от min до max
включительно.

Пример ввода
0 15
Пример вывода
0
5
10
15

code works
*/

#include <stdio.h>

#define DIVISOR 5

int main() {
    int min, max;
    int actual;
    
    scanf("%d %d", &min, &max);
    
    actual = min - min % DIVISOR;
    if ( min > 0 && min % DIVISOR != 0 ) {
        actual += DIVISOR;
    }
    
    for ( ; actual <= max; actual += DIVISOR ) {
        printf("%d\n", actual);
    }
    
    return 0;
}
