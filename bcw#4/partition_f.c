/*
Задача partition()

Условие задачи
int partition(int array[], int start, int end)

В качестве опорного элемента брать среднее арифметическое между start и end с
округлением вниз.

code works
*/

#include <stdio.h>

void printArray(int array[], int end) {
    for ( int i = 0; i < end; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[end]);
}

int partition(int array[], int start, int end) {
    int pivotIndex = (start + end) / 2;
    int pivotValue = array[pivotIndex];
    int temp = array[end];
    
    array[end] = pivotValue;
    array[pivotIndex] = temp;
    
    for ( pivotIndex = start; array[pivotIndex] < pivotValue; pivotIndex++ );
    
    for ( int i = pivotIndex + 1; i < end; i++ ) {
        if ( array[i] <= pivotValue ) {
            temp = array[i];
            array[i] = array[pivotIndex];
            array[pivotIndex] = temp;
            pivotIndex += 1;
        }
    }
    
    array[end] = array[pivotIndex];
    array[pivotIndex] = pivotValue;
    
    return pivotIndex;
}

void quickSort(int array[], int start, int end) {
    int pivot;
    
    if ( end - start > 0 ) {
        pivot = partition(array, start, end);
        
        quickSort(array, start, pivot);
        quickSort(array, pivot+1, end);
    }
}

#define SIZE 10

int main() {
    int array[SIZE] = {2, 6, 8, 4, 3, 1, 9, 5, 7, 0};
    int end = SIZE - 1;
    
    printArray(array, end);
    
    quickSort(array, 0, end);
    
    printArray(array, end);
    
    return 0;
}
