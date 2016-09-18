/*
Задача matrixRotate270

Условие задачи
void matrixRotate270(int target[SIZE][SIZE], int source[SIZE][SIZE], int size);

Поворот матрицы на 270 градусов по часовой стрелке.

code works
*/

#include <stdio.h>

#define SIZE 3

void matrixRotate270(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int sourceRow = 0; sourceRow < size; sourceRow++ ) {
        for ( int sourceCol = 0, targetRow = size - 1; sourceCol < size; sourceCol++, targetRow-- ) {
            target[sourceRow][targetRow] = source[sourceCol][sourceRow];
        }
    }
}

void matrixPrint(int matrix[SIZE][SIZE], int size) {
    int last = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < last; col++ ) {
            printf("%d ", matrix[col][row]);
        }
        printf("%d\n", matrix[last][row]);
    }
}

int main() {
    int matrixA[SIZE][SIZE] = {{1,4,7},{2,5,8},{3,6,9}};
    int matrixB[SIZE][SIZE];
    
    matrixPrint(matrixA, SIZE);
    
    matrixRotate270(matrixB, matrixA, SIZE);
    
    printf("\n");
    matrixPrint(matrixB, SIZE);
    
    return 0;
}
