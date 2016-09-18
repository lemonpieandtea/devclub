/*
Задача matrixDecrement

Условие задачи
void matrixDecrement(int matrix[SIZE][SIZE], int decrement[SIZE][SIZE],
int size)

epic win
*/

void matrixDecrement(int matrix[SIZE][SIZE], int increment[SIZE][SIZE], int size) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            matrix[i][j] -= increment[i][j];
        }
    }
}
