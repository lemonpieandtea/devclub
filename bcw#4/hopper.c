/*
Задача hopper

Условие задачи
Кузнечик начинает свой путь на клетке 0 и может прыгать на расстояние от 1 до
<maxJump> клеток. Прыжки возможны только на целое число клеток вперед.
Посчитать кол-во способов <ways>, которыми кузнечик может попасть на клетку
<cell>.

В файле task.in заданы целые числа:
<maxJump> <cell>

Вывести ways в task.out.

Ограничения:
1 <= maxJump <= 100
1 <= cell <= 100
1 <= ways <= 999 999 999 999 999 999

Пример ввода
2 3
Пример вывода
3
Пояснение
Кузнечик может прыгать на 1 или 2 клетки.
На 1-ю клетку он может попасть одним способом: 0->1.
На 2-ю клетку он может попасть двумя способами: 0->2, 0->1->2.
На 3-ю клетку можно попасть тремя способами: 0->1->2->3, 0->1->3, 0->2->3.

code works
*/

#include <stdio.h>

#define SIZE 100

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int maxJump;
    int cell;
    unsigned long long result[SIZE];
    
    fscanf(in, "%d %d", &maxJump, &cell);
    fclose(in);
    
    result[0] = 1;
    for ( int i = 0, j = 1; j <= cell; i++, j++ ) {
        if ( i < maxJump ) {
            result[j] = 1 << i;
        } else {
            result[j] = 0;
            
            for ( int k = i - maxJump + 1; k < j; k++ ) {
                result[j] += result[k];
            }
        }
    }
    
    fprintf(out, "%llu\n", result[cell]);
    fclose(out);
    
    return 0;
}
