#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000000

void arrayFill(int array[], long long size) {
    for ( long long i = 0; i < size; i++ ) {
        array[i] = i;
    }
}

void arrayPrint(int array[], long long size) {
    int last = size - 1;
    
    for ( long long i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

int main() {
    int *array;
    int x;
    
    array = malloc(SIZE*sizeof(int));
    
    arrayFill(array, SIZE);
    
    printf("%p\n", array);
    //arrayPrint(array, SIZE);
    
    scanf("%d", &x);
    
    free(array);
    
    return 0;
}
