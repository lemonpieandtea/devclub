/*
Задача binarySequence

Условие задачи
В файле task.in дана последовательность символов – нулей и единиц.
Вывести в task.out минимально необходимое число обменов пар значений для
упорядочивания последовательности по неубыванию.

Пример ввода
1101
Пример вывода
1
Пояснение
Необходимо обменять ноль с первой единицей.


*/

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int zeros = 0;
    int replaces = 0;
    
    for ( char temp; fscanf(in, "%c", &temp) != EOF; ) {
        if ( temp == '0' ) {
            zeros += 1;
        }
    }
    
    rewind(in);
    
    for ( char temp; zeros > 0; zeros-- ) {
        fscanf(in, "%c", &temp);
        
        if ( temp == '1' ) {
            replaces += 1;
        }
    }
    fclose(in);
    
    fprintf(out, "%d\n", replaces);
    fclose(out);
    
    return 0;
}
