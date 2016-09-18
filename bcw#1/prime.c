/*
Задача prime

Условие задачи
Вывести N-ное по счёту простое число (см. Википедию).
N считать с клавиатуры.
Оптимизировать работу программы, насколько это возможно.
В случае неопределенности ответа вывести -1.

Пример ввода
3
Пример вывода
5

code works
*/

#include <stdio.h>

int isPrime(int n) {
    int modulo;
    int half = n / 2;
    
    if ( n < 2 ) {
        return 0;
    }
    
    for ( int i = 2; i <= half; i++ ) {
        modulo = n % i;
        if ( modulo == 0 ) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int number;
    int index = 0;
    
    scanf("%d", &number);
    
    for ( int counter = 1; counter <= number; index += 1 ) {
        if ( isPrime(index) ) {
            counter += 1;
        }
    }
    
    printf("%d\n", index-1);
    
    return 0;
}
