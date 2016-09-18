/*
Задача strUpperCase()

Условие задачи
void strUpperCase(char str[])

code works
*/

void strUpperCase(char str[]) {
    for ( int i = 0, temp = str[0]; temp != 0; i++ ) {
        temp = str[i];
        if ( temp >= 'a' && temp <= 'z' ) {
            str[i] -= 'a' - 'A';
        }
    }
}
