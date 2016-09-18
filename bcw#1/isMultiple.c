/*
Задача isMultiple

Условие задачи
Считать с клавиатуры два целых числа, причем второе из них не равно нулю. 
Если первое кратно второму, вывести на экран yes, иначе вывести no.

Пример ввода
25 5
Пример вывода
yes

epic win
*/

#include <stdio.h>

int main() {
    int dividend, divisor;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( dividend % divisor == 0 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
