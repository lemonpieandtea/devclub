/*
Задача logic

Условие задачи
Считать с клавиатуры два целых числа.
Вывести результат логических действий И и ИЛИ.

Пример ввода
0 1
Пример вывода
0 AND 1 is 0
0 OR 1 is 1

epic win
*/

#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d AND %d is %d\n", a, b, a&&b);
    printf("%d OR %d is %d\n", a, b, a||b);
    
    return 0;
}
