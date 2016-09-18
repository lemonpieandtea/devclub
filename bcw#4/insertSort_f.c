/*
Задача insertSort()

Условие задачи
void insertSort(int array[], int len)

code works
*/

#include <stdio.h>

void insertSort(int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        int key = array[i];
        int j = i - 1;
        
        for ( int k = i; j >= 0 && array[j] > key; j--, k-- ) {
            array[k] = array[j];
        }
        array[j+1] = key;
    }
}

#define SIZE 10

int main() {
    int length = SIZE - 1;
    int array[SIZE] = {0, 4, 7, 8, 5, 2, 3, 6, 9, 1};
    
    for ( int i = 0; i < length; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[length]);
    
    insertSort(array, SIZE);
    
    for ( int i = 0; i < length; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[length]);
    
    return 0;
}
