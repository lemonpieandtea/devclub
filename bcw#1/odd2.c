/*
Задача odd2

Условие задачи
Считать с клавиатуры два целых числа, причём второе число не меньше первого.
Вывести в строку все нечётные числа в промежутке от первого до второго включительно.
В указанном промежутке гарантируется на вывод хотя бы одно число.

Пример ввода
7 15
Пример вывода
7 9 11 13 15

code works
*/

#include <stdio.h>

#define DIVISOR 2

int main() {
    int start, end;
    
    scanf("%d %d", &start, &end);
    
    if ( start % DIVISOR == 0 ) {
        start += 1;
    }
    if ( end % DIVISOR == 0 ) {
        end -= 1;
    }
    
    for ( int i = start; i < end; i += DIVISOR ) {
        printf("%d ", i);
    }
    printf("%d\n", end);
    
    return 0;
}
