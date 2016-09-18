#include "arrays.h"
#include <stdio.h>

void arrayAbs(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
    }
}

void arrayCopy(int destination[], int source[], int size) {
    for ( int i = 0; i < size; i++ ) {
        destination[i] = source[i];
    }
}

void arrayExchange(int array[], int len) {
    for ( int i = 0, j = 1; j < len; i += 2, j += 2 ) {
        int temp = array[i];
        
        array[i] = array[j];
        array[j] = temp;
    }
}

void arrayIncrement(int array[], int size, int increment) {
    for ( int i = 0; i < size; i++ ) {
        array[i] += increment;
    }
}

int arrayMax(int array[], int size) {
    int max = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] > max ) {
            max = array[i];
        }
    }
    return max;
}

int arrayMin(int array[], int size) {
    int min = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] < min ) {
            min = array[i];
        }
    }
    return min;
}

void arrayPrintReversed(int array[], int size) {
    for ( int i = size - 1; i > 0; i-- ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[0]);
}

void arrayPrintReversedFile(FILE *out, int array[], int size) {
    for ( int i = size - 1; i > 0; i-- ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[0]);
}

void arrayPrint(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

void arrayPrintFile(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

void arrayReverse(int array[], int size) {
    for ( int i = 0, j = size - 1; i < j; i++, j-- ) {
        int temp = array[i];
        
        array[i] = array[j];
        array[j] = temp;
    }
}

int arrayScan(FILE *in, int array[], int limit) {
    int quantity = 0;
    
    for ( ; quantity < limit && fscanf(in, "%d", &array[quantity]) == 1; quantity++ );
    return quantity;
}

int arraySearch(int array[], int size, int needle) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] == needle ) {
            return i;
        }
    }
    return -1;
}

void arrayShiftLeft(int array[], int size) {
    int temp = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        array[i-1] = array[i];
    }
    array[size-1] = temp;
}

void arrayShiftRight(int array[], int size) {
    int i = size - 1;
    int temp = array[i];
    
    for ( int j = i - 1; i > 0; i--, j-- ) {
        array[i] = array[j];
    }
    array[0] = temp;
}

void arraySort(int array[], int size) {
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

int arraySum(int array[], int size) {
    int sum = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        sum += array[i];
    }
    return sum;
}

void arrayZeroFill(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        array[i] = 0;
    }
}

void sliceReverse(int array[], int lo, int hi) {
    for ( ; lo < hi; lo++, hi-- ) {
        int temp = array[lo];
        
        array[lo] = array[hi];
        array[hi] = temp;
    }
}

void sliceShiftLeft(int array[], int start, int end) {
    if ( start < end ) {
        int temp = array[start];
        
        for ( int i = start; i < end; i++ ) {
            array[i] = array[i+1];
        }
        array[end] = temp;
    }
}

void sliceShiftRight(int array[], int start, int end) {
    if ( start < end ) {
        int temp = array[end];
        
        for ( int i = end; i > start; i-- ) {
            array[i] = array[i-1];
        }
        array[start] = temp;
    }
}

void arrayMerge(int target[], int src1[], int len1, int src2[], int len2) {
    int size = len1 + len2;
    
    for ( int i = 0, j = 0, k = 0; i < size; i++ ) {
        if ( src1[j] <= src2[k] && j < len1 ) {
            target[i] = src1[j];
            j += 1;
        } else {
            target[i] = src2[k];
            k += 1;
        }
    }
}

void arrayShift(int array[], int size, int shift) {
    int delimiter;
    
    shift %= size;
    if ( shift < 0 ) {
        shift += size;
    }
    delimiter = size - shift;
    
    if ( delimiter > shift ) {
        int arrayBuff[shift];
        
        for ( int i = 0, j = delimiter; j < size; i++, j++ ) {
            arrayBuff[i] = array[j];
        }
        for ( int i = size - 1, j = delimiter - 1; j >= 0; i--, j-- ) {
            array[i] = array[j];
        }
        for ( int i = 0; i < shift; i++ ) {
            array[i] = arrayBuff[i];
        }
    } else {
        int arrayBuff[delimiter];
        
        for ( int i = 0; i < delimiter; i++ ) {
            arrayBuff[i] = array[i];
        }
        for ( int i = 0, j = delimiter; j < size; i++, j++ ) {
            array[i] = array[j];
        }
        for ( int i = shift, j = 0; j < delimiter; i++, j++ ) {
            array[i] = arrayBuff[j];
        }
    }
}

int arrayUnique(int array[], int size) {
    int copy = array[0];
    int newSize = 0;
    
    for ( int i = 1, unique = copy; i < size; i++ ) {
        int temp = array[i];
        
        if ( temp != unique && temp != copy ) {
            newSize += 1;
            array[newSize] = temp;
            for ( int j = i + 1; j < size; j++ ) {
                if ( array[j] == temp ) {
                    array[j] = copy;
                }
            }
        }
    }
    
    return newSize + 1;
}
