/*
Задача selectSort()

Условие задачи
void selectSort(int array[], int size)

code works
*/

#include <stdio.h>

void selectSort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int temp;
        int min = i;
        
        for ( int j = i; j < size; j++ ) {
            if ( array[j] < array[min] ) {
                min = j;
            }
        }
        
        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
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
    
    selectSort(array, SIZE);
    
    for ( int i = 0; i < length; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[length]);
    
    return 0;
}
