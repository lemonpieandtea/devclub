/*
Задача divN

Условие задачи
Считать с клавиатуры целые числа min, max и положительный делитель. Вывести в столбик числа, кратные делителю, от min до max включительно.

Пример ввода
0 8 2
Пример вывода
0
2
4
6
8

code works
*/

#include <stdio.h>

int main() {
    int min, max;
    int divisor;
    int index;
    
    scanf("%d %d %d", &min, &max, &divisor);
    
    index = min - min % divisor;
    if ( min > 0 && min % divisor != 0 ) {
        index += divisor;
    }
    
    for ( ; index <= max; index += divisor ) {
        printf("%d\n", index);
    }
    
    return 0;
}
