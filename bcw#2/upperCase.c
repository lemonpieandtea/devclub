/*
Задача upperCase

Условие задачи
В файле task.in дана последовательность символов.
Перевести все буквы в верхний регистр и вывести результирующую
последовательность в файл task.out

Пример ввода
abcd
Пример вывода
ABCD

code works
*/

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    for ( char tmp; fscanf(in, "%c", &tmp) != EOF; ) {
        if ( tmp >= 'a' && tmp <= 'z' ) {
            tmp -= 'a' - 'A';
        }
        fprintf(out, "%c", tmp);
    }
    fclose(in);
    fprintf(out, "\n");
    fclose(out);
    
    return 0;
}
