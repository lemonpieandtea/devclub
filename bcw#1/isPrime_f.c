/*
Задача isPrime()

Условие задачи
Написать функцию:
int isPrime(int n)

Проверить, является ли данное число простым.

code works
*/

int isPrime(int n) {
    int half = n / 2;
    
    if ( n < 2 ) {
        return 0;
    }
    
    for ( int i = 2; i <= half; i++ ) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    
    return 1;
}
