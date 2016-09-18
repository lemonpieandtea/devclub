/*
Задача strEqual

Условие задачи
В файле task.in заданы две строки длиной не более 100 символов каждая.
Если строки равны, вывести в task.out слово "yes" - иначе вывести "no".

Пример ввода
hello
hello
Пример вывода
yes

code works
*/

#include <stdio.h>

#define LENGTH 100

int strEqual(char str1[], char str2[]) {
    for ( int i = 0; str1[i] == str2[i]; i++ ) {
        if ( str1[i] == 0 ) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str1[LENGTH+1];
    char str2[LENGTH+1];
    
    fscanf(in, "%100s %100s", str1, str2);
    fclose(in);
    
    if ( strEqual(str1, str2) ) {
        fprintf(out, "yes\n");
    } else {
        fprintf(out, "no\n");
    }
    fclose(out);
    
    return 0;
}
