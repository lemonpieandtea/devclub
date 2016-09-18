/*
Задача nextMultiple

Условие задачи
Считать с клавиатуры два целых числа - делимое и делитель, причем делитель не равен нулю.
Вывести на экран наименьшее число, кратное делителю, не меньшее делимого.
Пример ввода
15 6
Пример вывода
18

code works
*/

#include <stdio.h>

int main() {
    int dividend, divisor;
    int rest;
    
    scanf("%d %d", &dividend, &divisor);
    
    rest = dividend % divisor;
    dividend -= rest;
    if ( divisor > 0 && rest > 0 ) {
        printf("%d\n", dividend+divisor);
    } else if ( rest > 0 ) {
        printf("%d\n", dividend-divisor);
    } else {
        printf("%d\n", dividend);
    }
    
    return 0;
}
