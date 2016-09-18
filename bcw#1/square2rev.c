/*
Задача square2rev

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Порядок строк обратный.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
3 4
1 2

code works
*/

#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int row = 1; row <= size; row++ ) {
        int i = size * (size - row) + 1;
        
        for ( int col = 1; col < size; col++ ) {
            printf("%d ", i);
            i += 1;
        }
        printf("%d\n", i);
    }
    
    return 0;
}
