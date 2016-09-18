/*
Задача minN

Условие задачи
Считать с клавиатуры целое положительное число - количество чисел в
последовательности.
Затем считать с клавиатуры заданное количество чисел и вывести наименьшее из
них.
Данная задача решается без массивов.

Пример ввода
5
1 2 3 4 5
Пример вывода
1

code works
*/

#include <stdio.h>

int main() {
    unsigned int quantity;
    int min;
    
    scanf("%d %d", &quantity, &min);
    
    for ( int number; quantity > 1; quantity-- ) {
        scanf("%d", &number);
        if ( number < min ) {
            min = number;
        }
    }
    
    printf("%d\n", min);
    
    return 0;
}
