/*
Задача strReverse

Условие задачи
В файле task.in дана строка длиной не более 100 символов.
Прочитать строку в память и произвести ее реверс.
Результат вывести в task.out.

Пример ввода
hello
Пример вывода
olleh

code work
*/

#include <stdio.h>

#define LEN 100

int strLen(char str[]) {
    int len = 0;
    
    for ( ; str[len] != 0; len++ );
    return len;
}

void strReverse(char array[], int size) {
    for ( int i = 0, j = size - 1; i < j; i++, j-- ) {
        int temp = array[i];
        
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[LEN+1];
    
    fscanf(in, "%100s", str);
    fclose(in);
    
    strReverse(str, strLen(str));
    
    fprintf(out, "%s\n", str);
    fclose(out);
    
    return 0;
}
