/*
Задача maxN

Условие задачи
Считать с клавиатуры целое положительное число - количество чисел в
последовательности.
Затем считать с клавиатуры заданное количество чисел и вывести наибольшее из
них.

Пример ввода
5
1 2 3 4 5
Пример вывода
5

code works
*/

#include <stdio.h>

int main() {
    unsigned int quantity;
    int max;
    
    scanf("%d %d", &quantity, &max);
    
    for ( int number; quantity > 1; quantity-- ) {
        scanf("%d", &number);
        if ( number > max ) {
            max = number;
        }
    }
    
    printf("%d\n", max);
    
    return 0;
}
