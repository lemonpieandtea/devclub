#include <stdio.h>
#include "arrays.h"

#define LIMIT 30

int main(int argc, char const *argv[]) {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[LIMIT];
    int size;
    
    size = arrayScan(in, array, LIMIT);
    fclose(in);
    
    arrayPrintFile(out, array, size);
    
    arrayReverse(array, size);
    arrayPrintFile(out, array, size);
    
    sliceShiftLeft(array, 1, size-2);
    arrayPrintFile(out, array, size);
    
    arrayShift(array, size, size/2);
    arrayPrintFile(out, array, size);
    fclose(out);
    
    return 0;
}
