/*
Задача max2

Условие задачи
Считать с клавиатуры два целых числа и вывести большее из них.
Если числа равны, вывести любое.

Пример ввода
1 2
Пример вывода
2

epic win
*/

#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    if ( a > b ) {
        printf("%d\n", a);
    } else {
        printf("%d\n", b);
    }
    
    return 0;
}
