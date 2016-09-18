#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int row = 1; row <= size; row++ ) {
        for ( int column = 1; column < row; column++ ) {
            printf("%d ", column);
        }
        for ( int column = row; column < size; column++ ) {
            printf("%d ", row);
        }
        printf("%d\n", row);
    }
    
    return 0;
}
