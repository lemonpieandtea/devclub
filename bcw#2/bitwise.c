/*
Задача bitwise

Условие задачи
Считать из task.in два числа.
Записать в task.out результат выполнения различных побитовых операций.

Пример ввода
1 1
Пример вывода
1&1=1
1|1=1
1^1=0
1<<1=2
1>>1=0

epic win
*/

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int a, b;
    
    fscanf(in, "%d %d", &a, &b);
    fclose(in);
    
    fprintf(out, "%d&%d=%d\n", a, b, a&b);
    fprintf(out, "%d|%d=%d\n", a, b, a|b);
    fprintf(out, "%d^%d=%d\n", a, b, a^b);
    fprintf(out, "%d<<%d=%d\n", a, b, a<<b);
    fprintf(out, "%d>>%d=%d\n", a, b, a>>b);
    fclose(out);
    
    return 0;
}
