/*
Задача abs

Условие задачи
В файле task.in дана длина последовательности чисел (число больше нуля) и сама
последовательность.
Прочитать последовательность в массив.
Найти все отрицательные числа и заменить их положительными, равными по модулю.
Результирующий массив вывести в task.out.

Пример ввода
10
10 -20 30 40 -50 -60 70 80 90 -100
Пример вывода
10 20 30 40 50 60 70 80 90 100

code works
*/

#include <stdio.h>

int getSize(FILE *in) {
    int size;
    
    fscanf(in, "%d", &size);
    return size;
}

void arrayScan(FILE *in, int array[], int limit) {
    for ( int quantity = 0; quantity < limit && fscanf(in, "%d", &array[quantity]) == 1; quantity++ );
}

void arrayAbs(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
    }
}

void arrayPrint(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = getSize(in);
    int array[size];
    
    arrayScan(in, array, size);
    fclose(in);
    
    arrayAbs(array, size);
    
    arrayPrint(out, array, size);
    fclose(out);
    
    return 0;
}
