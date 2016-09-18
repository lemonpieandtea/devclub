/*
Задача mergeSort

Условие задачи
В файле task.in дано число len и массив размером len элементов.
Отсортировать элементы в порядке неубывания.
Использовать алгоритм mergeSort.
Результат записать в task.out
Допустимо использование рекурсии.


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

void mergeSort(int array[], int lo, int hi) {
    int mid = (lo + hi) / 2;
    
    if ( hi - lo <= 1 ) {
        return;
    }
    
    mergeSort(array, lo, mid);
    mergeSort(array, mid, hi);
    
    merge(array, lo, mid, hi);
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
    
    mergeSort(array, 0, len);
    
    for ( int i = 0; i < size; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[size]);
    fclose(out);
    
    return 0;
}
