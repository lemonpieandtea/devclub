/*
Задача gcd()

Условие задачи
Написать функцию, которая находит наибольший общий делитель.
int gcd(int a, int b)

Передаваемые значения больше нуля.

epic win
*/

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}
