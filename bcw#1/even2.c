/*
Задача even2

Условие задачи
Считать с клавиатуры два целых числа.
Вывести в строку все чётные числа в промежутке от первого до второго
включительно.
В указанном промежутке гарантировано наличие хотя бы одного числа, подлежащего
выводу.

Пример ввода
7 15
Пример вывода
8 10 12 14

code works
*/

#include <stdio.h>

#define DIVISOR 2

int main() {
    int start, end;
    
    scanf("%d %d", &start, &end);
    
    if ( start % DIVISOR != 0 ) {
        start += 1;
    }
    end -= end % DIVISOR;
    
    for ( int i = start; i < end; i += DIVISOR ) {
        printf("%d ", i);
    }
    printf("%d\n", end);
    
    return 0;
}
