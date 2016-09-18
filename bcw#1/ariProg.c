/*
Задача ariProg

Условие задачи
Считать с клавиатуры три целых числа - первый член, шаг и количество членов
арифметической прогрессии. Вывести в строку через пробел члены заданной
прогрессии.
Задаваемое количество больше нуля.

Пример ввода
12 2 4
Пример вывода
12 14 16 18

code works
*/

#include <stdio.h>

int main() {
    int i;
    int step;
    int quantity;
    
    scanf("%d %d %d", &i, &step, &quantity);
    
    for ( ; quantity > 1; quantity-- ) {
        printf("%d ", i);
        i += step;
    }
    printf("%d\n", i);
    
    return 0;
}
