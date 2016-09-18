/*
Задача factorial()

Условие задачи
int factorial(int n)

Использовать рекурсию.
В случае неопределенности возвращать -1.

epeic win
*/

int factorial(int n) {
    if ( n < 0 ) {
        return -1;
    }
    if ( n <= 1 ) {
        return 1;
    }
    return n * factorial(n-1);
}
