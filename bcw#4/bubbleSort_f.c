/*
Задача bubbleSort()

Условие задачи
void bubbleSort(int array[], int size)

code works
*/

#include <stdio.h>

void bubbleSort(int array[], int size) {
    int isSort = 0;
    
    for ( int i = size; i > 0 && isSort == 0; i-- ) {
        isSort = 1;
        
        for ( int j = 0, k = 1; k < i; k++, j++ ) {
            if ( array[j] > array[k] ) {
                int temp = array[j];
                
                array[j] = array[k];
                array[k] = temp;
                isSort = 0;
            }
        }
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
    
    bubbleSort(array, SIZE);
    
    for ( int i = 0; i < length; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[length]);
    
    return 0;
}
