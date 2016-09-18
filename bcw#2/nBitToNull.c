#include <stdio.h>

int main() {
    int number;
    int bit;
    
    scanf("%d %d", &number, &bit);
    
    number &= ~(1<<bit);
    
    printf("%d\n", number);
    
    return 0;
}
