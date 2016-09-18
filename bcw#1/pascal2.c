/*
Задача pascal2

Условие задачи
Вариация задачи pascal с расширенным диапазоном входных данных.

code works
*/

#include <stdio.h>

int value(int n, int k) {
    if ( k == 0 || n == k ) {
        return 1;
    }
    return value(n-1, k-1) + value(n-1, k);
}

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = 0; row < total; row++ ) {
        for ( int col = 0; col < row; col++ ) {
            printf("%d ", value(row, col));
        }
        printf("1\n");
    }
    
    return 0;
}
