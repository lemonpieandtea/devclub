/*
Задача array

Условие задачи
Считать в массив последовательность чисел длиной 10 из файла task.in.
Записать его через пробел в файл task.out.

Пример ввода
10 20 30 40 50 60 70 80 90 100
Пример вывода
10 20 30 40 50 60 70 80 90 100

code works
*/

#include <stdio.h>

#define SIZE 10

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    int last = SIZE - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fscanf(in, "%d", &array[i]);
        fprintf(out, "%d ", array[i]);
    }
    fscanf(in, "%d", &array[last]);
    fclose(in);
    fprintf(out, "%d\n", array[last]);
    fclose(out);
    
    return 0;
}
