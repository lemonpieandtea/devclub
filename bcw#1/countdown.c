/*
Задача countdown

Условие задачи
Считать с клавиатуры целое неотрицательное число.
Вывести в строку убывающий ряд чисел от заданного до нуля.

Пример ввода
7
Пример вывода
7 6 5 4 3 2 1 0

epic win
*/

#include <stdio.h>

int main() {
    int counter;
    
    scanf("%d", &counter);
    
    for ( ; counter > 0; counter-- ) {
        printf("%d ", counter);
    }
    printf("0\n");
    
    return 0;
}
