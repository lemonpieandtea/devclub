/*
Задача quickSort

Условие задачи
В файле task.in дано число len и массив размером len элементов.
Отсортировать элементы в порядке неубывания.
Использовать алгоритм quickSort.
Результат записать в task.out

code works
*/

#include <stdio.h>

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

int getLength(FILE *in) {
    int len;
    
    fscanf(in, "%d", &len);
    
    return len;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = getLength(in);
    int size = len - 1;
    int array[size];
    
    for ( int i = 0; i < len; i++ ) {
        fscanf(in, "%d", &array[i]);
    }
    fclose(in);
    
    quickSort(array, 0, size);
    
    for ( int i = 0; i < size; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[size]);
    fclose(out);
    
    return 0;
}
