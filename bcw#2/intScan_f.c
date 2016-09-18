/*
Задача intScan()

Условие задачи
int intScan(FILE *in)

Считать число из файла и вернуть его.

epic win
*/

int intScan(FILE *in) {
    int number;
    
    fscanf(in, "%d", &number);
    return number;
}
