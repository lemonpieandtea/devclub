/*
Задача prevMultiple

Условие задачи
Считать с клавиатуры два целых числа - делимое и делитель, причем делитель не равен нулю.
Вывести на экран наибольшее число, кратное делителю, не превышающее делимое.

Пример ввода
15 6
Пример вывода
12

code works
*/

#include <stdio.h>

int main() {
    int dividend, divisor;
    int rest;
    
    scanf("%d %d", &dividend, &divisor);
    
    rest = dividend - dividend % divisor;
    if ( dividend > 0 || dividend % divisor == 0 ) {
        printf("%d\n", rest);
    } else if ( divisor > 0 && dividend % divisor != 0 ) {
        printf("%d\n", rest-divisor);
    } else if ( dividend % divisor != 0 ) {
        printf("%d\n", rest+divisor);
    }
    
    return 0;
}
