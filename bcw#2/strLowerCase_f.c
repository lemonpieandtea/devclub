/*
Задача strLowerCase()

code works
*/

void strLowerCase(char str[]) {
    for ( int i = 0, temp = str[0]; temp != 0; i++ ) {
        temp = str[i];
        if ( temp >= 'A' && temp <= 'Z' ) {
            str[i] += 'a' - 'A';
        }
    }
}
