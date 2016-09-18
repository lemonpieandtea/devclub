/*
Задача pyramid1

Условие задачи
Вывести числовую пирамидку на total строк.
В каждой строке числа идут от единицы до номера строки через пробел.

Пример ввода
3
Пример вывода
1
1 2
1 2 3

epic win
*/

#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = 1; row <= total; row++ ) {
        for ( int column = 1; column < row; column++ ) {
            printf("%d ", column);
        }
        printf("%d\n", row);
    }
    
    return 0;
}
