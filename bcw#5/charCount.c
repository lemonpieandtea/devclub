/*
Задача charCount

Условие задачи
В файле task.in задана последовательность символов.
Вывести в task.out количество вхождений латинских букв, которые встречаются в последовательности.
Большие буквы считать как маленькие.
Пример ввода
Hello!
Пример вывода
e 1
h 1
l 2
o 1

code works
*/

#include <stdio.h>

#define LATIN 26

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int buffer[LATIN];
    
    for ( int i = 0; i < LATIN; i++ ) {
        buffer[i] = 0;
    }
    
    for ( char tmp; fscanf(in, "%c", &tmp) != EOF; ) {
        if ( tmp >= 'A' && tmp <= 'Z' ) {
            int i = tmp - 'A';
            
            buffer[i] += 1;
        } else if ( tmp >= 'a' && tmp <= 'z' ) {
            int i = tmp - 'a';
            
            buffer[i] += 1;
        }
    }
    fclose(in);
    
    for ( int i = 0, j = 'a'; i < LATIN; i++, j++ ) {
        if ( buffer[i] > 0 ) {
            fprintf(out, "%c %d\n", j, buffer[i]);
        }
    }
    fclose(out);
    
    return 0;
}
