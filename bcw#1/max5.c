/*
Задача max5

Условие задачи
Считать с клавиатуры пять целых чисел и вывести большее из них.
В случае равенства выводить любое.
Данная задача решается без массивов, циклов и функций.

Пример ввода
1 2 3 4 5
Пример вывода
5

epic win
*/

#include <stdio.h>

int main() {
    int a, b, c, d, e;
    int max;
    
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    max = a;
    if ( max < b ) {
        max = b;
    }
    if ( max < c ) {
        max = c;
    }
    if ( max < d ) {
        max = d;
    }
    if ( max < e ) {
        max = e;
    }
    
    printf("%d\n", max);
    
    return 0;
}
