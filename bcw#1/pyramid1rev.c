/*
Задача pyramid1rev

Условие задачи
Вывести числовую пирамидку на total строк. Порядок строк – обратный.
В каждой строке числа идут от единицы до номера строки через пробел.

Пример ввода
3
Пример вывода
1 2 3
1 2
1

epic win
*/

#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = total; row > 0; row-- ) {
        for ( int column = 1; column < row; column++ ) {
            printf("%d ", column);
        }
        printf("%d\n", row);
    }
    
    return 0;
}
