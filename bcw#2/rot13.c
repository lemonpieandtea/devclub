/*
Задача rot13

Условие задачи
Считать из файла task.in в память строку длиной не более 100 символов.
Зашифровать её по алгоритму ROT13.
Результат вывести в task.out.

Пример ввода
balk
Пример вывода
onyx

code works
*/

#include <stdio.h>

#define LEN 100
#define SHIFT 13

void strRot13(char str[]) {
    for ( int i = 0, temp = str[0]; temp != 0; i++ ) {
        temp = str[i];
        if ( temp >= 'A' && temp <= 'Z' ) {
            if ( temp < 'N' ) {
                str[i] += SHIFT;
            } else {
                str[i] -= SHIFT;
            }
        } else if ( temp >= 'a' && temp <= 'z' ) {
            if ( temp < 'n' ) {
                str[i] += SHIFT;
            } else {
                str[i] -= SHIFT;
            }
        }
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[LEN+1];
    
    fscanf(in, "%100s", str);
    fclose(in);
    
    strRot13(str);
    
    fprintf(out, "%s\n", str);
    fclose(out);
    
    return 0;
}
