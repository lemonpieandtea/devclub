#include <stdio.h>
#include "increment.h"
#include "decrement.h"
#include "sum.h"
#include "diff.h"

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d\n", increment(a));
    printf("%d\n", decrement(b));
    printf("%d\n", sum(a, b));
    printf("%d\n", diff(a, b));
}
