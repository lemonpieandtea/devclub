/*
Задача merge()

Условие задачи
void merge(int array[], int lo, int mid, int hi)
Слияние двух сортированных подмассивов в один отсортированный подмассив.
Первый подмассив от lo до mid не включая mid
Второй подмассив от mid до hi не включая hi

code works
*/

#include <stdio.h>

void merge(int array[], int lo, int mid, int hi) {
    int size = hi - lo;
    int buffer[size];
    
    for ( int i = 0, j = lo, k = mid; i < size; i++ ) {
        if ( j < mid && k < hi ) {
            if ( array[j] < array[k] ) {
                buffer[i] = array[j];
                j += 1;
            } else {
                buffer[i] = array[k];
                k += 1;
            }
        } else if ( j == mid ) {
            buffer[i] = array[k];
            k += 1;
        } else {
            buffer[i] = array[j];
            j += 1;
        }
    }
    
    for ( int i = lo, j = 0; j < size; i++, j++ ) {
        array[i] = buffer[j];
    }
}

#define SIZE 10

int main() {
    int length = SIZE - 1;
    int array[SIZE] = {10, 11, 12, 13, 14, 5, 6, 7, 8, 9};
    
    for ( int i = 0; i < length; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[length]);
    
    merge(array, 2, SIZE/2, SIZE-2);
    
    for ( int i = 0; i < length; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[length]);
    
    return 0;
}
