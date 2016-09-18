/*
Задача square2

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
1 2
3 4

epic win
*/

#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int row = 1, counter = 1; row <= size; row++ ) {
        for ( int col = 1; col < size; col++ ) {
            printf("%d ", counter);
            counter += 1;
        }
        printf("%d\n", counter);
        counter += 1;
    }
    
    return 0;
}
