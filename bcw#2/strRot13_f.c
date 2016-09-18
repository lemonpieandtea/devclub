/*
Задача strRot13()

Условие задачи
Написать функцию:
void strRot13(char str[])

Зашифровать строку по алгоритму ROT13

code works
*/

void strRot13(char str[]) {
    for ( int i = 0, temp = str[0]; temp != 0; i++ ) {
        temp = str[i];
        if ( temp >= 'A' && temp <= 'Z' ) {
            if ( temp < 'N' ) {
                str[i] = temp + 13;
            } else {
                str[i] = temp - 13;
            }
        } else if ( temp >= 'a' && temp <= 'z' ) {
            if ( temp < 'n' ) {
                str[i] = temp + 13;
            } else {
                str[i] = temp - 13;
            }
        }
    }
}
