/*
Задача fileSum

Условие задачи
Считать два числа из файла task.in.
Записать их сумму в файл task.out.

Пример ввода
10 20
Пример вывода
30

epic win
*/

#include <stdio.h>

int main() {
    int a, b;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%d %d", &a, &b);
    fclose(in);
    
    fprintf(out, "%d\n", a+b);
    fclose(out);
    
    return 0;
}
