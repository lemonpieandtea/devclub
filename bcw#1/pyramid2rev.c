/*
Задача pyramid2rev

Условие задачи
Вывести числовую пирамидку на total строк. Порядок строк – обратный.
В первой строке стоит число 1. В последующих строках стоят увеличивающиеся числа
через пробел.

Пример ввода
3
Пример вывода
4 5 6
2 3
1

code works
*/

#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = 1; row <= total; row++ ) {
        int i = 1;
        int limit = total - row;
        
        for ( int j = total - row; j > 0; j-- ) {
            i += j;
        }
        
        for ( int col = 1; col <= limit; col++ ) {
            printf("%d ", i);
            i += 1;
        }
        printf("%d\n", i);
    }
    
    return 0;
}
