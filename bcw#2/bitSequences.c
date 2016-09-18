/*
Задача bitSequences

Условие задачи
Вывести количество различных битовых последовательностей заданной длины
(не более 32), не содержащих двух единиц подряд.
Пример ввода
1
Пример вывода
2

code works - fibonacci?
*/

#include <stdio.h>

int fibonacci(int n) {
    if ( n == 0 ) {
        return 0;
    }
    if ( n == 1 || n == -1 ) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int length;
    
    scanf("%d", &length);
    
    printf("%d\n", fibonacci(length+2));
    
    return 0;
}
