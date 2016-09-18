#include <stdio.h>

int main() {
    int min = 1<<31;
    int max = ~min;
    
    printf("%d %d\n", max, min);
    
    return 0;
}
